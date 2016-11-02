/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 13:46:03 by qloubier          #+#    #+#             */
/*   Updated: 2016/01/10 05:59:29 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

size_t	ft_wrdcount(char const *s, int c)
{
	size_t	num;
	char	*cur;

	cur = ft_strchrnot(s, c);
	num = 0;
	while (cur)
	{
		++num;
		if ((cur = ft_strchr(cur, c)))
			cur = ft_strchrnot(cur, c);
	}
	return (num);
}
