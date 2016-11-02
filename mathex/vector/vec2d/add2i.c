/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add2i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 01:06:47 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/16 01:11:55 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_v2i					v2iaddv2i(t_v2i a, t_v2i b)
{
	return ((t_v2i){ a.x + b.x, a.y + b.y });
}

t_v2i					*pv2iaddv2i(t_v2i *a, const t_v2i *b)
{
	a->x += b->x;
	a->y += b->y;
	return (a);
}

t_v2i					v2iaddv2f(t_v2i a, t_v2f b)
{
	return ((t_v2i){ a.x + b.x, a.y + b.y });
}

t_v2i					*pv2iaddv2f(t_v2i *a, const t_v2f *b)
{
	a->x += b->x;
	a->y += b->y;
	return (a);
}
