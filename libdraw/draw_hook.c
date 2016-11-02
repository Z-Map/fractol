/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 04:36:41 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/30 06:14:18 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

void	draw_hook(t_win *w, int (*f)(), void *ud, const enum e_hook hook)
{
	int		lnx;

	if (hook == KEYDOWN)
		lnx = 1;
	else if (hook == KEYUP)
		lnx = 2;
	else if (hook == MOUSEDOWN || hook == MOUSEUP)
		lnx = 0xf;
	else if (hook == MOUSEMOVE)
		lnx = (1 << 6);
	else
		lnx = 0;
	mlx_hook(w->id, hook, lnx, f, ud);
}
