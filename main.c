/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 04:08:52 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 23:23:37 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "fractol.h"

int			frac_quit(void *sys, char *message)
{
	t_frc	*frc;

	ft_putendl(message);
	frc = (t_frc *)sys;
	if (frc->params.flags & MULTITHREAD)
		frac_exit_thread(frc);
	free(frc->mgr->ctab);
	ft_putendl("Free Hud image ...");
	if (frc->hud)
		mlx_destroy_image(frc->sys.mlx, frc->hud);
	return (draw_clean_exit(&(frc->sys), NULL));
}

void		frac_start(t_frc *frc)
{
	t_v2i	size;

	frc->thmgr->quit = 0;
	frc->params.maxiter = 8192;
	frc->active = 0;
	size = (t_v2i){1024, 128};
	frc->hud = mlx_xpm_file_to_image(frc->sys.mlx, "hud.xpm",
		&(size.x), &(size.y));
	frc->hudy = 702;
	frc->ctx.vmouse = (t_vec){0.0, 0.0};
	frac_set(frc, frc->params.ftype);
	*(frc->mgr) = frac_mgr_create(frc);
	if (frc->params.flags & MULTITHREAD)
		frac_init_thread(frc);
	frac_draw(frc);
	draw_hook(&(frc->win), frc->sys.quit, frc, CLOSE);
	draw_hook(&(frc->win), &frac_presskey, frc, KEYDOWN);
	draw_hook(&(frc->win), &frac_releasekey, frc, KEYUP);
	draw_hook(&(frc->win), &frac_mousebutton, frc, MOUSEDOWN);
	draw_hook(&(frc->win), &frac_mouseupbutton, frc, MOUSEUP);
	draw_hook(&(frc->win), &frac_mouse, frc, MOUSEMOVE);
	mlx_expose_hook(frc->win.id, &frac_drawexpose, (void *)(frc));
	mlx_loop_hook(frc->sys.mlx, &frac_mainloop, (void *)(frc));
}

int			main(int argc, char **argv)
{
	t_frc	frc;
	t_thmgr	mgr;

	frc.thmgr = &mgr;
	frc.mgr = &(mgr.mgr);
	if ((frc.hudy = parse_args(&frc, argc, argv)) <= 0)
		return (frc.hudy);
	frc.sys = draw_init();
	frc.sys.quit = &frac_quit;
	frc.texsize = (t_v2ui){1024, 768};
	frc.win = draw_init_win(&(frc.sys), frc.texsize, "~* Fractol *~");
	frac_start(&frc);
	ft_putstr("-- Starting complete --\n");
	mlx_loop(frc.sys.mlx);
	return (0);
}
