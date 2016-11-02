/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matf_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:27:24 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/21 14:56:49 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

t_mattf				*pmattf_rot(t_mattf *mat, t_v3f vrad)
{
	t_mattf			rot;

	rot = nmattf_rot(vrad);
	return (pmattf_multiply(mat, &rot));
}

t_mattf				mattf_rot(t_mattf mat, t_v3f vrad)
{
	t_mattf			rot;

	rot = nmattf_rot(vrad);
	pmattf_multiply(&mat, &rot);
	return (mat);
}

t_mattf				nmattf_rot(t_v3f vrad)
{
	const t_v3f		c = (t_v3f){cos(vrad.x), cos(vrad.y), cos(vrad.z)};
	const t_v3f		s = (t_v3f){sin(vrad.x), sin(vrad.y), sin(vrad.z)};
	const float		sxsz = s.x * s.z;
	const float		sycz = s.y * c.z;

	return ((t_mattf){
		(t_v3f){ (c.y * c.z) - (s.y * sxsz), -s.z * c.x, sycz + (c.y * sxsz)},
		(t_v3f){ (s.z * c.y) + (s.y * s.x * c.z), c.z * c.x,
			(s.y * s.z) - (c.y * s.x * c.z)},
			(t_v3f){ -s.y * c.x, s.x, c.x * c.y},
			(t_v3f){ 0.0f, 0.0f, 0.0f},
			(t_v4f){ 0.0f, 0.0f, 0.0f, 1.0f}});
}
