/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mglw_window_legacy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:24:32 by map               #+#    #+#             */
/*   Updated: 2016/12/15 05:49:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_ogl2tools.h"
#include "mglw_intern.h"

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
	if ((win->flags & MGLW_2DLAYER) &&
		!(win->data->layer2D = mglw_mktexture(
			(uint)x, (uint)y, MGLW_RGBA, MGLWI_DYNAMIC)))
	{
		win->flags &= ~MGLW_2DLAYER;
		win->data->flags &= ~MGLW_2DLAYER;
	}
	return (1);
}

void		MGLWclearer_legacy(mglwin *win)
{
	glClear(GL_COLOR_BUFFER_BIT);
	(void)win;
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
	if (win->flags & MGLW_2DLAYER)
		mglw_rmimg((mglimg *)(win->data->layer2D));
}
