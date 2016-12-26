/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:32:54 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/26 04:11:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_SHADERS_H
#define BASIC_SHADERS_H

#include "mgl/shaders.h"

static const mglsha		drawimage2d_shader = (mglsha){
	.id = 0,
	.vshid = 0,
	.fshid = 0,
	.vsh =
#include "pixelbox.vert.h"
,
	.fsh =
#include "pixelbox.frag.h"
};

#endif
