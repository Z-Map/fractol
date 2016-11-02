/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:43:25 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:31:33 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "fractol.h"

void			frac_set(t_frc *frc, t_frt type)
{
	const void	*frac_proc[] = {&mandlebrot_process, &julia_process,
		&burningship_process, &x_process, &custom_process, &circle_process,
		&cube_process, &multibrot_process};

	frc->ctx.process = (t_col *(*)(t_frac, t_frac, t_frctx *))(
		frac_proc[type]);
	if (type == FRAC_JULIA)
		frc->params.flags |= VMOUSEMODE;
	else
		frc->params.flags &= ~VMOUSEMODE;
	frc->params.ftype = type;
	frac_reset(frc);
}

void			frac_reset(t_frc *frc)
{
	frc->ctx.mxi = 64;
	frc->params.minzoom = MINZOOM;
	frc->ctx.vmouse = (t_vec){0.0, 0.0};
	if (frc->params.ftype == FRAC_LUNA)
		frc->ctx.vmouse = (t_vec){0.005, 0.0};
	if (frc->params.ftype == FRAC_CUSTOM)
		frc->ctx.vmouse = (t_vec){-4.5, 3.2};
	frc->texzoom = MINZOOM;
	frc->params.vmsens = 1.2;
	frc->texoffset = (t_v2f){0.0f, 0.0f};
	frc->ctx.view = frac_init_view(frc->params.ftype, frc->texsize);
	frc->ctx.activekey |= K_NEEDREFRESH | K_RENDER | K_HUDREFRESH;
}

void			frac_moveview(t_frc *frc)
{
	t_v2f		mov;
	t_frac		zoom;

	mov = (t_v2f){0.0f, 0.0f};
	zoom = frc->ctx.view.zoom;
	if (frc->active & KCOLF)
		rotate_hue(&(frc->params.gradient.start), 3);
	if (frc->active & KCOLB)
		rotate_hue(&(frc->params.gradient.end), 3);
	if (frc->active & (K_W | K_S | KUP | KDOWN))
		mov.y = ((frc->active & (K_S | KUP)) ? MOVEVAL : -MOVEVAL);
	if (frc->active & (K_A | K_D | KLEFT | KRIGHT))
		mov.x = ((frc->active & (K_A | KLEFT)) ? MOVEVAL : -MOVEVAL);
	if (frc->active & KZOOM)
		zoom = frac_zoom(frc, ZOOMVAL);
	else if (frc->active & KUNZOOM)
		zoom = frac_zoom(frc, -ZOOMVAL);
	frac_move_view(frc, zoom, mov, (t_v2f){(float)(frc->texsize.x) / 2.0,
		(float)(frc->texsize.y) / 2.0});
	frc->ctx.activekey = frc->active | K_NEEDREFRESH |
		(frc->ctx.activekey & (THREAD_K | K_REFRESHGRADIENT));
}

void			frac_draw(t_frc *frc)
{
	if ((frc->ctx.activekey & K_NEEDREFRESH) &&
		(frc->params.flags & AUTOREFRESH))
		frc->ctx.activekey |= K_RENDER;
	if (frc->params.flags & MULTITHREAD)
		frac_sync_thread(frc);
	else if (frc->thmgr->quit)
		return ;
	else if (frac_mgr_render_request(&(frc->ctx), frc->mgr))
	{
		frac_ctx_update(&(frc->ctx), frc->mgr);
		frc->ctx.img = frc->mgr->textures[frc->mgr->drawtex];
		frac_render(&(frc->ctx), 0, 1, &(frc->thmgr->quit));
		frc->mgr->activetex = frc->mgr->drawtex;
		frc->ctx.activekey &= ~K_REFRESH;
		frc->ctx.activekey |= K_NEEDREFRESH;
		frc->texview = frc->ctx.view;
		frac_view_push(frc);
	}
}

int				frac_mainloop(void *arg)
{
	const struct timespec	t = (struct timespec){0, 12000000L};
	t_frc					*frc;

	frc = (t_frc *)arg;
	if ((frc->active | frc->ctx.activekey) & (~THREAD_K))
		frac_moveview(frc);
	if (!(frc->params.flags & MULTITHREAD))
		frc->mgr->gradient = frc->params.gradient;
	frac_draw(frc);
	frac_drawexpose(frc);
	if ((frc->params.flags & MULTITHREAD) || !(frc->params.flags & AUTOREFRESH))
		nanosleep(&t, NULL);
	return (1);
}
