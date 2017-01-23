/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:21:38 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/23 14:04:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern/window.h"
#include "mglw_intern/image.h"

GLFWmonitor	*MGLWgetWinMonitor(mglwin *win)
{
	GLFWmonitor			*monitor = glfwGetWindowMonitor(win->data->window);
	GLFWmonitor			**monitors;
	const GLFWvidmode	*mode;
	int					x, y, mx, my, i,
						wx = win->data->win_x,
						wy = win->data->win_y;

	if (!monitor)
	{
		monitor = glfwGetPrimaryMonitor();
		monitors = glfwGetMonitors(&i);
		if (i == 1)
			return (*monitors);
		while (i--)
		{
			mode = glfwGetVideoMode(monitors[i]);
			glfwGetMonitorPos(monitors[i], &x, &y);
			mx = x + mode->width;
			my = y + mode->height;
			if ((wx >= x) && (wy >= y) && (wx < mx) && (wy < my))
			{
				monitor = monitors[i];
				break ;
			}
		}
	}
	return (monitor);
}
