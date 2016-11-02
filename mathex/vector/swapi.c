/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 03:58:15 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/28 04:42:41 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			swapv2i(t_v2i *a, t_v2i *b)
{
	t_v2i	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			swapv3i(t_v3i *a, t_v3i *b)
{
	t_v3i	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			swapv4i(t_v4i *a, t_v4i *b)
{
	t_v4i	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
