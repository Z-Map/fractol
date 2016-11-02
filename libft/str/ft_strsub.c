/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 01:47:39 by qloubier          #+#    #+#             */
/*   Updated: 2015/12/22 15:22:45 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *nstr;

	if (!s)
		return (NULL);
	while (start && *(s++))
		start--;
	if (start || ft_strlen(s) < len)
		return (NULL);
	if ((nstr = ft_strnew(len)))
		ft_strncpy(nstr, s, len);
	return (nstr);
}
