/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul3f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 01:06:47 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/16 12:59:05 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_v3f					v3fmulv3i(t_v3f a, t_v3i b)
{
	return ((t_v3f){ a.x * (float)(b.x),
		a.y * (float)(b.y),
		a.z * (float)(b.z)});
}

t_v3f					*pv3fmulv3i(t_v3f *a, const t_v3i *b)
{
	a->x *= (float)(b->x);
	a->y *= (float)(b->y);
	a->z *= (float)(b->z);
	return (a);
}

t_v3f					v3fmulv3f(t_v3f a, t_v3f b)
{
	return ((t_v3f){ a.x * (float)(b.x),
		a.y * (float)(b.y),
		a.z * (float)(b.z)});
}

t_v3f					*pv3fmulv3f(t_v3f *a, const t_v3f *b)
{
	a->x *= b->x;
	a->y *= b->y;
	a->z *= b->z;
	return (a);
}
