/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesquare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 04:05:55 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/14 16:41:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glload/gl_all.h"
#include "glload/gl_load.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "mglw/mglw.h"

#define CUBECOL 0xff0000ff

typedef struct		test_context
{
	int				x;
	int				y;
	int				mx;
	int				my;
	int				size;
	int				fullscreen;
}					tctx;

int		keypress(void *c, int k)
{
	tctx	*ctx = (tctx *)c;

	if (k == MGLW_KEY_W)
		ctx->y -= 5;
	else if (k == MGLW_KEY_S)
		ctx->y += 5;
	else if (k == MGLW_KEY_A)
		ctx->x -= 5;
	else if (k == MGLW_KEY_D)
		ctx->x += 5;
	else if (k == MGLW_KEY_F)
		ctx->fullscreen = 1;
	return (0);
}

int		keyrelease(void *c, int k)
{
	tctx	*ctx = (tctx *)c;

	if (k == MGLW_KEY_W)
		ctx->y += 5;
	else if (k == MGLW_KEY_S)
		ctx->y -= 5;
	else if (k == MGLW_KEY_A)
		ctx->x += 5;
	else if (k == MGLW_KEY_D)
		ctx->x -= 5;
	return (0);
}

void	resizeprocess(void *c, int w, int h)
{
	tctx	*ctx = (tctx *)c;

	printf("coucou %i, %i\n", w, h);
	ctx->mx = w - ctx->size;
	ctx->my = h - ctx->size;
}

int		keyprocess(tctx *ctx, tctx *kctx)
{
	ctx->x += kctx->x;
	ctx->y += kctx->y;
	if (ctx->x > kctx->mx)
		ctx->x = kctx->mx;
	else if (ctx->x < 0)
		ctx->x = 0;
	if (ctx->y > kctx->my)
		ctx->y = kctx->my;
	else if (ctx->y < 0)
		ctx->y = 0;
	return (0);
}

void	init_ctx(tctx *ctx, mglimg *img, int size)
{
	if (size < 0)
		size = -size;
	ctx->size = size;
	ctx->x = (img->x / 2) - (size / 2);
	ctx->y = (img->y / 2) - (size / 2);
	ctx->mx = img->x - size;
	ctx->my = img->y - size;
	ctx->fullscreen = 0;
}

void	draw(tctx *ctx, mglimg *img)
{
	static tctx		last = { 0, 0, 0, 0, 0, 0};
	int				x, y, i, j;
	unsigned int	*pxs;

	pxs = (unsigned int *)(img->pixels);
	if (last.size)
	{
		if ((last.x <= ctx->mx) || (last.y <= ctx->my))
		{
			j = last.y + last.size;
			if (j > (ctx->my + ctx->size))
				j = ctx->my + ctx->size;
			if ((last.x + last.size) > (ctx->mx + ctx->size))
			{
				last.x = ctx->mx;
				last.size = ctx->size;
			}
			for (y = last.y; y < j; y++){
				x = y * img->x + last.x;
				bzero(pxs + x, last.size * sizeof(int));
			}
			last.size = ctx->size;
		}
	}
	if (ctx->size)
	{
		if (!last.size)
		{
			last = *ctx;
			ctx->x = 0;
			ctx->y = 0;
		}
		else
			keyprocess(&last, ctx);
		j = last.y + last.size;
		for (y = last.y; y < j; y++){
			x = y * img->x + last.x;
			for (i = 0; i < last.size; i++){
				pxs[x + i] = CUBECOL;
			}
		}
	}
}

int		main()
{
	const struct timespec	t = (struct timespec){0, 12000000L};
	mglwin					*win;
	mglimg					*img;
	// mglimg					*doggo;
	tctx					ctx;

	if (!(mglw_init()) ||
		!(win = mglw_openwin(
			mglw_mkwin(MGLW_LEGACY_MODE, MGLW_2DLAYER),
			800, 600, "Coucou !")))
		return (-1);
	mglw_setsetting(MGLWS_EXITKEY, MGLW_KEY_ESCAPE);
	img = (mglimg *)mglw_get2dlayer(win);
	// doggo = mglw_loadimage("doggo.jpg", MGLWI_NONE, 4);
	// memcpy(img->pixels, pinguin->pixels, img->memlen);
	bzero(img->pixels, img->memlen);
	init_ctx(&ctx, img, 20);
	mglw_setkcb(win, 1, &keypress, &ctx);
	mglw_setkcb(win, 0, &keyrelease, &ctx);
	mglw_setsizecb(win, &resizeprocess, &ctx);
	while (mglwin_run(win))
	{
		// mglw_draw_itow(win, doggo, 0, 0);
		// glDisable(GL_DEPTH_TEST);
		// glDisable(GL_CULL_FACE);
		// glDisable(GL_TEXTURE_2D);
		glColor3f(1.0f, 0.8f, 0.15f);
		glBegin(GL_TRIANGLES);
		glVertex3f(-0.5f, -0.5f, 0.0f);
		glVertex3f( 0.0f, -0.5f, 0.0f);
		glVertex3f(-0.25f, 0.0f, 0.0f);
		glVertex3f( 0.5f, -0.5f, 0.0f);
		glVertex3f( 0.0f, -0.5f, 0.0f);
		glVertex3f(0.25f, 0.0f, 0.0f);
		glVertex3f( -0.25f, 0.0f, 0.0f);
		glVertex3f( 0.25f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glEnd();
		if (ctx.fullscreen)
		{
			mglw_togglefullscreen(win, 1);
			ctx.fullscreen = 0;
		}
		draw(&ctx, img);
		nanosleep(&t, NULL);
	}
	mglw_close();
	return (0);
}
