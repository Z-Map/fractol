/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 19:27:29 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/21 16:15:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	if (*alst)
		ft_lstlast(*alst)->next = new;
	else
		*alst = new;
}
