/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptabdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 13:02:07 by qloubier          #+#    #+#             */
/*   Updated: 2015/12/22 14:13:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include <stdlib.h>

void	ft_ptabdel(void ***tptr)
{
	void	**tmpptr;

	if (!tptr || !(*tptr))
		return ;
	tmpptr = *tptr;
	while (*tmpptr)
		free(*(tmpptr++));
	free(*tptr);
	*tptr = NULL;
}
