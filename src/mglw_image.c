/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mglw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 01:55:52 by map               #+#    #+#             */
/*   Updated: 2016/12/15 05:50:18 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern.h"

mglimg		*mglw_mkimage(uint x, uint y, mglw_tf fmt,  mglw_if flags)
{
	mglw_sys *const	sys = MGLWgetsys();
	int				bpp;
	mglimg			img;
	mglimg			*ret;

	flags &= MGLWI_USERFLAG;
	bpp = MGLWgetBpp(fmt, flags);
	if (bpp <= 1)
		bpp = sys->settings[MGLWS_DEFAULT_IBPP];
	img = (mglimg){ .x = x, .y = y, .bpp = (uint)bpp, .flags = flags,
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

mglimg		*mglw_mkimg(uint x, uint y)
{
	mglw_sys *const	sys = MGLWgetsys();

	return (mglw_mkimage(x, y,
		sys->settings[MGLWS_DEFAULT_IFORMAT],
		(uint)sys->settings[MGLWS_DEFAULT_IFLAG]));
}

mglimg		*mglw_dupimg(mglimg *img)
{
	mglimg			*ret;

	if (img->flags & MGLWI_TEXTURE)
		ret = (mglimg *)mglw_mktexture(img->x, img->y, img->format, img->flags);
	else
		ret = mglw_mkimage(img->x, img->y, img->format, img->flags);
	if (ret)
		memcpy(img->pixels, ret->pixels, img->memlen);
	return (ret);
}

mglimg		*mglw_setimg(mglimg *img, uchar *pixels)
{
	size_t			dsize;
	mglimg			*ret;

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

	if (!(img->flags & MGLWI_DYNAMIC))
	{
		if (!(ret = mglw_mkimage(img->x, img->y, img->format, img->flags)))
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

	if (img->pixels)
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
