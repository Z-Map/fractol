/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:03:37 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/21 15:29:49 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGLW_IMAGE_H

#include "mglw_intern/mglw_header.h"
#include "mglw_intern/system.h"

#include "mglw/image.h"

/* MiniGLwin image management  */

int			MGLWgetBpp(mglw_tf fmt, mglw_if flags);
mglw_tf		MGLWgetFormat(int bpp, mglw_if flags);
mglw_tt		MGLWgetType(mglw_tf fmt, mglw_if flags);

#endif
