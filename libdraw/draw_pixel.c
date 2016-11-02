/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 07:02:12 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:52:03 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

t_col		draw_getpx(t_ibuf *i, t_ui x, t_ui y)
{
	return (*(t_ui *)(i->image_data + (i->opt.lbs * y) + (i->opt.pbw * x)));
}

void		draw_px(t_ibuf *i, t_v2ui *p, t_ui *c)
{
	*(t_col *)(i->image_data + (i->opt.lbs * p->y) + (i->opt.pbw * p->x)) = *c;
}

void		draw_pxc(t_ibuf *i, t_v2ui p, t_ui c)
{
	*(t_col *)(i->image_data + (i->opt.lbs * p.y) + (i->opt.pbw * p.x)) = c;
}

void		draw_px_line(t_ibuf *i, t_v2ui *p, t_ui num, t_ui *c)
{
	while (num-- > 0)
		*(t_ui *)(i->image_data +
			(i->opt.lbs * p->y) +
			(i->opt.pbw * (p->x + num))) = *c;
}

void		draw_px_column(t_ibuf *i, t_v2ui *p, t_ui num, t_ui *c)
{
	while (num-- > 0)
		*(t_ui *)(i->image_data +
			(i->opt.lbs * (p->y + num)) +
			(i->opt.pbw * p->x)) = *c;
}
