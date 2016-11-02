/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorgen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:49:27 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:40:21 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fractol.h"

t_col			basic_grad(t_cgr *gr, t_ui i, t_ui mxi)
{
	const t_uc	factor = (unsigned char)(((float)i / (float)mxi) * 255.0f);

	if (gr->mode == UNICOLOR)
		return (draw_lerp_col(&(gr->voidcol), &(gr->start), factor));
	else
		return (draw_lerp_col(&(gr->end), &(gr->start), factor));
}

t_col			hue_grad(t_cgr *gr, t_ui i, t_ui mxi)
{
	const t_ui	mi = 12;
	const int	m = (gr->mode == HUETRIGRAD || gr->mode == HSGRAD) ? 1 : 0;
	float		factor;
	t_col		cs;
	t_col		ce;

	cs = (gr->mode == HSGRAD) ? 64 : mxi;
	factor = (float)((m) ? i - mi : i) / (float)((m) ? (int)cs - mi : mxi);
	cs = fromargb(rgb2hsv(toargb(gr->start)));
	ce = fromargb(rgb2hsv(toargb(gr->end)));
	if (m && (i < mi))
	{
		factor = (float)i / (float)mi;
		cs = fromargb(rgb2hsv(toargb(gr->voidcol)));
		cs = fromargb(hsv_lerp(toargb(cs), toargb(ce), factor));
	}
	else if ((gr->mode == HSGRAD) && (i > 64))
		return (static_saturation_grad(gr, i, mxi));
	else
		cs = fromargb(hsv_lerp(toargb(ce), toargb(cs), factor));
	ce = fromargb(hsv2rgb(toargb(cs)));
	return (ce);
}

t_col			static_saturation_grad(t_cgr *gr, t_ui i, t_ui mxi)
{
	const float	fac = (float)(i % 32) / 32.0f;
	t_uc		rot;
	t_col		cs;
	t_col		ce;

	(void)mxi;
	rot = i / 64;
	cs = fromargb(rgb2hsv(toargb(gr->start)));
	cs = (((i < 128) ? i * 2 : 255) << 8) | (cs & 0xFFFF00FF);
	ce = fromargb(rgb2hsv(toargb(gr->end)));
	ce = (((i < 128) ? i * 2 : 255) << 8) | (ce & 0xFFFF00FF);
	cs = (((toargb(cs).r + (rot * 37)) & 0xFF) << 16) | (cs & 0xFF00FFFF);
	if ((i / 32) & 1)
	{
		++rot;
		ce = (((toargb(ce).r + (rot * 37)) & 0xFF) << 16) | (ce & 0xFF00FFFF);
		cs = fromargb(hsv_lerp(toargb(cs), toargb(ce), fac));
	}
	else
	{
		ce = (((toargb(ce).r + (rot * 37)) & 0xFF) << 16) | (ce & 0xFF00FFFF);
		cs = fromargb(hsv_lerp(toargb(ce), toargb(cs), fac));
	}
	ce = fromargb(hsv2rgb(toargb(cs)));
	return (ce);
}

t_col			static_grad(t_cgr *gr, t_ui i, t_ui mxi)
{
	const float	fac = (float)(i % 32) / 32.0f;
	t_uc		rot;
	t_col		cs;
	t_col		ce;

	(void)mxi;
	rot = i / 64;
	cs = fromargb(rgb2hsv(toargb(gr->start)));
	cs = ((i < 128) ? i * 2 : 255) | (cs & 0xFFFFFF00);
	ce = fromargb(rgb2hsv(toargb(gr->end)));
	ce = ((i < 128) ? i * 2 : 255) | (ce & 0xFFFFFF00);
	cs = (((toargb(cs).r + (rot * 37)) & 0xFF) << 16) | (cs & 0xFF00FFFF);
	if ((i / 32) & 1)
	{
		++rot;
		ce = (((toargb(ce).r + (rot * 37)) & 0xFF) << 16) | (ce & 0xFF00FFFF);
		cs = fromargb(hsv_lerp(toargb(cs), toargb(ce), fac));
	}
	else
	{
		ce = (((toargb(ce).r + (rot * 37)) & 0xFF) << 16) | (ce & 0xFF00FFFF);
		cs = fromargb(hsv_lerp(toargb(ce), toargb(cs), fac));
	}
	ce = fromargb(hsv2rgb(toargb(cs)));
	return (ce);
}

t_ui			gen_ctab(t_frmgr *mgr, t_ui mxi)
{
	const void	*ftab[] = {&basic_grad, &basic_grad, &hue_grad, &static_grad,
					&static_saturation_grad, &hue_grad, &hue_grad, &fire_grad};
	t_col		*ctab;
	t_ui		i;

	if (mxi == mgr->mxi && !(mgr->activekey & K_REFCOL))
		return (mxi);
	if (!(ctab = (t_col *)malloc(sizeof(t_col) * (mxi + 1))))
		return (mgr->mxi);
	if (mgr->ctab)
		free(mgr->ctab);
	mgr->ctab = ctab;
	mgr->ctab[0] = mgr->gradient.voidcol;
	i = 0;
	while (++i <= mxi)
		ctab[i] = ((t_col (**)(t_cgr *, t_ui, t_ui))ftab)[mgr->gradient.mode](
			&(mgr->gradient), i, mxi);
	return (mxi);
}
