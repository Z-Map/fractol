/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:59:26 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/30 19:39:03 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_col			*mandlebrot_process(t_frac x, t_frac y, t_frctx *ctx)
{
	t_frac		zr;
	t_frac		zi;
	t_frac		tr;
	t_frac		ti;
	t_ui		i;

	zr = ctx->vmouse.x;
	zi = ctx->vmouse.y;
	i = ctx->mxi;
	while (i)
	{
		tr = zr * zr;
		ti = zi * zi;
		if ((tr + ti) > 4)
			return (&(ctx->ctab[ctx->mxi - i]));
		zi = (2 * zi * zr) + y;
		zr = tr - ti + x;
		i--;
	}
	return (ctx->ctab);
}
