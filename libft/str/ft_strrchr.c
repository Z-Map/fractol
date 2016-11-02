/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:03:52 by qloubier          #+#    #+#             */
/*   Updated: 2015/12/18 20:41:36 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*as;

	as = (char *)s;
	while (*as)
		(as++);
	while (as >= s)
	{
		if (*as == (char)c)
			return (as);
		as--;
	}
	return (NULL);
}
