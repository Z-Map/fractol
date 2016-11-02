/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matf_scalv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:06:20 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/16 13:08:13 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mattf				*pmattf_scalv(t_mattf *mat, t_v3f sizev)
{
	pv3fmulv3f(&(mat->x), &sizev);
	pv3fmulv3f(&(mat->y), &sizev);
	pv3fmulv3f(&(mat->z), &sizev);
	return (mat);
}

t_mattf				mattf_scalv(t_mattf mat, t_v3f sizev)
{
	pv3fmulv3f(&(mat.x), &sizev);
	pv3fmulv3f(&(mat.y), &sizev);
	pv3fmulv3f(&(mat.z), &sizev);
	return (mat);
}

t_mattf				nmattf_scalv(t_v3f sizev)
{
	return ((t_mattf){
		(t_v3f){ sizev.x, 0.0f, 0.0f},
		(t_v3f){ 0.0f, sizev.y, 0.0f},
		(t_v3f){ 0.0f, 0.0f, sizev.z},
		(t_v3f){ 0.0f, 0.0f, 0.0f},
		(t_v4f){ 0.0f, 0.0f, 0.0f, 1.0f}});
}
