/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 18:26:37 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:39:51 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				get_hexchar(char c)
{
	if (c >= 0 && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (10 + (c - 'a'));
	else if (c >= 'A' && c <= 'F')
		return (10 + (c - 'A'));
	return (-1);
}

t_col			get_col(const char *c)
{
	t_col		col;

	if (*c == '=')
		++c;
	if (!ft_strncmp(c, "0x", 2))
		c += 2;
	col = 0;
	while (*c && (get_hexchar(*c) >= 0))
		col = (col * 16) + get_hexchar(*(c++));
	return (col & 0xFFFFFF);
}

void			parse_col(t_frc *frc, const char *arg)
{
	t_col		col;

	if ((frc->params.flags & COLSET) && !(frc->params.flags & DUALCOLSET))
	{
		frc->params.gradient.end = frc->params.gradient.start;
		frc->params.flags |= DUALCOLSET;
		if (frc->params.gradient.mode == NOTSET)
			frc->params.gradient.mode = DUALCOLOR;
	}
	col = 0;
	while (*arg && (get_hexchar(*arg) >= 0))
		col = (col * 16) + get_hexchar(*(arg++));
	frc->params.gradient.start = col & 0xFFFFFF;
	frc->params.flags |= COLSET;
	if (frc->params.gradient.mode == NOTSET)
		frc->params.gradient.mode = UNICOLOR;
}
