/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mglw_window_opengl4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 01:31:48 by map               #+#    #+#             */
/*   Updated: 2016/12/15 02:01:14 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_ogl4tools.h"
#include "mglw_intern.h"

int			MGLWopener_opengl4(mglwin *win, int x, int y, const char *title)
{
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	if (!(win->data->window = glfwCreateWindow(x, y, title, NULL, NULL)))
		return (0);
	glfwMakeContextCurrent(win->data->window);
	if(ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(win->data->window);
		return (0);
	}
	if ((win->flags & MGLW_2DLAYER) &&
		!(win->data->layer2D = mglw_mktexture(
			(uint)x, (uint)y, MGLW_RGBA, MGLWI_DYNAMIC)))
	{
		win->flags &= ~MGLW_2DLAYER;
		win->data->flags &= ~MGLW_2DLAYER;
	}
	win->data->state |= 1;
	return (1);
}

void		MGLWclearer_opengl4(mglwin *win)
{
	glClear(GL_COLOR_BUFFER_BIT);
	(void)win;
}

void		MGLWdrawer_opengl4(mglwin *win)
{
	(void)win;
}

void		MGLWcloser_opengl4(mglwin *win)
{
	if (win->flags & MGLW_2DLAYER)
		mglw_rmimg((mglimg *)(win->data->layer2D));
}
