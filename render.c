/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:50:43 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:25:53 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			frac_render(t_frctx *ctx, t_ui cid, t_ui thnum, int *quit)
{
	const t_v2ui	l = ctx->view.ts;
	t_frac			x;
	t_frac			y;
	t_frac			d;
	t_v2ui			p;

	d = ctx->view.d / ctx->view.zoom;
	x = ctx->view.x + (d * cid);
	p = (t_v2ui){cid, 0};
	while ((p.x < l.x) && (!*quit))
	{
		p.y = 0;
		y = ctx->view.y;
		while ((p.y < l.y) && (!*quit))
		{
			draw_px(&(ctx->img.texture_buffer), &p, ctx->process(x, y, ctx));
			y += d;
			p.y++;
		}
		x += d * thnum;
		p.x += thnum;
	}
}
