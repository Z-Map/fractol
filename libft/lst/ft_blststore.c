/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blststore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 18:39:30 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:47:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void		ft_blststore(t_blst *blst, void *data)
{
	if (!blst || !data)
		return ;
	while (blst->next && (blst->len == blst->bsize))
		blst = blst->next;
	if (blst->len == blst->bsize)
	{
		blst->next = ft_blstnew(blst->csize, blst->bsize);
		blst = blst->next;
	}
	ft_memcpy(blst->data + (blst->len * blst->csize), data, blst->csize);
	blst->len += 1;
}
