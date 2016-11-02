/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gradient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 07:02:12 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/01 18:55:31 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

void		draw_grad_px(t_ibuf *i, t_v2ui *p, t_ui (*c)(void *))
{
	*(t_ui *)(i->image_data
		+ (i->opt.lbs * p->y) + (i->opt.pbw * p->x)) = c(NULL);
}

void		draw_agrad_px(t_ibuf *i, t_v2ui *p, t_ui (*c)(void *))
{
	register unsigned long	col;
	register unsigned int	ac;

	ac = c(NULL);
	col = (long)*(int *)(i->image_data +
		(i->opt.pbw * p->x) + (i->opt.lbs * p->y));
	col = ((((col & 0xFF0000) << 16) |
		((col & 0x00FF00) << 8) |
		(col & 0x000000FF)) *
		(long)((ac & 0xFF000000) >> 24))
		| ((col & 0xFF000000) << 24);
	col = ((((col & 0xFF0000000000) >> 24)
		| ((col & 0xFF000000) >> 16)
		| ((col & 0xFF00) >> 8))
		+ (long)(ac & 0xFFFFFF))
		| ((col & 0xFF00000000000000) >> 24);
	*(int *)((i->image_data) +
		(i->opt.pbw * p->x) + (i->opt.lbs * p->y)) = (int)col;
}

void		draw_grad_hl(t_ibuf *i, t_v2ui *p, t_ui n, t_ui (*c)(void *))
{
	while (n-- > 0)
		*(t_ui *)(i->image_data +
			(i->opt.lbs * p->y) +
			(i->opt.pbw * (p->x + n))) = c(NULL);
}

void		draw_grad_vl(t_ibuf *i, t_v2ui *p, t_ui n, t_ui (*c)(void *))
{
	while (n-- > 0)
		*(t_ui *)(i->image_data +
			(i->opt.lbs * (p->y + n)) +
			(i->opt.pbw * p->x)) = c(NULL);
}
