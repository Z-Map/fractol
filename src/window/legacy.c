/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legacy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:24:32 by map               #+#    #+#             */
/*   Updated: 2016/12/19 17:13:43 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_ogl2tools.h"
#include "mglw_intern.h"

#include "ressources/quads.h"

int			MGLWopener_legacy(mglwin *win, int x, int y, const char *title)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	if (!(win->data->window = glfwCreateWindow(x, y, title, NULL, NULL)))
		return (0);
	glfwMakeContextCurrent(win->data->window);
	glfwSwapInterval(1);
	if(ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(win->data->window);
		return (0);
	}
	mglw_initwin(win, x, y);
	if (win->data->flags & MGLW_2DLAYER)
	{
		glGenBuffers(1, &(win->data->l2D_buffer));
		glBindBuffer(GL_ARRAY_BUFFER, win->data->l2D_buffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(mglw_GR_quad),
			&mglw_GR_quad, GL_STATIC_DRAW);
	}
	return (1);
}

void		MGLWclearer_legacy(mglwin *win)
{
	glClear(GL_COLOR_BUFFER_BIT);
	(void)win;
}

void		MGLWimagedraw_legacy(mglwin *win, mglimg *img, int x, int y)
{
	if (!win || !img)
		return ;
	glPushAttrib(GL_COLOR_BUFFER_BIT|GL_CURRENT_BIT);
	glEnable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	(void)x;
	(void)y;
	glPopAttrib(GL_COLOR_BUFFER_BIT|GL_CURRENT_BIT);
}

void		MGLWdrawer_legacy(mglwin *win)
{
	mglimg	*layer = (mglimg *)(win->data->layer2D);

	if (win->flags & MGLW_2DLAYER)
	{
		glPushAttrib(GL_COLOR_BUFFER_BIT|GL_CURRENT_BIT);
		glEnable(GL_BLEND);
		glEnable(GL_ALPHA_TEST);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glRasterPos2f(-1.0f,1.0f);
		glPixelZoom(1.0f, -1.0f);
		glDrawPixels(layer->x, layer->y,
			layer->format, layer->type, layer->pixels);
		glPopAttrib(GL_COLOR_BUFFER_BIT|GL_CURRENT_BIT);
	}
}

void		MGLWcloser_legacy(mglwin *win)
{
	(void)win;
}
