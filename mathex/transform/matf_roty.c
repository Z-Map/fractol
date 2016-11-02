/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matf_roty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:08:09 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/16 19:48:33 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

t_mattf				*pmattf_roty(t_mattf *mat, float rad)
{
	t_mattf			rot;

	rot = nmattf_roty(rad);
	return (pmattf_multiply(mat, &rot));
}

t_mattf				mattf_roty(t_mattf mat, float rad)
{
	t_mattf			rot;

	rot = nmattf_roty(rad);
	pmattf_multiply(&mat, &rot);
	return (mat);
}

t_mattf				nmattf_roty(float rad)
{
	const float			c = cos(rad);
	const float			s = sin(rad);

	return ((t_mattf){
		(t_v3f){ c, 0.0f, -s},
		(t_v3f){ 0.0f, 1.0f, 0.0f},
		(t_v3f){ s, 0.0f, c},
		(t_v3f){ 0.0f, 0.0f, 0.0f},
		(t_v4f){ 0.0f, 0.0f, 0.0f, 1.0f}});
}
