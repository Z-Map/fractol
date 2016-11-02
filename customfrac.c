/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customfrac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:59:26 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:39:42 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

t_col			*x_process(t_frac x, t_frac y, t_frctx *ctx)
{
	t_frac		zr;
	t_frac		zi;
	t_frac		tr;
	t_frac		ti;
	t_ui		i;

	zr = y;
	zi = x;
	i = ctx->mxi;
	while (i)
	{
		tr = zr * zr;
		ti = zi * zi;
		if ((tr + ti) > 10.0)
			return (&(ctx->ctab[ctx->mxi - i]));
		zr = (tr - ti) - ctx->vmouse.y;
		zi = ((zr) ? zi / zr : 0.0) + ctx->vmouse.x;
		i--;
	}
	return (ctx->ctab);
}

t_col			*cube_process(t_frac x, t_frac y, t_frctx *ctx)
{
	t_frac		zr;
	t_frac		zi;
	t_frac		tr;
	t_frac		ti;
	t_ui		i;

	if ((x > 3.0) || (y > 3.0))
		return (ctx->ctab);
	zr = 3.0 + ctx->vmouse.y;
	zi = 1.0 + ctx->vmouse.x;
	i = ctx->mxi;
	while (i--)
	{
		tr = fmodl(x, zr);
		ti = fmodl(y, zr);
		if ((tr > zi) && (tr < (zi * 2)) && (ti > zi) && (ti < (zi * 2)))
			return (&(ctx->ctab[ctx->mxi - i]));
		zi /= 3.0;
		zr /= 3.0;
		if (zr < (ctx->view.d / ctx->view.zoom))
			break ;
	}
	return (ctx->ctab);
}

t_col			*multibrot_process(t_frac x, t_frac y, t_frctx *ctx)
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
		if ((tr + ti) >= 4)
			return (&(ctx->ctab[ctx->mxi - i]));
		zi = ((3 * tr * zi) - (zi * ti)) + y;
		zr = (tr * zr) - (3 * zr * ti) + x;
		i--;
	}
	return (ctx->ctab);
}

t_col			*circle_process(t_frac x, t_frac y, t_frctx *ctx)
{
	t_frac		zr;
	t_frac		zi;
	t_frac		tr;
	t_frac		ti;
	t_ui		i;

	zr = x;
	zi = y;
	i = ctx->mxi;
	while (i)
	{
		tr = zr * zr;
		ti = zi * zi;
		if (!(tr + ti) || ((tr + ti) > 4.0))
			return (&(ctx->ctab[ctx->mxi - i]));
		zi = (zi / (tr + ti)) + ctx->vmouse.y;
		zr = (zr / (tr + ti)) + ctx->vmouse.x;
		i--;
	}
	return (ctx->ctab);
}

t_col			*custom_process(t_frac x, t_frac y, t_frctx *ctx)
{
	t_frac		zr;
	t_frac		zi;
	t_frac		tr;
	t_frac		ti;
	t_ui		i;

	zr = 0;
	zi = 0;
	i = ctx->mxi;
	while (i)
	{
		tr = zr * zr;
		ti = zi * zi;
		if ((tr + ti) > 4)
		{
			return (&(ctx->ctab[(int)((tr + ti / ctx->vmouse.x) *
				ctx->vmouse.y) % ctx->mxi]));
		}
		zi = (2 * zi * zr) + y;
		zr = tr - ti + x;
		i--;
	}
	return (ctx->ctab);
}
