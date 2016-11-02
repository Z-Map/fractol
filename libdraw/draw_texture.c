/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:22:10 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:52:39 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libdraw.h"
#include "basic.h"

t_col			draw_gettexel(t_tex *tex, t_v2f *p)
{
	return (draw_getpx(&(tex->texture_buffer), (t_ui)p->x, (t_ui)p->y));
}

static int		assert_param(t_v2f *p, t_v4ui *a, t_tex *tex, float zoom)
{
	t_v2f		v;
	t_v2ui		b;

	v = (t_v2f){((float)(tex->size.x) - p->x) * zoom,
				((float)(tex->size.y) - p->y) * zoom};
	if (v.x <= 0.0)
		b.x = 0;
	else
		b.x = a->x + (t_ui)(v.x);
	if (v.y <= 0.0)
		b.y = 0;
	else
		b.y = a->y + (t_ui)(v.y);
	if (!(b.x | b.y))
		return (0);
	a->z = mxminu(b.x, a->z);
	a->w = mxminu(b.y, a->w);
	return (1);
}

void			draw_tex_to_cvs(t_cvs *cvs, t_tex *tex, t_v2f p, float zoom)
{
	t_v4ui		a;
	t_v2ui		v;
	t_v2f		d;

	a = (t_v4ui){(p.x > 0.0) ? (t_ui)round(p.x) : 0,
		(p.y > 0.0) ? (t_ui)round(p.y) : 0,
		cvs->render_buffer.size.x, cvs->render_buffer.size.y};
	d = (t_v2f){1.0f / zoom, (p.x < 0.0) ? -p.x / zoom : 0.0f};
	p = (t_v2f){d.y, (p.y < 0.0) ? -p.y / zoom : 0.0f};
	if (!assert_param(&p, &a, tex, zoom))
		return ;
	v.y = a.y;
	while (v.y < a.w)
	{
		v.x = a.x;
		p.x = d.y;
		while (v.x < a.z)
		{
			draw_pxc(&(cvs->render_buffer), v, draw_gettexel(tex, &p));
			p.x += d.x;
			v.x++;
		}
		p.y += d.x;
		v.y++;
	}
}

void			draw_clear_tex(t_tex *tex, t_col c)
{
	unsigned long	col;
	unsigned int	i;
	const t_ibuf	*ib = &(tex->texture_buffer);

	col = (unsigned long)c | ((unsigned long)c << 32);
	i = 0;
	*(unsigned long *)(ib->image_data) = col;
	while ((i += 8) < ib->opt.ibs)
		*(unsigned long *)(ib->image_data + i) = col;
}
