/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tov2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 19:49:30 by qloubier          #+#    #+#             */
/*   Updated: 2016/06/26 21:41:12 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_v2d					nv2d(double i)
{
	return ((t_v2d){i, i});
}

t_v2d					v3to2d(t_v3d vec)
{
	return ((t_v2d){vec.x, vec.y});
}

t_v2d					v4to2d(t_v4d vec)
{
	return ((t_v2d){vec.x, vec.y});
}
