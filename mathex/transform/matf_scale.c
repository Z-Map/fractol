/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matf_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 09:27:57 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/16 13:05:55 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mattf				*pmattf_scale(t_mattf *mat, float size)
{
	const t_v3f		s = nv3f(size);

	pv3fmulv3f(&(mat->x), &s);
	pv3fmulv3f(&(mat->y), &s);
	pv3fmulv3f(&(mat->z), &s);
	return (mat);
}

t_mattf				mattf_scale(t_mattf mat, float size)
{
	const t_v3f		s = nv3f(size);

	pv3fmulv3f(&(mat.x), &s);
	pv3fmulv3f(&(mat.y), &s);
	pv3fmulv3f(&(mat.z), &s);
	return (mat);
}

t_mattf				nmattf_scale(float size)
{
	return ((t_mattf){
		(t_v3f){ size, 0.0f, 0.0f},
		(t_v3f){ 0.0f, size, 0.0f},
		(t_v3f){ 0.0f, 0.0f, size},
		(t_v3f){ 0.0f, 0.0f, 0.0f},
		(t_v4f){ 0.0f, 0.0f, 0.0f, 1.0f}});
}
