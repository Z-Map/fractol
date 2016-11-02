/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 20:06:58 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:51:46 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"
#include <stdio.h>

t_col			draw_col(t_uc r, t_uc g, t_uc b)
{
	return ((t_col)((r << 16) | (g << 8) | b));
}

t_cola			draw_cola(t_uc r, t_uc g, t_uc b, t_uc a)
{
	return ((t_cola)(((255 - a) << 24) | (r << 16) | (g << 8) | b));
}

unsigned int	draw_lerp_col(t_col *col, t_col *col2, unsigned char fac)
{
	int		r;
	int		g;
	int		b;

	if (!fac)
		return (*col);
	else if (fac == 255)
		return (*col2);
	r = ((((*col & 0xFF0000) >> 16) * (255 - fac)) >> 8)
		+ ((((*col2 & 0xFF0000) >> 16) * fac) >> 8);
	g = ((((*col & 0x00FF00) >> 8) * (255 - fac)) >> 8)
		+ ((((*col2 & 0x00FF00) >> 8) * fac) >> 8);
	b = (((*col & 0x0000FF) * (255 - fac)) >> 8)
		+ (((*col2 & 0x0000FF) * fac) >> 8);
	return ((r << 16) | (g << 8) | b);
}

unsigned int	draw_autocol(void *param)
{
	static t_gradient	gr;
	unsigned int		col;

	col = 0;
	if (param)
		gr = *((t_gradient *)param);
	else if (gr.ic)
	{
		col = draw_col(
			((((gr.s >> 16) & 0xFF) * gr.ic) + (((gr.e >> 16) & 0xFF) * gr.c))
			/ gr.step,
			((((gr.s >> 8) & 0xFF) * gr.ic) + (((gr.e >> 8) & 0xFF) * gr.c))
			/ gr.step,
			(((gr.s & 0xFF) * gr.ic) + ((gr.e & 0xFF) * gr.c))
			/ gr.step);
		gr.ic--;
		gr.c++;
	}
	else
		col = gr.e;
	return (col);
}
