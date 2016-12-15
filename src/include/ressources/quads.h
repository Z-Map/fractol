/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quads.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 00:33:08 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/27 23:23:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUADS_H
#define QUADS_H

static const struct	{
	float	vertex[12];
	float	colors[12];
	float	uvs[8];
	int		index[4];
} mglw_GR_quad = {			// Quad static data :
	.vertex = {				// Vertex :
		-1.0f, -1.0f, 0.0f,	// left bottom
		-1.0f, 1.0f, 0.0f,	// left top
		1.0f, -1.0f, 0.0f,	// right bottom
		1.0f, 1.0f, 0.0f	// right top
	}, .colors = {			// Vertex colors :
		1.0f, 1.0f, 1.0f,	// == rgb(255, 255, 255)
		1.0f, 1.0f, 1.0f,	// All vertex are white by
		1.0f, 1.0f, 1.0f,	// default.
		1.0f, 1.0f, 1.0f	//
	}, .uvs = {				// UVs :
		0.0f, 0.0f,			// left bottom
		0.0f, 1.0f,			// left top
		1.0f, 0.0f,			// right bottom
		1.0f, 1.0f,			// right top
	}, .index = {			// Triangle strip index :
		0, 1, 2,			// Triangle 1
		3					// Triangle 2 with vertex 1, 2 & 3
	}
};

#endif
