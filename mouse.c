/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 19:28:27 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:26:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_frc	*valid_mousepos(int *x, int *y, void *param, int ignore)
{
	t_frc			*frc;
	int				m;

	frc = (t_frc *)param;
	m = 1;
	if ((*x < 0) || (*x > (int)frc->texsize.x))
	{
		*x = (*x < 0) ? 0 : (int)frc->texsize.x;
		m = ignore;
	}
	if ((*y < 0) || (*y > (int)frc->texsize.y))
	{
		*y = (*y < 0) ? 0 : (int)frc->texsize.y;
		m = ignore;
	}
	return ((m) ? frc : NULL);
}

int				frac_mouse(int x, int y, void *param)
{
	static t_v3i	mouse = (t_v3i){ 0, 0, 0};
	t_frc			*frc;

	if (mouse.z == 0)
		mouse = (t_v3i){ x, y, 1};
	x -= mouse.x;
	y -= mouse.y;
	mouse.x += x;
	mouse.y += y;
	frc = (t_frc *)param;
	if (frc->params.flags & GRABMODE)
		frac_move_view(frc, frc->ctx.view.zoom,
			(t_v2f){(float)x, (float)y}, nv2f(0.0f));
	else if (frc->params.flags & VMOUSEMODE)
	{
		frc->ctx.vmouse.x += ((t_frac)(x) / 256.0) / (frc->params.vmsens);
		frc->ctx.vmouse.y += ((t_frac)(y) / 256.0) / (frc->params.vmsens);
		frc->ctx.activekey |= K_RENDER;
	}
	else
		return (0);
	frc->ctx.activekey |= K_NEEDREFRESH;
	return (0);
}

t_frac			frac_zoom(t_frc *frc, t_frac zval)
{
	t_frac	zoom;
	t_frac	vmsens;
	int		m;

	m = (zval < 0.0) ? 0 : 1;
	zoom = frc->ctx.view.zoom;
	vmsens = frc->params.vmsens;
	if ((m && (frc->ctx.view.zoom > 862766924468926089.375)) ||
		(!m && (frc->ctx.view.zoom <= frc->params.minzoom)))
		return (zoom);
	zoom *= 1.0f + zval;
	vmsens = zoom * ((frc->params.flags & SHIFT_MODE) ? 30.0 : 1.0);
	if (zoom <= frc->params.minzoom)
		vmsens = (frc->params.flags & SHIFT_MODE) ? 36.0 : 1.2;
	frc->params.vmsens = vmsens;
	return (zoom);
}

int				frac_mouseupbutton(int button, int x, int y, void *param)
{
	t_frc	*frc;

	frc = valid_mousepos(&x, &y, param, 1);
	if (button == LMB_KEY)
		((t_frc *)param)->params.flags &= ~GRABMODE;
	if (frc && (button == RMB_KEY))
		frc->params.flags ^= VMOUSEMODE;
	if (!frc || !(frc->params.flags & DISP_KCODE))
		return (0);
	ft_putstr("Button code :");
	ft_putnbr(button);
	ft_putstr(" at pos :  ");
	ft_putnbr(x);
	ft_putstr(", ");
	ft_putnbr(y);
	ft_putchar('\n');
	return (0);
}

int				frac_mousebutton(int button, int x, int y, void *param)
{
	t_frc	*frc;
	t_frac	zoom;

	if (!(frc = valid_mousepos(&x, &y, param, 0)))
		return (0);
	if (((button == 4) || (button == 5)) && ((zoom = frac_zoom(
		frc, (button == 4) ? 0.2 : -0.2)) != frc->ctx.view.zoom))
		frac_move_view(frc, zoom, nv2f(0.0f), (t_v2f){(float)x, (float)y});
	else if (button == LMB_KEY)
		frc->params.flags |= GRABMODE;
	else
		return (0);
	frc->ctx.activekey |= K_NEEDREFRESH;
	return (0);
}
