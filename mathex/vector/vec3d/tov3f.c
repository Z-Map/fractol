/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tov3f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 01:29:16 by qloubier          #+#    #+#             */
/*   Updated: 2016/02/21 01:33:48 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_v3f					nv3f(float i)
{
	return ((t_v3f){i, i, i});
}

t_v3f					v2to3f(t_v2f vec)
{
	return ((t_v3f){vec.x, vec.y, 0.0f});
}

t_v3f					v4to3f(t_v4f vec)
{
	return ((t_v3f){vec.x, vec.y, vec.z});
}
