/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_canvas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:14:01 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/29 20:52:40 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

void	draw_cvs_to_win(t_win *win, t_cvs *cvs, int x, int y)
{
	mlx_put_image_to_window(win->sys->mlx,
		win->id,
		cvs->render_buffer.id,
		x, y);
}

void	draw_render_matrix(t_cvs *cvs)
{
	t_mattf		m1;

	m1 = cvs->mt_object;
	pmattf_multiply(&m1, &(cvs->mt_rotation));
	pmattf_multiply(&m1, &(cvs->modelview));
	pmattf_multiply(&m1, &(cvs->projection));
	pmattf_multiply(&m1, &(cvs->winmat));
	cvs->transform = m1;
}

void	draw_clear_cvs(t_cvs *cvs)
{
	unsigned long	col;
	unsigned int	i;
	const t_ibuf	*ib = &(cvs->render_buffer);

	i = ((*(unsigned int *)(&(cvs->color))) & 0x00ffffff);
	col = (unsigned long)i | ((unsigned long)i << 32);
	i = 0;
	*(unsigned long *)(ib->image_data) = col;
	while ((i += 8) < cvs->render_buffer.opt.ibs)
		*(unsigned long *)(ib->image_data + i) = col;
}
