/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub2i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 01:12:31 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/16 01:34:14 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_v2i					v2isubv2i(t_v2i a, t_v2i b)
{
	return ((t_v2i){ a.x - b.x, a.y - b.y });
}

t_v2i					*pv2isubv2i(t_v2i *a, const t_v2i *b)
{
	a->x -= b->x;
	a->y -= b->y;
	return (a);
}

t_v2i					v2isubv2f(t_v2i a, t_v2f b)
{
	return ((t_v2i){ a.x - b.x, a.y - b.y });
}

t_v2i					*pv2isubv2f(t_v2i *a, const t_v2f *b)
{
	a->x -= b->x;
	a->y -= b->y;
	return (a);
}
