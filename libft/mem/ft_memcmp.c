/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:34:27 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/20 02:18:30 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;
	size_t			i;

	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (--n && b1[i] == b2[i])
		i++;
	return (b1[i] - b2[i]);
}
