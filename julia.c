/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:59:26 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:26:35 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_col			*julia_process(t_frac x, t_frac y, t_frctx *ctx)
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
		if ((tr + ti) > 4)
			return (&(ctx->ctab[ctx->mxi - i]));
		zi = (2 * zi * zr) + ctx->vmouse.x;
		zr = tr - ti + ctx->vmouse.y;
		i--;
	}
	return (ctx->ctab);
}
