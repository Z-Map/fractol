/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:30:04 by qloubier          #+#    #+#             */
/*   Updated: 2015/12/22 14:12:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	bsize;
	char	*nstr;

	bsize = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return (s1 ? ft_strdup(s1) : ft_strdup(s2));
	bsize = ft_strlen(s1) + ft_strlen(s2);
	if ((nstr = ft_strnew(bsize)))
		ft_strcat(ft_strcpy(nstr, s1), s2);
	return (nstr);
}
