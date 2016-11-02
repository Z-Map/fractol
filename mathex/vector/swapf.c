/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 22:18:09 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/21 22:20:51 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			swapv2f(t_v2f *a, t_v2f *b)
{
	t_v2f	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			swapv3f(t_v3f *a, t_v3f *b)
{
	t_v3f	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			swapv4f(t_v4f *a, t_v4f *b)
{
	t_v4f	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
