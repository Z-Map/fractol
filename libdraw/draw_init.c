/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 19:32:30 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/29 20:53:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

t_dsys			draw_init(void)
{
	t_dsys	draw_system;

	draw_system.mlx = mlx_init();
	draw_system.win_lst = NULL;
	draw_system.cvs_lst = NULL;
	draw_system.tex_lst = NULL;
	draw_system.win_id = 0;
	draw_system.cvs_id = 0;
	draw_system.tex_id = 0;
	draw_system.quit = &draw_clean_exit;
	return (draw_system);
}

t_win			draw_init_win(t_dsys *sys, t_v2ui size, char *name)
{
	t_win	new_window;

	new_window.sys = sys;
	new_window.size = size;
	new_window.id = mlx_new_window(sys->mlx, size.x, size.y, name);
	mlx_clear_window(sys->mlx, new_window.id);
	new_window.buffer = draw_init_cvs(sys, size);
	mlx_put_image_to_window(sys->mlx,
		new_window.id,
		new_window.buffer.render_buffer.id,
		0, 0);
	new_window.draw_id = ++(sys->win_id);
	ft_lstpush(&(sys->win_lst), ft_lstnew(&new_window, sizeof(new_window)));
	return (new_window);
}

static t_ibuf	draw_init_image_buffer(t_dsys *sys, t_v2ui size, t_ibflag flag)
{
	t_ibuf	new_ibuf;

	new_ibuf.sys = sys;
	new_ibuf.size = size;
	new_ibuf.id = mlx_new_image(sys->mlx, (int)size.x, (int)size.y);
	new_ibuf.opt = (t_ibset){ 0, 0, 0, 0, 0, flag };
	new_ibuf.image_data = (t_uc *)mlx_get_data_addr(
			new_ibuf.id,
			&(new_ibuf.opt.bpp),
			&(new_ibuf.opt.lbs),
			&(new_ibuf.opt.cbe));
	new_ibuf.opt.pbw = new_ibuf.opt.bpp / 8;
	new_ibuf.opt.ibs = (unsigned int)(new_ibuf.opt.lbs) * size.y;
	return (new_ibuf);
}

t_cvs			draw_init_cvs(t_dsys *sys, t_v2ui size)
{
	t_cvs	new_cvs;

	new_cvs.sys = sys;
	new_cvs.color = draw_cola(0, 0, 0, 255);
	new_cvs.render_buffer = draw_init_image_buffer(sys, size, FRAME_BUFFER);
	draw_clear_cvs(&new_cvs);
	new_cvs.modelview = mattf_identity();
	new_cvs.winmat = mattf_identity();
	new_cvs.projection = mattf_identity();
	new_cvs.mt_camera = mattf_identity();
	new_cvs.mt_object = mattf_identity();
	new_cvs.transform = mattf_identity();
	new_cvs.draw_id = ++(sys->cvs_id);
	ft_lstpush(&(sys->cvs_lst), ft_lstnew(&new_cvs, sizeof(new_cvs)));
	return (new_cvs);
}

t_tex			draw_init_tex(t_dsys *sys, t_v2ui size)
{
	t_tex	new_tex;

	new_tex.sys = sys;
	size.x = bitceil(size.x - 1) + 1;
	size.y = bitceil(size.y - 1) + 1;
	new_tex.size = size;
	new_tex.texture_buffer = draw_init_image_buffer(sys, size, TEXTURE_BUFFER);
	new_tex.draw_id = ++(sys->tex_id);
	ft_lstpush(&(sys->tex_lst), ft_lstnew(&new_tex, sizeof(new_tex)));
	return (new_tex);
}
