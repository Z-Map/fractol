/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:46:18 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/27 01:18:26 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

void			ft_blstfree(t_blst **blst)
{
	t_blst		*blsit;

	while (blst && *blst)
	{
		blsit = (*blst)->next;
		free((void *)(*blst));
		(*blst) = blsit;
	}
	*blst = NULL;
}
