/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matf_rotx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:15:34 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/16 19:48:33 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

t_mattf				*pmattf_rotx(t_mattf *mat, float rad)
{
	t_mattf			rot;

	rot = nmattf_rotx(rad);
	return (pmattf_multiply(mat, &rot));
}

t_mattf				mattf_rotx(t_mattf mat, float rad)
{
	t_mattf			rot;

	rot = nmattf_rotx(rad);
	pmattf_multiply(&mat, &rot);
	return (mat);
}

t_mattf				nmattf_rotx(float rad)
{
	const float		c = cos(rad);
	const float		s = sin(rad);

	return ((t_mattf){
		(t_v3f){ 1.0f, 0.0f, 0.0f},
		(t_v3f){ 0.0f, c, s},
		(t_v3f){ 0.0f, -s, c},
		(t_v3f){ 0.0f, 0.0f, 0.0f},
		(t_v4f){ 0.0f, 0.0f, 0.0f, 1.0f}});
}
