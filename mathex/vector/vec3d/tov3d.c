/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tov3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 01:29:16 by qloubier          #+#    #+#             */
/*   Updated: 2016/06/26 21:42:03 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_v3d					nv3d(double i)
{
	return ((t_v3d){i, i, i});
}

t_v3d					v2to3d(t_v2d vec)
{
	return ((t_v3d){vec.x, vec.y, 0.0});
}

t_v3d					v4to3d(t_v4d vec)
{
	return ((t_v3d){vec.x, vec.y, vec.z});
}
