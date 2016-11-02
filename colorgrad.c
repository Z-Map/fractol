/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorgrad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:49:27 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:40:14 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				rotate_hue(t_col *c, int i)
{
	t_argb			col;

	col = rgb2hsv(toargb(*c));
	col.r += (char)i;
	*c = fromargb(hsv2rgb(col));
}

static t_col		fire_extend_grad(t_cgr *gr, t_ui i, t_ui mxi)
{
	const t_ui		mi = (t_ui)((float)mxi * 0.2581f);
	const t_argb	cv = rgb2hsv(toargb(gr->voidcol));
	const t_argb	ce = rgb2hsv(toargb(gr->end));
	const t_argb	cs = rgb2hsv(toargb(gr->start));
	float			fac;

	if (i < mi)
	{
		fac = (float)i / (float)mi;
		return (fromargb(hsv2rgb(hsv_lerp(cs, ce, fac))));
	}
	fac = (float)(i - mi) / (float)(mxi - mi);
	return (fromargb(hsv2rgb(hsv_lerp(ce, cv, fac))));
}

t_col				fire_grad(t_cgr *gr, t_ui i, t_ui mxi)
{
	const t_argb	cv = rgb2hsv(toargb(gr->voidcol));
	const t_argb	cs = rgb2hsv(toargb(gr->start));
	const t_argb	ce = rgb2hsv(toargb(gr->end));
	const t_argb	cf = (t_argb){0, 0, 0, 255};
	float			factor;

	factor = (float)i / 12.0f;
	if (mxi > 256 && i > 132)
		return (fire_extend_grad(gr, i - 132, mxi - 132));
	else if (i < 12)
		return (fromargb(hsv2rgb(hsv_lerp(cv, ce, factor))));
	else if (i < 40)
		return (fromargb(hsv2rgb(hsv_lerp(ce, cs, (float)(i - 12) / 28.0f))));
	else if (i < 64)
		return (fromargb(hsv2rgb(hsv_lerp(cs, cf, (float)(i - 40) / 24.0f))));
	else if (i < 132)
		return (fromargb(hsv2rgb(hsv_lerp(cf, cs, (float)(i - 64) / 64.0f))));
	else if (i < 164)
		return (fromargb(hsv2rgb(hsv_lerp(cs, ce, (float)(i - 132) / 32.0f))));
	return (fromargb(hsv2rgb(hsv_lerp(ce, cv, (float)(i - 164) / 92.0f))));
}
