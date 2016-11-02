/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 18:14:48 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/27 05:19:25 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

t_blst		*ft_blstnew(size_t csize, size_t bsize)
{
	t_blst	*ret;

	if (!csize || !bsize
		|| !(ret = (t_blst *)malloc(sizeof(t_blst) + (csize * bsize))))
		return (NULL);
	*ret = (t_blst){csize, bsize, 0, (void *)ret + sizeof(t_blst), NULL};
	return (ret);
}
