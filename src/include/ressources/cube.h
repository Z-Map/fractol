/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 00:33:08 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/27 23:26:04 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUADS_H
#define QUADS_H

/* -------------------------------------------------------------------------- *\
|* 		Cube layout :	|			Triangle strip cube						  *|
|* 		 5----7			|													  *|
|* 		 | \  | \		|	The size of each side of the cube is 2.0f, UV	  *|
|* 		 4--1=6--3		|	coordinates fills each face with one full		  *|
|* 		  \ |  \ |		|	texture unit (no reapeat on same face), and 	  *|
|* 		    0----2		|	there is no duplication of vertices				  *|
|* 						|													  *|
\* -------------------------------------------------------------------------- */

static const struct	{
	float	vertex[24];
	float	colors[24];
	float	uvs[14];
	short	index_ts[14];
	short	index_ts_uv[14];
} mglw_GR_cube = {				// Cube static data :
	.vertex = {					// Vertex :
		-1.0f, -1.0f, 1.0f,		// front left bottom	0
		-1.0f, 1.0f, 1.0f,		// front left top		1
		1.0f, -1.0f, 1.0f,		// front right bottom	2
		1.0f, 1.0f, 1.0f,		// front right top		3
		-1.0f, -1.0f, -1.0f,	// back left bottom		4
		-1.0f, 1.0f, -1.0f,		// back left top		5
		1.0f, -1.0f, -1.0f,		// back right bottom	6
		1.0f, 1.0f, -1.0f		// back right top		7
	}, .colors = {				// Vertex colors :
		1.0f, 1.0f, 1.0f,		// == rgb(255, 255, 255)
		1.0f, 1.0f, 1.0f,		// All vertex are white by
		1.0f, 1.0f, 1.0f,		// default.
		1.0f, 1.0f, 1.0f,		//
		1.0f, 1.0f, 1.0f,		//
		1.0f, 1.0f, 1.0f,		//
		1.0f, 1.0f, 1.0f,		//
		1.0f, 1.0f, 1.0f		//
	}, .uvs = {					// UVs :
		0.0f, 0.0f,				// left bottom
		0.0f, 1.0f,				// left top == top left mirror top left
		1.0f, 0.0f,				// right bottom
		1.0f, 1.0f,				// right top
		-1.0f, 1.0f,			// right top mirror top left
		0.0f, 2.0f,				// left bottom mirror top left
		-1.0f, 2.0f,			// right bottom mirror top left
	}, .index_ts = {			// Triangle strip index :
		1, 0, 2,				// Front face	- tris 1
		6,						// Bottom face	- tris 2
		3, 7,					// Right face	- tris 3 & 4
		5,						// Top face		- tris 5
		6, 4,					// Back face	- tris 6 & 7
		0,						// Bottom face	- tris 8
		5, 1,					// Left face	- tris 9 & 10
		3,						// Top face		- tris 11
		2						// Front face	- tris 12
	}, .index_ts_uv = {			// Triangle strip uv index :
		1, 0, 2,				// Front face	- tris 1
		3,						// Bottom face	- tris 2
		0, 1,					// Right face	- tris 3 & 4
		4,						// Top face		- tris 5
		5, 6,					// Back face	- tris 6 & 7
		4,						// Bottom face	- tris 8
		5, 1,					// Left face	- tris 9 & 10
		3,						// Top face		- tris 11
		2						// Front face	- tris 12
	}
};

#endif
