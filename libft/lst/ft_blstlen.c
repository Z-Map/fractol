/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:54:16 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/27 05:15:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

size_t			ft_blstlen(t_blst *blst)
{
	size_t		i;

	i = 0;
	while (blst)
	{
		i += blst->len;
		blst = blst->next;
	}
	return (i);
}
