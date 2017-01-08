/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fromttf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 08:49:30 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/05 18:45:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "mgl/strings.h"
#define STB_TRUETYPE_IMPLEMENTATION
#include "hlib/stb_truetype.h"

#define MGL_FILEREAD_BUFSIZE 0x10000

static int		load_ttf(const char *ttfpath, stbtt_fontinfo *font,
				unsigned char *fbuf)
{
	struct stat		ttfstat;
	int				fd;
	size_t			fsize = MGL_FILEREAD_BUFSIZE;

	if ((fd = open(ttfpath, O_RDONLY)) < 0)
		return 0;
	if (!fstat(fd, &ttfstat))
	{
		fsize = ttfstat.st_size;
		fbuf = malloc(fsize);
		read(fd, fbuf, fsize);
		stbtt_InitFont(font, fbuf, stbtt_GetFontOffsetForIndex(fbuf,0));
	}
	close(fd);
	return ((fbuf) ? 1 : 0);
}

static mglca	clean_end_ttftoca(mglca ca, void *fbuf, void *tex)
{
	void		*tmpb;

	if (fbuf)
		free(fbuf);
	if (tex)
		free(tex);
	if (!ca.texture)
		ca.length = 0;
	if (!ca.length)
	{
		ca.glyphs = NULL;
		if (ca.texoffset)
			free(ca.texoffset);
		ca.metrics = NULL;
		ca.texoffset = NULL;
	}
	if (ca.glyphs)
	{
		tmpb = malloc(sizeof(int) * ca.length);
		memcpy(tmpb, ca.glyphs, sizeof(int) * ca.length);
		ca.glyphs = (unsigned int *)tmpb;
	}
	return (ca);
}

static void		fill_tex(stbtt_fontinfo *font, unsigned char *tex, int *chartab,
					size_t len, int bw, int bh, float fs, unsigned int tw)
{
	size_t			i, x, y;
	int				g, x0,y0,x1,y1, gw, gh;

	printf("tw : %u\n", tw);
	bzero(tex, tw * tw);
	x = 0;
	y = 0;
	for (i = 0; i < len; i++)
	{
		g = stbtt_FindGlyphIndex(font, (chartab) ? chartab[i] : (int)i);
		stbtt_GetGlyphBitmapBox(font, g, fs, fs, &x0,&y0,&x1,&y1);
		gw = x1-x0;
		gh = y1-y0;
		if ((x + bw) > tw)
		{
			x = 0;
			y += bh;
		}
		stbtt_MakeGlyphBitmap(font, tex + x + (y * tw), gw, gh, tw, fs, fs, g);
		x += bw;
	}
}

