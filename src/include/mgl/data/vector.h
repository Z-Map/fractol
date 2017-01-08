/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 07:15:14 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/01 07:18:59 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGL_VECTOR_H
#define MGL_VECTOR_H

/* -------------------------------------------------------------------------- */
// Vector int

typedef struct		int_vector_2d
{
	int				x;
	int				y;
}					v2i;

typedef struct		int_vector_3d
{
	int				x;
	int				y;
	int				z;
}					v3i;

typedef struct		int_vector_4d
{
	int				x;
	int				y;
	int				z;
	int				w;
}					v4i;

typedef struct		uint_vector_2d
{
	unsigned int	x;
	unsigned int	y;
}					v2ui;

typedef struct		uint_vector_3d
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	z;
}					v3ui;

typedef struct		uint_vector_4d
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	z;
	unsigned int	w;
}					v4ui;

/* -------------------------------------------------------------------------- */
// Vector float

typedef struct		float_vector_2d
{
	float			x;
	float			y;
}					v2f;

typedef struct		float_vector_3d
{
	float			x;
	float			y;
	float			z;
}					v3f;

typedef struct		float_vector_4d
{
	float			x;
	float			y;
	float			z;
	float			w;
}					v4f;

/* -------------------------------------------------------------------------- */
// Vector double

typedef struct		double_vector_2d
{
	double			x;
	double			y;
}					v2d;

typedef struct		double_vector_3d
{
	double			x;
	double			y;
	double			z;
}					v3d;

typedef struct		double_vector_4d
{
	double			x;
	double			y;
	double			z;
	double			w;
}					v4d;

#endif
