/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:24:57 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/20 02:16:46 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

size_t		ft_lstlen(t_list *lst)
{
	size_t len;

	if (!lst)
		return (0);
	len = 1;
	while ((lst = lst->next))
		++len;
	return (len);
}
