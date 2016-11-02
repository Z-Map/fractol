/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:21:59 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/26 19:42:30 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void			*ft_blstiter(t_blit *iterator)
{
	t_blst		*blst;
	size_t		i;

	i = iterator->idx;
	blst = iterator->bloc;
	++iterator->idx;
	if (iterator->idx == blst->len)
	{
		if (!(blst->next))
			return (NULL);
		blst = blst->next;
		iterator->idx = 0;
		iterator->bloc = blst;
	}
	return (blst->data + (blst->csize * i));
}
