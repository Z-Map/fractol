/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:28:01 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/20 02:16:46 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*rlst;

	if (!(rlst = malloc(sizeof(t_list))))
		return (NULL);
	rlst->content = (content) ? ft_memdup(content, content_size) : NULL;
	rlst->content_size = (content) ? content_size : 0;
	rlst->next = NULL;
	return (rlst);
}
