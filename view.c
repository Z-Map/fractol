/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:57:08 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:23:42 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "basic.h"

void			frac_view_push(t_frc *frc)
{
	t_frctx		*c;
	t_frv		view;

	c = &(frc->ctx);
	view = frc->texview;
	frc->texzoom = c->view.zoom / view.zoom;
	frc->texoffset = (t_v2f){
		(float)(c->view.offset.x - (view.offset.x * frc->texzoom)),
		(float)(c->view.offset.y - (view.offset.y * frc->texzoom))};
}

void			frac_move_view(t_frc *frc, t_frac z, t_v2f mov, t_v2f zp)
{
	t_frctx		*c;
	t_frv		*view;
	t_vec		offset;

	c = &(frc->ctx);
	offset.x = c->view.offset.x + (t_frac)mov.x;
	offset.y = c->view.offset.y + (t_frac)mov.y;
	z = (z < frc->params.minzoom) ? frc->params.minzoom : z;
	if (z != c->view.zoom)
	{
		offset.x = ((offset.x - (t_frac)zp.x) / c->view.zoom)
			* z + (t_frac)zp.x;
		offset.y = ((offset.y - (t_frac)zp.y) / c->view.zoom)
			* z + (t_frac)zp.y;
		c->view.zoom = z;
	}
	c->view.offset = offset;
	frac_clip_view(frc);
	view = &(frc->ctx.view);
	view->x = view->sx + ((-(view->offset.x) / view->zoom) * view->d);
	view->y = view->sy + ((-(view->offset.y) / view->zoom) * view->d);
	frac_view_push(frc);
}

void			frac_clip_view(t_frc *frc)
{
	t_vec		limit;

	if (frc->ctx.view.zoom < frc->params.minzoom)
		frc->ctx.view.zoom = frc->params.minzoom;
	limit = (t_vec){-(t_frac)(frc->texsize.x) * (frc->ctx.view.zoom - 1.0),
		-(t_frac)(frc->texsize.y) * (frc->ctx.view.zoom - 1.0)};
	if (frc->ctx.view.offset.x > 0.0)
		frc->ctx.view.offset.x = 0.0;
	if (frc->ctx.view.offset.y > 0.0)
		frc->ctx.view.offset.y = 0.0;
	if (frc->ctx.view.offset.x < limit.x)
		frc->ctx.view.offset.x = limit.x;
	if (frc->ctx.view.offset.y < limit.y)
		frc->ctx.view.offset.y = limit.y;
}

static t_frv	frac_defaultview_ftype(t_frt ftype, t_v2ui ts, t_vec of)
{
	if (ftype == FRAC_MANDLEBROT)
		return ((t_frv){ts, -2.1, -1.2, -2.1, -1.2, 2.9, 2.4, 0.0, 1.0, of});
	else if (ftype == FRAC_MULTIBROT)
		return ((t_frv){ts, -1.5, -1.5, -1.5, -1.5, 3.0, 3.0, 0.0, 1.0, of});
	else if (ftype == FRAC_JULIA)
		return ((t_frv){ts, -2.0, -1.5, -2.0, -1.5, 4.0, 3.0, 0.0, 1.0, of});
	else if (ftype == FRAC_BURNINGSHIP)
		return ((t_frv){ts, -1.0, -2.0, -1.0, -2.0, 3.0, 3.0, 0.0, 1.0, of});
	else if (ftype == FRAC_CUBE)
		return ((t_frv){ts, 0.0, 0.0, 0.0, 0.0, 3.0, 3.0, 0.0, 1.0, of});
	return ((t_frv){ts, -3.0, -3.0, -3.0, -3.0, 6.0, 6.0, 0.0, 1.0, of});
}

t_frv			frac_init_view(t_frt ftype, t_v2ui ts)
{
	t_frv		ret;
	t_vec		offset;
	t_v4f		l;

	offset = (t_vec){(t_frac)0.0, (t_frac)0.0};
	ret = frac_defaultview_ftype(ftype, ts, offset);
	l.x = ((t_frac)(ts.x) / (t_frac)(ts.y)) - (ret.lx / ret.ly);
	l.y = ((t_frac)(ts.y) / (t_frac)(ts.x)) - (ret.ly / ret.lx);
	if (l.x < l.y)
	{
		ret.d = ret.lx / (t_frac)(ts.x);
		ret.sy -= (l.y * ret.ly) / 2;
	}
	else
	{
		ret.d = ret.ly / (t_frac)(ts.y);
		ret.sx -= (l.x * ret.lx) / 2;
	}
	ret.x = ret.sx;
	ret.y = ret.sy;
	return (ret);
}
