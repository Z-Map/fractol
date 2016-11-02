/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 05:39:08 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:38:49 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	frac_keyprocess(int keycode, int state, t_frc *frc)
{
	const int	keys[] = {UP_KEY, DOWN_KEY, LEFT_KEY, RIGHT_KEY, W_KEY, A_KEY,
		S_KEY, D_KEY, PGEUP_KEY, PGEDOWN_KEY, R_KEY, Q_KEY, Z_KEY, X_KEY, -1};
	int			key;
	int			find;

	find = 0;
	key = -1;
	while (keys[++key] >= 0)
	{
		if (keycode == keys[key])
		{
			if (state)
				frc->active |= 1 << key;
			else
				frc->active &= ~(1 << key);
			find = 1;
		}
	}
	return (find);
}

int			frac_frackey(int keycode, t_frc *frc)
{
	const int	keys[] = {UP1_KEY, UP2_KEY, UP3_KEY, UP4_KEY, UP5_KEY, UP6_KEY,
		UP7_KEY, UP8_KEY, UP9_KEY, UP0_KEY};
	int			key;

	key = (frc->params.flags & SHIFT_MODE) ? GRADNUM : FRACNUM;
	while (--key >= 0)
	{
		if (keycode == keys[key])
		{
			if (frc->params.flags & SHIFT_MODE)
			{
				frc->params.gradient.mode = key;
				frc->ctx.activekey |= K_REFRESHGRADIENT;
			}
			else
				frac_set(frc, key);
		}
	}
	return (0);
}

int			frac_releasekey(int keycode, void *frc_context)
{
	t_frc		*frc;

	frc = (t_frc *)frc_context;
	if (keycode == ESC_KEY)
		frc->sys.quit(frc, "Escape pressed");
	else if (keycode == F_KEY)
	{
		frc->params.flags ^= HIDE_HUD;
		frc->ctx.activekey |= K_HUDREFRESH;
	}
	else if (keycode == R_KEY)
		frac_reset(frc);
	else if (keycode == SHIFT_KEY)
	{
		frc->params.flags &= ~SHIFT_MODE;
		frc->params.vmsens /= 30.0;
	}
	else
		frac_keyprocess(keycode, 0, frc);
	if (!(frc->params.flags & DISP_KCODE))
		return (0);
	ft_putstr("Keycode :");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

int			frac_presskey(int keycode, void *frc_context)
{
	t_frc		*frc;

	frc = (t_frc *)frc_context;
	if (keycode == NUM_MORE_KEY)
		up_iteration(frc);
	else if (keycode == NUM_LESS_KEY)
		down_iteration(frc);
	else if (keycode == SHIFT_KEY)
	{
		frc->params.flags |= SHIFT_MODE;
		frc->params.vmsens *= 30.0;
	}
	else if ((keycode != ESC_KEY) && !(frac_keyprocess(keycode, 1, frc)))
		frac_frackey(keycode, frc);
	return (0);
}