mglca			mgl_ttf_to_charatlas(const char *ttfpath, int *chartab,
					size_t len)
{
	mglca			ca;
	size_t			i, x, y;
	int				g;
	// GL texture vars
	unsigned char	*tex = NULL;
	GLuint			texid;
	unsigned int	tw;
	size_t			texsize;
	// Font vars
	unsigned char	*fbuf = NULL;
	stbtt_fontinfo	font;
	float			fs;
	// Char metrics vars
	int				x0, y0, x1, y1, gx0, gy0, gx1, gy1, gw, gh, bw, bh;

	if (!chartab)
		len = 128;
	ca.glyphs = NULL;
	ca.metrics = NULL;
	ca.texoffset = NULL;
	ca.length = 0;
	ca.texture = 0;
	ca.box = (v2i){0,0};
	ca.linesize = 0.0f;
	if (!len)
		return (ca);
	ca.glyphs = (unsigned int *)chartab;

	// Load the font
	load_ttf(ttfpath, &font, fbuf);
	puts("coucou ttf");
	// Get font size ratio for the maximum size of render :
	//*	fixed at 102 pixels for now
	//*	(because 1024 / 10 so ~ 100 char fill a 1k texture)
	fs = stbtt_ScaleForPixelHeight(&font, 94);
	// Get Vertical font metrics
	stbtt_GetFontVMetrics(&font, &x0, &x1, &y0);
	ca.linesize = (x0 + x1 + y0) * fs;
	// Get max char bounding box
	stbtt_GetFontBoundingBox(&font, &x0, &y0, &x1, &y1);
	bw = (int)round((x1 - x0) * fs) + 1;
	bh = (int)round((y1 - y0) * fs) + 1;
	ca.box = (v2i){bw - 1, bh - 1};
	// Calculate texture size
	if (bw < bh)
		texsize = (size_t)ceilf(sqrtf(
			ceilf(len * ((float)bw / (float)bh)))) * bh;
	else
		texsize = (size_t)ceilf(sqrtf(
			ceilf(len * ((float)bh / (float)bw)))) * bw;
	printf("tex size %zi\nbw %i\nbh %i\n", texsize, bw, bh);
	if (texsize > 8192)
		return (clean_end_ttftoca(ca, fbuf, tex));
	tw = 256;
	while (tw < texsize)
		tw *= 2;
	printf("tw %zi\n", tw);
	texsize = tw * tw;
	if (!(tex = malloc(texsize)))
		return (clean_end_ttftoca(ca, fbuf, tex));
	bzero(tex, texsize);
	if (!(ca.texoffset = malloc(sizeof(v4f) * 2 * len)))
		return (clean_end_ttftoca(ca, fbuf, tex));
	ca.metrics = ca.texoffset + len;
	bw -= 1;
	bh -= 1;
	x = 0;
	y = 0;
	for (i = 0; i < len; i++)
	{
		g = stbtt_FindGlyphIndex(&font, (chartab) ? chartab[i] : ((int)i + 31));
		stbtt_GetGlyphBitmapBox(&font, g, fs, fs, &gx0, &gy0, &gx1, &gy1);
		gw = gx1-gx0;
		gh = gy1-gy0;
		ca.texoffset[i] = (v4f){
			(float)x / (float)tw,
			(float)y / (float)tw,
			(float)(x + gw) / (float)tw,
			(float)(y + gh) / (float)tw
		};
		ca.metrics[i] = (v4f){
			(float)(gx0 - x0) / (float)bw,
			(float)(gy0 - y0) / (float)bh,
			(float)gw / (float)bw,
			(float)gh / (float)bh
		};
		if ((gw > bw) || (gh > bh))
			return (clean_end_ttftoca(ca, fbuf, tex));
		if ((x + bw) > tw)
		{
			x = 1;
			y += bh + 1;
		}
		if ((y + bh) >= tw)
			return (clean_end_ttftoca(ca, fbuf, tex));
		stbtt_MakeGlyphBitmap(&font, tex + x + (y * tw), gw, gh, tw, fs, fs, g);
		x += bw + 1;
	}
	puts("coucou les amis");
	// Gen GL texture
	glGenTextures(1, &texid);
	ca.texture = texid;
	glBindTexture(GL_TEXTURE_2D, texid);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 4);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_R,
		tw, tw, 0, GL_R, GL_UNSIGNED_BYTE, tex);
	i = 96;
	x = 1;
	// Get max char bounding box
	stbtt_GetFontBoundingBox(&font, &x0, &y0, &x1, &y1);
	while (i > 6) {
		i /= 2;
		fs = stbtt_ScaleForPixelHeight(&font, (int)i - 2);
		bw = (int)round((x1 - x0) * fs) + 1;
		bh = (int)round((y1 - y0) * fs) + 1;
		tw /= 2;
		fill_tex(&font, tex, chartab, len, bw + 1, bh + 1, fs, tw);
		glTexImage2D(GL_TEXTURE_2D, x++, GL_R,
			tw, tw, 0, GL_R, GL_UNSIGNED_BYTE, tex);
	}
	(void)fill_tex;
	glBindTexture(GL_TEXTURE_2D, 0);
	ca.length = len;
	return (clean_end_ttftoca(ca, fbuf, tex));
}
