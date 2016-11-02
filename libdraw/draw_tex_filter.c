/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex_filter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:16:41 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/26 23:57:14 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libdraw.h"

void		draw_texlerp_filter(t_ibuf *img, t_texfilter *tf, t_tex *tex)
{
	t_v2ui			tmp;
	t_v2ui			cols;
	unsigned char	y;
	t_col			c;

	y = (unsigned char)(((ft->tc.y * (float)tex->size.y)
		- (float)round(ft->tc.y * (float)tex->size.y)) * 255.0f);
	tmp.x = draw_getpx(tex->texture_buffer, tf->ptex.x, tf->ptex.y);
	tmp.y = draw_getpx(tex->texture_buffer, tf->ptex.x, tf->ptex.y + 1);
	clos.x = draw_lerp_col(&(tmp.x), &(tmp.y), y);
	tmp.x = draw_getpx(tex->texture_buffer, tf->ptex.x + 1, tf->ptex.y);
	tmp.y = draw_getpx(tex->texture_buffer, tf->ptex.x + 1, tf->ptex.y + 1);
	clos.y = draw_lerp_col(&(tmp.x), &(tmp.y), y);
	tmp.x = 0;
	tmp.y = (t_ui)(tf->texel.x);
	tmp.y = (tmp.y > tf->p.z) ? tf->p.z : tmp.y;
	while (tf->p.x < tmp.y)
	{
		c = draw_lerp_col(&(cols.x), &(cols.y),
			(unsigned char)round((float)tmp.x * (255.0f / tf->texel->x)));
		draw_px(img, &(tf->p), &c);
		++(tf->p.x);
		++(tmp.x);
	}
	++(tf->ptex.x);
}

void		draw_mipmap_filter(t_ibuf *img, t_texfilter *tf, t_tex *tex)
{
	t_col	c;

	c = draw_getpx(tex->texture_buffer, tf->ptex.x, tf->ptex.y);
	draw_px(img, &(tf->p), &c);
	tf->ptex.x += (t_ui)(1.0f / tf->texel.x);
	if (tf->texel.y < 1.0f)
		tf->ptex.y += (t_ui)(1.0f / tf->texel.y);
}
