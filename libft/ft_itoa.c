/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 05:22:56 by qloubier          #+#    #+#             */
/*   Updated: 2015/12/18 14:38:38 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	absn;
	size_t			len;
	char			*buf;

	len = (n < 0) ? 2 : 1;
	absn = (n < 0) ? -1 * n : n;
	while ((absn /= 10))
		len++;
	buf = ft_strnew(len--);
	if (!buf)
		return (NULL);
	*buf = '-';
	absn = (n < 0) ? -1 * n : n;
	buf[len--] = '0' + (char)(absn % 10);
	while ((absn /= 10))
		buf[len--] = '0' + (char)(absn % 10);
	return (buf);
}
