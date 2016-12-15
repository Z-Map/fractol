/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mglw_window_layer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:59:43 by map               #+#    #+#             */
/*   Updated: 2016/12/15 05:49:40 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern.h"

mgltex		*mglw_get2dlayer(mglwin *win)
{
	if ((win) && (win->data->state & 1) && (win->flags & MGLW_2DLAYER))
		return (win->data->layer2D);
	return (NULL);
}
