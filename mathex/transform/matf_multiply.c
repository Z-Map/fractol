/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matf_multiply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:54:05 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/16 12:41:19 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static inline void	pmattf_vecprod(t_v3f *v, const t_mattf *mat)
{
	*v = (t_v3f){(mat->x.x * v->x) + (mat->y.x * v->y) + (mat->z.x * v->z),
		(mat->x.y * v->x) + (mat->y.y * v->y) + (mat->z.y * v->z),
		(mat->x.z * v->x) + (mat->y.z * v->y) + (mat->z.z * v->z)};
}

t_mattf				*pmattf_multiply(t_mattf *dest, const t_mattf *mat)
{
	pmattf_apply(&(dest->offset), mat);
	pmattf_vecprod(&(dest->x), mat);
	pmattf_vecprod(&(dest->y), mat);
	pmattf_vecprod(&(dest->z), mat);
	return (dest);
}

t_mattf				mattf_multiply(t_mattf mat1, t_mattf mat2)
{
	pmattf_multiply(&mat1, &mat2);
	return (mat1);
}

t_v3f				*pmattf_apply(t_v3f *v, const t_mattf *mat)
{
	pmattf_vecprod(v, mat);
	v->x += mat->offset.x;
	v->y += mat->offset.y;
	v->z += mat->offset.z;
	return (v);
}

t_v3f				mattf_apply(t_v3f v, t_mattf mat)
{
	return ((t_v3f){
		(mat.x.x * v.x) + (mat.y.x * v.y) + (mat.z.x * v.z) + mat.offset.x,
		(mat.x.y * v.x) + (mat.y.y * v.y) + (mat.z.y * v.z) + mat.offset.y,
		(mat.x.z * v.x) + (mat.y.z * v.y) + (mat.z.z * v.z) + mat.offset.z});
}
