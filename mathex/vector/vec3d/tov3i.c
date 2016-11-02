/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tov3i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 01:39:57 by qloubier          #+#    #+#             */
/*   Updated: 2016/02/21 02:05:27 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_v3i					nv3i(int i)
{
	return ((t_v3i){i, i, i});
}

t_v3i					v2to3i(t_v2i vec)
{
	return ((t_v3i){vec.x, vec.y, 0});
}

t_v3i					v4to3i(t_v4i vec)
{
	return ((t_v3i){vec.x, vec.y, vec.z});
}
