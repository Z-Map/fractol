/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 21:40:08 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:23:27 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_frmgr			frac_mgr_create(t_frc *frc)
{
	t_frmgr		ret;
	int			i;

	ret.activetex = 0;
	ret.drawtex = 0;
	ret.activekey = NOKEY;
	i = 0;
	ret.ctab = NULL;
	ret.gradient = frc->params.gradient;
	ret.mxi = 0;
	ret.mxi = gen_ctab(&ret, frc->ctx.mxi);
	ret.process = frc->ctx.process;
	ret.vmouse = frc->ctx.vmouse;
	while (i < TEXNUM)
	{
		ret.textures[i] = draw_init_tex(&(frc->sys), frc->texsize);
		ret.textures[i].size = frc->texsize;
		draw_clear_tex(&(ret.textures[i]), ret.ctab[1]);
		ret.texview[i++] = frac_init_view(frc->params.ftype, frc->texsize);
	}
	return (ret);
}

int				frac_mgr_render_request(t_frctx *newctx, t_frmgr *mgr)
{
	if ((newctx->mxi == mgr->mxi) && !(newctx->activekey & K_RENDER))
		return (0);
	mgr->mxi = gen_ctab(mgr, newctx->mxi);
	newctx->activekey = (newctx->activekey & (~K_RENDER)) | K_REFRESH;
	mgr->activekey = newctx->activekey;
	if (++mgr->drawtex >= TEXNUM)
		mgr->drawtex = 0;
	mgr->texview[mgr->drawtex] = newctx->view;
	mgr->process = newctx->process;
	mgr->vmouse = newctx->vmouse;
	return (1);
}
