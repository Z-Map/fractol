/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 01:55:52 by map               #+#    #+#             */
/*   Updated: 2017/01/23 12:31:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern/image.h"

mglimg		*mglw_mkimage(int x, int y, mglw_tf fmt,  mglw_if flags)
{
	mglw_sys *const	sys = MGLWgetsys();
	int				bpp;
	mglimg			img;
	mglimg			*ret;

	flags &= MGLWI_USERFLAG;
	if (!fmt)
		fmt = sys->settings[MGLWS_DEFAULT_IFORMAT];
	bpp = MGLWgetBpp(fmt, flags);
	if (!bpp)
		bpp = sys->settings[MGLWS_DEFAULT_IBPP];
	img = (mglimg){ .x = (uint)x, .y = (uint)y,
		.bpp = (uint)bpp, .flags = flags,
		.format = fmt, .type = MGLWgetType(fmt, flags),
		.memlen = x * y * bpp, .pixels = NULL, .creatime = glfwGetTime(),
		.next = NULL};
	ret = &img;
	if ((flags & MGLWI_DYNAMIC) && !(ret = malloc(sizeof(mglimg))))
		return (NULL);
	else if (flags & MGLWI_DYNAMIC)
		*ret = img;
	if (!(ret = mglw_setimg(ret, NULL)))
		return (NULL);
	MGLWaddimg(ret);
	return (ret);
}

mglimg		*mglw_mkimg(int x, int y)
{
	mglw_sys *const	sys = MGLWgetsys();

	return (mglw_mkimage(x, y,
		sys->settings[MGLWS_DEFAULT_IFORMAT],
		(mglw_if)(sys->settings[MGLWS_DEFAULT_IFLAG])));
}

mglimg		*mglw_dupimg(mglimg *img)
{
	mglimg			*ret;

	if (!img)
		return (NULL);
	if (img->flags & MGLWI_TEXTURE)
		ret = (mglimg *)mglw_mktexture(
			(int)img->x, (int)img->y, img->format, img->flags);
	else
		ret = mglw_mkimage((int)img->x, (int)img->y, img->format, img->flags);
	if (ret)
		memcpy(img->pixels, ret->pixels, img->memlen);
	return (ret);
}

mglimg		*mglw_setimg(mglimg *img, uchar *pixels)
{
	size_t			dsize;
	mglimg			*ret;

	if (!img)
		return (NULL);
	if (pixels)
	{
		if ((img->pixels) && (img->flags & MGLWI_DYNAMIC)
			&& !(img->flags & MGLWI_NOALLOC))
			mglw_unsetimg(img);
		else if ((img->pixels) && !(img->flags & MGLWI_DYNAMIC))
			return (NULL);
		img->pixels = pixels;
		img->flags |= MGLWI_USERALLOC;
		return (img);
	}
	else if ((img->pixels) || (img->flags & MGLWI_NOALLOC))
		return (img);
	dsize = (img->flags & MGLWI_TEXTURE) ? sizeof(mgltex): sizeof(mglimg);
	if ((img->flags & MGLWI_DYNAMIC) &&
		(img->pixels = malloc(img->memlen)))
		return (img);
	else if ((img->flags & MGLWI_DYNAMIC) ||
			!(ret = malloc(dsize + img->memlen)))
		return (NULL);
	memcpy(img, ret, dsize);
	img->pixels = (uchar *)((size_t)ret + dsize);
	return (ret);
}

mglimg		*mglw_resetimg(mglimg *img)
{
	mglimg			tmpi;
	mglimg			*ret;
	uchar			*pxs;

	if (!img)
		return (NULL);
	if (!(img->flags & MGLWI_DYNAMIC))
	{
		if (!(ret = mglw_mkimage(
			(uint)img->x, (uint)img->y, img->format, img->flags)))
			return (NULL);
		MGLWdelimg(img);
		return (ret);
	}
	pxs = img->pixels;
	tmpi = *img;
	img->pixels = NULL;
	if (mglw_setimg(img, NULL))
	{
		if (img->flags & MGLWI_LOADED)
			mglw_unloadimg(&tmpi);
		else if (!(img->flags & MGLWI_NOALLOC))
			free(pxs);
		img->flags &= ~MGLWI_LOADED;
		return (img);
	}
	img->pixels = pxs;
	return (NULL);
}

mglimg		*mglw_unsetimg(mglimg *img)
{
	size_t			dsize;
	mglimg			*ret;

	if (img && (img->pixels))
	{
		if (img->flags & MGLWI_LOADED)
			mglw_unloadimg(img);
		else if ((img->flags & MGLWI_USERALLOC) == MGLWI_DYNAMIC)
			free(img->pixels);
		else
		{
			dsize = (img->flags &  MGLWI_TEXTURE) ?
				sizeof(mgltex) : sizeof(mglimg);
			if (!(ret = malloc(sizeof(dsize))))
				return (NULL);
			MGLWdelimg(img);
			memcpy(img, ret, dsize);
			free(img);
			img = ret;
			img->flags |= MGLWI_DYNAMIC;
			MGLWaddimg(img);
		}
		img->pixels = NULL;
	}
	return (img);
}

mglimg		*mglw_resizeimg(mglimg *img, int x, int y, mglw_tf fmt)
{
	uchar			*pxs;
	int				bpp;
	size_t			memlen;

	if (!img)
		return (NULL);
	if (fmt == MGLW_TF_UNDEFINED)
		fmt = img->format;
	bpp = MGLWgetBpp(fmt, img->flags);
	if (!bpp)
		bpp = mglw_getsetting(MGLWS_DEFAULT_IBPP);
	memlen = (size_t)(x * y * bpp);
	if (!(pxs = malloc(memlen)) || !mglw_unsetimg(img))
		return (NULL);
	img->x = x;
	img->y = y;
	img->format = fmt;
	img->bpp = bpp;
	img->memlen = memlen;
	img->pixels = pxs;
	return (img);
}

void		mglw_rmimg(mglimg *img)
{
	if (img)
	{
		MGLWdelimg(img);
		if (img->pixels)
		{
			if (img->flags & MGLWI_DYNAMIC)
				free(img->pixels);
			else if (img->flags & MGLWI_LOADED)
				mglw_unloadimg(img);
		}
		free(img);
	}
}
