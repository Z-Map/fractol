/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 02:27:34 by qloubier          #+#    #+#             */
/*   Updated: 2016/06/26 21:46:02 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_v2f					normalize2f(t_v2f v)
{
	const float		nor = sqrtf((v.x * v.x) + (v.y * v.y));

	return ((t_v2f){v.x / nor, v.y / nor});
}

t_v3f					normalize3f(t_v3f v)
{
	const float		nor = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

	return ((t_v3f){v.x / nor, v.y / nor, v.z / nor});
}

t_v2d					normalize2d(t_v2d v)
{
	const double	nor = sqrt((v.x * v.x) + (v.y * v.y));

	return ((t_v2d){v.x / nor, v.y / nor});
}

t_v3d					normalize3d(t_v3d v)
{
	const double	nor = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

	return ((t_v3d){v.x / nor, v.y / nor, v.z / nor});
}
