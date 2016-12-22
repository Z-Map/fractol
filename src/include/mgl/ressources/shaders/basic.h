/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:32:54 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/22 17:30:53 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_SHADERS_H
#define BASIC_SHADERS_H

#include "mgl/shaders.h"

static const mglsha		drawimage2d_shader = (mglsha){
	.id = 0,
	.vshid = 0,
	.fshid = 0,
	.vsh = "#version 130\n\
	in vec3 v_pos;\n\
	in vec2 v_uv;\n\
	out vec2 tex_coord;\n\
	void main()\n\
	{\n\
		gl_Position.xyz = v_pos;\n\
		gl_Position.w = 1.0;\n\
		tex_coord = v_uv;\n\
	}\n\
	",
	.fsh = "#version 130\n\
	in vec2 tex_coord;\n\
	uniform sampler2D image;\n\
	out vec4 color;\n\
	void main()\n\
	{\n\
		color = texture2D(image, tex_coord);\n\
	}\n\
	"
};

#endif
