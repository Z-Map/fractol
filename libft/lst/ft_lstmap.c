/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:00:59 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/20 02:16:46 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;
	t_list *cur;

	if (!lst || !f)
		return (NULL);
	newlst = f(lst);
	cur = newlst;
	while ((lst = lst->next))
	{
		cur->next = f(lst);
		cur = cur->next;
	}
	return (newlst);
}
