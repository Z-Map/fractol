/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:03:37 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/23 12:21:07 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGLW_IMAGE_H
#define MGLW_IMAGE_H

#include "mglw/mglw_header.h"

/* MiniGLwin image management  */

mglimg		*mglw_mkimg(int x, int y);
mglimg		*mglw_mkimage(int x, int y, mglw_tf fmt, mglw_if flags);
mgltex		*mglw_mktex(int x, int y);
mgltex		*mglw_mktexture(int x, int y, mglw_tf fmt, mglw_if flags);
mglimg		*mglw_loadimg(const char *filename);
mglimg		*mglw_loadimage(const char *filename, mglw_if flags, int bpp);
mgltex		*mglw_loadtex(const char *filename);
mgltex		*mglw_loadtexture(const char *filename, mglw_if flags, GLenum fmt);
mglimg		*mglw_dupimg(mglimg *img);
mglimg		*mglw_setimg(mglimg *img, unsigned char *pixels);
mglimg		*mglw_unsetimg(mglimg *img);
mglimg		*mglw_resetimg(mglimg *img);
mglimg		*mglw_reloadimg(mglimg *img, const char *filename);
mglimg		*mglw_resizeimg(mglimg *img, int x, int y, mglw_tf fmt);
void		mglw_rmimg(mglimg *img);
void		mglw_unloadimg(mglimg *img);

#endif
