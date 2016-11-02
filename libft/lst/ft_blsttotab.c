/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blsttotab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:58:15 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/27 05:34:39 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

void		*ft_blsttotab(t_blst *blst, size_t *len)
{
	char	*tab;
	size_t	i;

	if (!blst || !(tab = (char *)malloc(blst->csize * ft_blstlen(blst))))
		return (NULL);
	*len = 0;
	i = 0;
	while (blst)
	{
		ft_memcpy(tab + i, blst->data, blst->len * blst->csize);
		*len += blst->len;
		i += blst->len * blst->csize;
		blst = blst->next;
	}
	return (tab);
}
