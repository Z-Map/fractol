/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vulkan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 01:31:48 by map               #+#    #+#             */
/*   Updated: 2016/12/21 15:34:27 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern/mglw_ogl3tools.h"
#include "mglw_intern/window.h"

int			MGLWopener_vulkan(mglwin *win, int x, int y, const char *title)
{
	(void)win;
	(void)x;
	(void)y;
	(void)title;
	return (0);
}

void		MGLWclearer_vulkan(mglwin *win)
{
	(void)win;
}

void		MGLWimagedraw_vulkan(mglwin *win, mglimg *img, int x, int y)
{
	(void)win;
	(void)img;
	(void)x;
	(void)y;
}

void		MGLWdrawer_vulkan(mglwin *win)
{
	(void)win;
}

void		MGLWcloser_vulkan(mglwin *win)
{
	(void)win;
}
