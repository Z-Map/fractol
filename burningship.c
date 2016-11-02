/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:59:26 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:40:29 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_frac	frc_abs(t_frac a)
{
	if (a < 0.0)
		return (-a);
	return (a);
}

t_col			*burningship_process(t_frac x, t_frac y, t_frctx *ctx)
{
	t_frac		zr;
	t_frac		zi;
	t_frac		tr;
	t_frac		ti;
	t_ui		i;

	zr = ctx->vmouse.x;
	zi = ctx->vmouse.y;
	i = ctx->mxi + 1;
	while (--i)
	{
		tr = zr * zr;
		ti = zi * zi;
		if ((tr + ti) > 10)
			return (&(ctx->ctab[ctx->mxi - i]));
		zi = (2 * frc_abs(zi * zr)) + y;
		zr = tr - ti - x;
	}
	return (ctx->ctab);
}
