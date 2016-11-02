/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnequ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 01:37:16 by qloubier          #+#    #+#             */
/*   Updated: 2015/12/18 16:15:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (n && *s1 && (ft_tolower(*s1) == ft_tolower(*s2)))
	{
		s1++;
		s2++;
		n--;
	}
	if (n && ft_tolower(*s1) != ft_tolower(*s2))
		return (0);
	return ((!n || !(*s1)) ? 1 : 0);
}
