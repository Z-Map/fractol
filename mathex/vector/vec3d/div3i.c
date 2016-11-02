/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div3i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 01:12:31 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/16 13:00:07 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_v3i					v3idivv3i(t_v3i a, t_v3i b)
{
	return ((t_v3i){ a.x / b.x, a.y / b.y, a.z / b.z});
}

t_v3i					*pv3idivv3i(t_v3i *a, const t_v3i *b)
{
	a->x /= b->x;
	a->y /= b->y;
	a->z /= b->z;
	return (a);
}

t_v3i					v3idivv3f(t_v3i a, t_v3f b)
{
	return ((t_v3i){ a.x / (int)(b.x), a.y / (int)(b.y), a.z / (int)(b.z)});
}

t_v3i					*pv3idivv3f(t_v3i *a, const t_v3f *b)
{
	a->x /= (int)(b->x);
	a->y /= (int)(b->y);
	a->z /= (int)(b->z);
	return (a);
}
