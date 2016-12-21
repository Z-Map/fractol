/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:20:49 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/21 15:43:33 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern/image.h"

mglw_tt			MGLWgetType(mglw_tf fmt, mglw_if flags)
{
	(void)fmt;
	if (flags & MGLWI_FLOAT)
		return (MGLW_FLOAT);
	else if (flags & MGLWI_INT)
		return (MGLW_UINT);
	else
		return (MGLW_UBYTE);
}

int				MGLWgetBpp(mglw_tf fmt, mglw_if flags)
{
	int	csize = 1;

	if (flags & MGLWI_FLOAT)
		csize = sizeof(float);
	else if (flags & MGLWI_INT)
		csize = sizeof(int);
	if ((fmt == MGLW_BGRA) || (fmt == MGLW_RGBA))
		return (4 * csize);
	else if ((fmt == MGLW_RGB) || (fmt == MGLW_BGR))
		return (3 * csize);
	else if ((fmt == MGLW_RG) || (fmt == MGLW_DEPTH_STEN))
		return (2 * csize);
	else if ((fmt == MGLW_RED) || (fmt == MGLW_STEN) || (fmt == MGLW_DEPTH))
		return (1 * csize);
	return (0);
}

mglw_tf			MGLWgetFormat(int bpp, mglw_if flags)
{
	int	csize = 1;

	if (flags & MGLWI_FLOAT)
		csize = sizeof(float);
	else if (flags & MGLWI_INT)
		csize = sizeof(int);
	bpp /= csize;
	if (bpp == 4)
		return (MGLW_RGBA);
	else if (bpp == 3)
		return (MGLW_RGB);
	else if (bpp == 2)
		return (MGLW_RG);
	else if (bpp == 1)
		return (MGLW_RED);
	return (MGLW_TF_UNDEFINED);
}

mgltex			*mglw_mktexture(int x, int y, mglw_tf fmt,  mglw_if flags)
{
	mglw_sys *const	sys = MGLWgetsys();
	mglimg			img;
	mgltex			*ret;
	int			bpp;

	flags &= MGLWI_USERFLAG;
	flags |= MGLWI_TEXTURE;
	if (fmt == MGLW_TF_UNDEFINED)
		fmt = sys->settings[MGLWS_DEFAULT_TEXFORMAT];
	bpp = MGLWgetBpp(fmt, flags);
	img = (mglimg){ .x = (uint)x, .y = (uint)y, .bpp = (uint)bpp,
		.flags = flags, .format = fmt, .type = MGLWgetType(fmt, flags),
		.memlen = x * y * bpp, .pixels = NULL, .creatime = glfwGetTime(),
		.next = NULL};
	ret = (mgltex *)&img;
	if ((flags & MGLWI_DYNAMIC) && !(ret = malloc(sizeof(mgltex))))
		return (NULL);
	else if (flags & MGLWI_DYNAMIC)
		ret->cpuimage = img;
	if (!(ret = (mgltex *)mglw_setimg((mglimg *)ret, NULL)))
		return (NULL);
	ret->texid = 0;
	ret->format = fmt;
	MGLWaddimg((mglimg *)ret);
	return (ret);
}

mgltex			*mglw_mktex(int x, int y)
{
	mglw_sys *const	sys = MGLWgetsys();

	return (mglw_mktexture(x, y,
		(mglw_tf)sys->settings[MGLWS_DEFAULT_TEXFORMAT],
		sys->settings[MGLWS_DEFAULT_TFLAG]));
}
