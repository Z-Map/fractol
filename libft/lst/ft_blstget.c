/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:07:35 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/26 19:20:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void			*ft_blstget(t_blst *blst, size_t idx)
{
	size_t		bi;

	bi = idx / blst->bsize;
	idx = idx % blst->bsize;
	while (blst->next && bi)
	{
		--bi;
		blst = blst->next;
	}
	if (bi)
		return (NULL);
	return (blst->data + (blst->csize * idx));
}
