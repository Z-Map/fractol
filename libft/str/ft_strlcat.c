/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:27:19 by qloubier          #+#    #+#             */
/*   Updated: 2015/12/22 17:12:59 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(dst);
	i = len;
	if (len >= size)
		len = size;
	len += ft_strlen(src);
	while (*src && i < (size - 1))
		dst[i++] = *(src++);
	if (i < size)
		dst[i] = '\0';
	return (len);
}
