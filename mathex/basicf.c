/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 09:54:44 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/25 19:55:36 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic.h"

int			mxabsf(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int			mxmaxf(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

int			mxminf(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

void		swapf(float *a, float *b)
{
	register float	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}
