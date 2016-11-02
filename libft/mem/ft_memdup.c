/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 22:05:26 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/20 02:18:30 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	*ft_memdup(const void *s1, size_t n)
{
	void	*rmem;

	if (!n)
		return (NULL);
	rmem = ft_memalloc(n);
	if (rmem)
		ft_memcpy(rmem, s1, n);
	return (rmem);
}
