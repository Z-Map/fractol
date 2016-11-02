/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matf_trans.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:47:59 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/21 14:58:27 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mattf				*pmattf_trans(t_mattf *mat, t_v3f mov)
{
	pv3faddv3f(&(mat->offset), &mov);
	return (mat);
}

t_mattf				mattf_trans(t_mattf mat, t_v3f mov)
{
	pv3faddv3f(&(mat.offset), &mov);
	return (mat);
}

t_mattf				nmattf_trans(t_v3f mov)
{
	return ((t_mattf){
		(t_v3f){ 1.0f, 0.0f, 0.0f},
		(t_v3f){ 0.0f, 1.0f, 0.0f},
		(t_v3f){ 0.0f, 0.0f, 1.0f},
		mov,
		(t_v4f){ 0.0f, 0.0f, 0.0f, 1.0f}});
}
