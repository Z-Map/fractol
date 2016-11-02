/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_expose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:43:25 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:38:19 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "fractol.h"

void			frac_drawhud(t_frc *frc)
{
	if ((frc->hudy < 700) && (frc->params.flags & HIDE_HUD))
		frc->hudy += 6;
	else if (frc->params.flags & HIDE_HUD)
	{
		frc->hudy = 702;
		frc->ctx.activekey &= ~K_HUDREFRESH;
	}
	else if ((frc->hudy > 642) && !(frc->params.flags & HIDE_HUD))
		frc->hudy -= 6;
	else
	{
		frc->hudy = 640;
		frc->ctx.activekey &= ~K_HUDREFRESH;
	}
	if (frc->hud)
		mlx_put_image_to_window(frc->sys.mlx, frc->win.id, frc->hud,
			0, frc->hudy);
}

int				frac_drawexpose(void *arg)
{
	t_frc		*frc;
	t_cvs		*cvs;
	t_tex		tex;

	frc = (t_frc *)arg;
	if (frc->ctx.activekey & (K_NEEDREFRESH | K_HUDREFRESH))
	{
		cvs = &(frc->win.buffer);
		tex = frc->ctx.img;
		cvs->color = frc->mgr->ctab[1];
		draw_clear_cvs(cvs);
		draw_tex_to_cvs(cvs, &tex, frc->texoffset, (float)frc->texzoom);
		draw_cvs_to_win(&(frc->win), cvs, 0, 0);
		frac_drawhud(frc);
		frc->ctx.activekey &= ~K_NEEDREFRESH;
	}
	return (1);
}
