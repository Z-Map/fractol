/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 21:18:06 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 23:16:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

void		draw_free_win(void *ptr, size_t s)
{
	t_win	*win;

	win = (t_win *)ptr;
	ft_putstr("Clean window ");
	ft_putnbr(win->draw_id);
	ft_putstr(" - Size : ");
	ft_putnbr((int)s);
	ft_putchar('\n');
	mlx_destroy_window(win->sys->mlx, win->id);
	ft_memdel(&ptr);
}

void		draw_free_cvs(void *ptr, size_t s)
{
	t_cvs	*cvs;

	cvs = (t_cvs *)ptr;
	ft_putstr("Clean canvas ");
	ft_putnbr(cvs->draw_id);
	ft_putstr(" - Size : ");
	ft_putnbr((int)s);
	ft_putchar('\n');
	mlx_destroy_image(cvs->sys->mlx, cvs->render_buffer.id);
	ft_memdel(&ptr);
}

void		draw_free_tex(void *ptr, size_t s)
{
	t_tex	*tex;

	tex = (t_tex *)ptr;
	ft_putstr("Clean texture ");
	ft_putnbr(tex->draw_id);
	ft_putstr(" - Size : ");
	ft_putnbr((int)s);
	ft_putchar('\n');
	mlx_destroy_image(tex->sys->mlx, tex->texture_buffer.id);
	ft_memdel(&ptr);
}
