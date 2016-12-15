/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tris.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 00:33:08 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/27 22:49:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUADS_H
#define QUADS_H

static const struct	{
	float	vertex[9];
	float	colors[9];
	float	uvs[6];
	int		index[3];
} mglw_GR_tris = {			// Tris static data :
	.vertex = {				// Vertex :
		-1.0f, -1.0f, 0.0f,	// left bottom
		-1.0f, 1.0f, 0.0f,	// left top
		1.0f, -1.0f, 0.0f,	// right bottom
	}, .colors = {			// Vertex colors :
		1.0f, 1.0f, 1.0f,	// == rgb(255, 255, 255)
		1.0f, 1.0f, 1.0f,	// All vertex are white by
		1.0f, 1.0f, 1.0f,	// default.
	}, .uvs = {				// UVs :
		0.0f, 0.0f,			// left bottom
		0.0f, 1.0f,			// left top
		1.0f, 0.0f,			// right bottom
	}, .index = {			// Triangle index :
		0, 1, 2,			// Triangle 1
	}
};

#endif
