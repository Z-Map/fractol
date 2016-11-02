/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:27:08 by qloubier          #+#    #+#             */
/*   Updated: 2015/12/22 17:14:57 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = ft_strlen(s2);
	if (!(*s2))
		return ((char *)s1);
	while (*s1 && n-- >= len)
	{
		if (*s1 == *s2 && ft_strncmp(s1 + 1, s2 + 1, len - 1) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
