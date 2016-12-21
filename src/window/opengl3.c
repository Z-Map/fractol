/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 01:31:48 by map               #+#    #+#             */
/*   Updated: 2016/12/21 15:34:34 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern/mglw_ogl3tools.h"
#include "mglw_intern/window.h"

#include "mgl/ressources/quads.h"

int			MGLWopener_opengl3(mglwin *win, int x, int y, const char *title)
{
#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	if (!(win->data->window = glfwCreateWindow(x, y, title, NULL, NULL)))
		return (0);
	glfwMakeContextCurrent(win->data->window);
	if(ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(win->data->window);
		return (0);
	}
	return (1);
}

void		MGLWclearer_opengl3(mglwin *win)
{
	glClear(GL_COLOR_BUFFER_BIT);
	(void)win;
}

void		MGLWimagedraw_opengl3(mglwin *win, mglimg *img, int x, int y)
{
	(void)win;
	(void)img;
	(void)x;
	(void)y;
}

void		MGLWdrawer_opengl3(mglwin *win)
{
	(void)win;
}

void		MGLWcloser_opengl3(mglwin *win)
{
	(void)win;
}
