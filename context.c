/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 21:19:43 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:39:48 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			frac_ctx_update(t_frctx *ctx, t_frmgr *mgr)
{
	ctx->mxi = mgr->mxi;
	ctx->ctab = mgr->ctab;
	ctx->vmouse = mgr->vmouse;
	ctx->img = mgr->textures[mgr->drawtex];
	ctx->view = mgr->texview[mgr->drawtex];
	ctx->process = mgr->process;
}

void			frac_ctx_sync(t_frctx *ctx, t_frctx *octx)
{
	octx->mxi = ctx->mxi;
	octx->vmouse = ctx->vmouse;
	octx->view = ctx->view;
	octx->process = ctx->process;
}

t_frctx			frac_create_frctx(t_frmgr *mgr)
{
	t_frctx		ret;

	ret.mxi = 0;
	ret.activekey = 0;
	ret.ctab = NULL;
	ret.process = &mandlebrot_process;
	if (mgr)
		frac_ctx_update(&ret, mgr);
	return (ret);
}
