/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 06:52:55 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/21 14:09:18 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libdraw.h"

t_2dl			mkline(t_v3f s, t_v3f e, t_v2ui *limit, t_gradient *gr)
{
	t_2dl		nl;

	nl = (t_2dl){(t_v2ui){0, 0}, (t_v2ui){0, 0}, (t_v2i){0, 0}, 0};
	s = (t_v3f){(float)round(s.x), (float)round(s.y), 0.0f};
	e = (t_v3f){(float)round(e.x), (float)round(e.y), 0.0f};
	if (((int)(s.x) > (int)(e.x)) || ((s.x == e.x) && (s.y > e.y)))
		draw_swap(&s, &e, gr, 3);
	if (((s.x == e.x) && (s.y == e.y)) || (e.x < 0.0f)
		|| ((s.y < 0.0f) && (e.y < 0.0f)) || (s.x >= limit->x)
		|| ((s.y >= limit->y) && (e.y >= limit->y)))
		return (nl);
	if (e.y < s.y)
		nl.vy = draw_clip_neg(&s, &e, &(nl.d), limit);
	else
		nl.vy = draw_clip_pos(&s, &e, &(nl.d), limit);
	draw_swap(&s, &e, gr, ((nl.d.x == 0) || (nl.d.y == 0)) ? 1 : 0);
	nl.d.y = (nl.d.y < 0) ? -nl.d.y : nl.d.y;
	nl.from = (t_v2ui){(unsigned int)(round(s.x)), (unsigned int)(round(s.y))};
	nl.to = (t_v2ui){(unsigned int)(round(e.x)), (unsigned int)(round(e.y))};
	if ((nl.from.x >= limit->x) || (nl.from.y >= limit->y)
		|| (nl.to.x >= limit->x) || (nl.to.y >= limit->y))
		nl.vy = 0;
	return (nl);
}

static void		draw_2d_line(t_cvs *cvs, t_2dl *l)
{
	const t_ui			end = l->to.x;
	register int		c;
	t_v2ui				p;

	p = l->from;
	c = -l->d.x;
	while (p.x != end)
	{
		c += l->d.y;
		if (c <= 0)
			draw_px(&(cvs->render_buffer), &p, (t_ui *)&(cvs->color));
		else
		{
			while (c > 0)
			{
				draw_px(&(cvs->render_buffer), &p, (t_ui *)&(cvs->color));
				c -= l->d.x;
				if (p.y || (l->vy > 0))
					p.y += l->vy;
			}
		}
		++p.x;
	}
	draw_px(&(cvs->render_buffer), &p, (t_ui *)&(cvs->color));
}

static void		draw_2dgrad_line(t_cvs *cvs, t_2dl *l)
{
	const t_ui			end = l->to.x;
	register int		c;
	t_v2ui				p;

	p = l->from;
	c = -(l->d.x) >> 1;
	while (p.x != end)
	{
		c += l->d.y;
		if (c <= 0)
			draw_grad_px(&(cvs->render_buffer), &p, &draw_autocol);
		else
		{
			while (c > 0)
			{
				draw_grad_px(&(cvs->render_buffer), &p, &draw_autocol);
				c -= l->d.x;
				if (p.y || (l->vy > 0))
					p.y += l->vy;
			}
		}
		++p.x;
	}
	draw_grad_px(&(cvs->render_buffer), &p, &draw_autocol);
}

void			draw_line(t_cvs *cvs, t_2dl *l)
{
	if (l->vy == 0)
		return ;
	if (!(l->d.y))
		draw_px_line(&(cvs->render_buffer), &(l->from),
			(t_ui)(l->d.x), (t_ui *)&(cvs->color));
	else if (!(l->d.x))
	{
		if (l->vy > 0)
			draw_px_column(&(cvs->render_buffer), &(l->from),
				(t_ui)(l->d.y), (t_ui *)&(cvs->color));
		else
			draw_px_column(&(cvs->render_buffer), &(l->to),
				(t_ui)(l->d.y), (t_ui *)&(cvs->color));
	}
	else
		draw_2d_line(cvs, l);
}

void			draw_grad_line(t_cvs *cvs, t_2dl *l, t_gradient *gr)
{
	draw_autocol(gr);
	if (l->vy == 0)
		return ;
	if (!(l->d.y))
		draw_grad_hl(&(cvs->render_buffer), &(l->from),
			(t_ui)(l->d.x), &draw_autocol);
	else if (!(l->d.x))
	{
		if (l->vy > 0)
			draw_grad_vl(&(cvs->render_buffer), &(l->from),
				(t_ui)(l->d.y), &draw_autocol);
		else
			draw_grad_vl(&(cvs->render_buffer), &(l->to),
				(t_ui)(l->d.y), &draw_autocol);
	}
	else
		draw_2dgrad_line(cvs, l);
}
