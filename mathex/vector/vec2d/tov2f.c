/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tov2f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 19:49:30 by qloubier          #+#    #+#             */
/*   Updated: 2016/02/21 01:33:04 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_v2f					nv2f(float i)
{
	return ((t_v2f){i, i});
}

t_v2f					v3to2f(t_v3f vec)
{
	return ((t_v2f){vec.x, vec.y});
}

t_v2f					v4to2f(t_v4f vec)
{
	return ((t_v2f){vec.x, vec.y});
}
