/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matf_rotz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:20:59 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/16 19:48:33 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

t_mattf				*pmattf_rotz(t_mattf *mat, float rad)
{
	t_mattf			rot;

	rot = nmattf_rotz(rad);
	return (pmattf_multiply(mat, &rot));
}

t_mattf				mattf_rotz(t_mattf mat, float rad)
{
	t_mattf			rot;

	rot = nmattf_rotz(rad);
	pmattf_multiply(&mat, &rot);
	return (mat);
}

t_mattf				nmattf_rotz(float rad)
{
	const float		c = cos(rad);
	const float		s = sin(rad);

	return ((t_mattf){
		(t_v3f){ c, s, 0.0f},
		(t_v3f){ -s, c, 0.0f},
		(t_v3f){ 0.0f, 0.0f, 1.0f},
		(t_v3f){ 0.0f, 0.0f, 0.0f},
		(t_v4f){ 0.0f, 0.0f, 0.0f, 1.0f}});
}
