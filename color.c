/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 16:49:06 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:40:26 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_argb			toargb(t_col c)
{
	return ((t_argb){(c >> 24) & 0xFF, (c >> 16) & 0xFF,
		(c >> 8) & 0xFF, c & 0xFF});
}

t_col			fromargb(t_argb c)
{
	return ((t_col)((c.a << 24) | (c.r << 16) | (c.g << 8) | c.b));
}

t_argb			rgb2hsv(t_argb rgb)
{
	t_uc		min;
	t_uc		max;
	t_uc		delta;

	min = mxminu(rgb.r, mxminu(rgb.g, rgb.b));
	max = mxmaxu(rgb.r, mxmaxu(rgb.g, rgb.b));
	delta = max - min;
	if (!delta || !max)
		return ((t_argb){rgb.a, 0, 0, max});
	if (rgb.r == max)
		min = (t_uc)((int)(rgb.g - rgb.b) * 42 / (int)delta);
	else if (rgb.g == max)
		min = (t_uc)((int)(rgb.b - rgb.r) * 42 / (int)delta + 85);
	else
		min = (t_uc)((int)(rgb.r - rgb.g) * 42 / (int)delta + 170);
	return ((t_argb){rgb.a, min, ((int)(delta * 255) / max), max});
}

t_argb			hsv2rgb(t_argb hsv)
{
	const t_uc	delta = (t_uc)((int)(hsv.g * hsv.b) / 255);
	const t_uc	min = hsv.b - delta;
	int			i;

	if ((hsv.r < 43u) || (hsv.r > 212u))
	{
		i = (int)(char)hsv.r * (int)delta / 43;
		return ((t_argb){hsv.a, hsv.b, ((hsv.r < 43) ? i + min : min),
			((hsv.r > 170) ? -i + min : min)});
	}
	else if (hsv.r < 128u)
	{
		i = (int)(char)(hsv.r - 85) * (int)delta / 43;
		return ((t_argb){hsv.a, ((hsv.r < 85) ? -i + min : min), hsv.b,
			((hsv.r > 85) ? i + min : min)});
	}
	else
	{
		i = (int)(char)(hsv.r - 170) * (int)delta / 43;
		return ((t_argb){hsv.a, (hsv.r > 170) ? i + min : min,
			(hsv.r < 170) ? -i + min : min, hsv.b});
	}
}

t_argb			hsv_lerp(t_argb a, t_argb b, float fac)
{
	int			h;

	if (a.g == 0)
		a.r = b.r;
	else if (b.g == 0)
		b.r = a.r;
	if (a.b == 0)
		a.g = b.g;
	else if (b.b == 0)
		b.g = a.g;
	if (fac > 1.0)
		return (b);
	else if (fac < 0.0)
		return (a);
	if (((int)a.r - (int)b.r) > 128)
		h = ((float)a.r * (1.0f - fac)) + (((float)b.r + 255.0f) * fac);
	else if (((int)b.r - (int)a.r) > 128)
		h = (((float)a.r + 255.0f) * (1.0f - fac)) + ((float)b.r * fac);
	else
		h = ((float)a.r * (1.0f - fac)) + ((float)b.r * fac);
	return ((t_argb){
		(t_uc)(((float)a.a * (1.0f - fac)) + ((float)b.a * fac)), (t_uc)(h),
		(t_uc)(((float)a.g * (1.0f - fac)) + ((float)b.g * fac)),
		(t_uc)(((float)a.b * (1.0f - fac)) + ((float)b.b * fac)),
	});
}
