/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 01:55:52 by map               #+#    #+#             */
/*   Updated: 2016/12/21 15:31:03 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern/image.h"
#pragma GCC diagnostic push
#if __GNUC__ >= 6
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif
#pragma GCC diagnostic ignored "-Wshift-negative-value"
#define STBI_ONLY_JPEG
#define STBI_ONLY_PNG
#define STBI_ONLY_BMP
#define STB_IMAGE_IMPLEMENTATION
#include "hlib/stb_image.h"
#pragma GCC diagnostic pop

mglimg		*mglw_loadimage(const char *filename, mglw_if flags, int n)
{
	mglimg			img;
	mglimg			*ret;

	if (n > 4)
		n = 4;
	else if (n < 0)
		n = 0;
	flags &= MGLWI_LOADFLAG;
	img = (mglimg){ .x = 0, .y = 0, .bpp = 0,
		.flags = MGLWI_LOADED | MGLWI_DYNAMIC | flags,
		.format = MGLW_TF_UNDEFINED, .type = MGLW_UBYTE,
		.memlen = 0, .pixels = NULL, .creatime = glfwGetTime(),
		.next = NULL};
	if (!(ret = malloc(sizeof(mglimg))))
		return (NULL);
	if (!(img.pixels = stbi_load(filename,
		(int *)&(img.x), (int *)&(img.y), (int *)&(img.bpp), n)))
	{
		free(ret);
		return (NULL);
	}
	if (n)
		img.bpp = n;
	img.format = MGLWgetFormat(img.bpp, flags);
	img.memlen = img.x * img.y * img.bpp;
	*ret = img;
	MGLWaddimg(ret);
	return (ret);
}

mglimg		*mglw_loadimg(const char *filename)
{
	mglw_sys *const	sys = MGLWgetsys();

	return (mglw_loadimage(filename,
		sys->settings[MGLWS_DEFAULT_IFLAG], 0));
}

mgltex		*mglw_loadtexture(const char *filename, mglw_if flags, mglw_tf fmt)
{
	mglimg			img;
	mgltex			*ret;
	int				n;

	flags &= MGLWI_USERFLAG;
	n = MGLWgetBpp(fmt, flags);
	img = (mglimg){ .x = 0, .y = 0, .bpp = 0,
		.flags = MGLWI_LOADED | MGLWI_DYNAMIC | MGLWI_TEXTURE | flags,
		.format = fmt, .type = MGLW_UBYTE,
		.memlen = 0, .pixels = NULL, .creatime = glfwGetTime(),
		.next = NULL};
	if (!(ret = malloc(sizeof(mgltex))))
		return (NULL);
	if (!(img.pixels = stbi_load(filename,
		(int *)&(img.x), (int *)&(img.y), (int *)&(img.bpp), n)))
	{
		free(ret);
		return (NULL);
	}
	if (n)
		img.bpp = n;
	else
		img.format = MGLWgetFormat(img.bpp, img.flags);
	img.memlen = img.x * img.y * img.bpp;
	ret->cpuimage = img;
	ret->texid = 0;
	MGLWaddimg((mglimg *)ret);
	return (ret);
}

mgltex		*mglw_loadtex(const char *filename)
{
	mglw_sys *const	sys = MGLWgetsys();

	return (mglw_loadtexture(filename,
		sys->settings[MGLWS_DEFAULT_TFLAG], MGLW_TF_UNDEFINED));
}

mglimg		*mglw_reloadimg(mglimg *img, const char *filename)
{
	mglimg			nimg;
	int				n;

	if (!img)
		return (NULL);
	nimg = *img;
	if (!(nimg.pixels = stbi_load(filename, (int *)&(nimg.x), (int *)&(nimg.y),
		(int *)&(n), (int)nimg.bpp)))
		return (NULL);
	nimg.flags |= MGLWI_LOADED | MGLWI_DYNAMIC;
	if (!mglw_unsetimg(img))
	{
		stbi_image_free(nimg.pixels);
		return (NULL);
	}
	nimg.next = img->next;
	*img = nimg;
	return  (img);
};

void		mglw_unloadimg(mglimg *img)
{
	if (!img)
		return ;
	if (img->flags & MGLWI_LOADED)
	{
		stbi_image_free(img->pixels);
		img->pixels = NULL;
	}
	img->flags &= ~MGLWI_LOADED;
}
