/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_clip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:58:01 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/21 14:11:33 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libdraw.h"
#include "basic.h"
#include <stdio.h>

void		draw_clipval(t_v3f *p, float df, float limit, unsigned int ord)
{
	if (ord & BSH3)
		p->y += (limit - p->x) / df;
	else if (ord & BSH4)
		p->x += (limit - p->y) * df;
	else if (ord & BSH5)
		p->y -= (p->x - limit) / df;
	else if (ord & BSH6)
		p->x -= (p->y - limit) * df;
	else if (ord & BSH7)
		p->y += (p->x - limit) / df;
	else if (ord & BSH8)
		p->x += (p->y - limit) * df;
	if (ord & BSH9)
		limit -= 1.0f;
	if (ord & BSH1)
		p->x = limit;
	else if (ord & BSH2)
		p->y = limit;
}

int			draw_clip_pos(t_v3f *s, t_v3f *e, t_v2i *d, t_v2ui *limit)
{
	float	df;

	*d = (t_v2i){round(e->x - s->x), round(e->y - s->y)};
	df = (round(e->x - s->x) / round(e->y - s->y));
	if (s->x < 0.0f)
		draw_clipval(s, df, 0.0f, BSH1 | BSH3);
	if ((int)s->y < 0.0f)
		draw_clipval(s, df, 0.0f, BSH2 | BSH4);
	if ((int)e->x >= (int)(limit->x))
		draw_clipval(e, df, (float)(limit->x - 1), BSH1 | BSH5);
	if (e->y >= (int)(limit->y))
		draw_clipval(e, df, (float)(limit->y - 1), BSH2 | BSH6);
	*d = (t_v2i){round(e->x - s->x), round(e->y - s->y)};
	return (1);
}

int			draw_clip_neg(t_v3f *s, t_v3f *e, t_v2i *d, t_v2ui *limit)
{
	float	df;

	*d = (t_v2i){round(e->x - s->x), round(e->y - s->y)};
	df = (round(e->x - s->x) / round(e->y - s->y));
	if (s->x < 0.0f)
		draw_clipval(s, df, 0.0f, BSH1 | BSH3);
	if ((int)s->y >= (int)(limit->y))
		draw_clipval(s, df, (float)(limit->y - 1), BSH2 | BSH6);
	if ((int)e->x >= (int)(limit->x))
		draw_clipval(e, df, (float)(limit->x - 1), BSH1 | BSH5);
	if (e->y < 0.0f)
		draw_clipval(e, df, 0.0f, BSH2 | BSH4);
	*d = (t_v2i){round(e->x - s->x), round(e->y - s->y)};
	if (d->y > 0)
		return (1);
	return (-1);
}

void		draw_swap(t_v3f *s, t_v3f *e, t_gradient *gr, int swp)
{
	if (swp & 2)
		swapv3f(s, e);
	if (gr && (swp & 1))
		swap(&(gr->s), &(gr->e));
}
