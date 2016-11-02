/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 01:09:20 by qloubier          #+#    #+#             */
/*   Updated: 2015/12/02 01:17:00 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ns;
	size_t	i;

	ns = NULL;
	i = 0;
	if (!s || !f)
		return (NULL);
	ns = ft_strnew(ft_strlen(s));
	if (!ns)
		return (NULL);
	while (*s)
		ns[i++] = f(*(s++));
	return (ns);
}
