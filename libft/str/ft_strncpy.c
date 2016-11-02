/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 01:10:28 by qloubier          #+#    #+#             */
/*   Updated: 2015/12/22 17:07:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*dit;

	dit = dst;
	if (!n)
		return (dst);
	while (n--)
	{
		*(dit++) = *src;
		if (*src)
			src++;
	}
	return (dst);
}
