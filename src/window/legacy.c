/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legacy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:24:32 by map               #+#    #+#             */
/*   Updated: 2017/01/04 08:50:08 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern/mglw_ogl2tools.h"
#include "mglw_intern/window.h"

#include "mgl/ressources/quads.h"
#include "mgl/ressources/shaders/basic.h"
#include "mgl/shaders.h"

int			MGLWopener_legacy(mglwin *win, int x, int y, const char *title)
{
	float	vdata[20];

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
	glGenTextures(1, win->data->draw_tex);
	if (win->data->flags & MGLW_2DLAYER)
	{
		memcpy(vdata, &mglw_GR_quad, sizeof(float) * 12);
		memcpy(&(vdata[12]), &(mglw_GR_quad.uvs), sizeof(float) * 8);
		vdata[13] = 1.0f;
		vdata[15] = 0.0f;
		vdata[17] = 1.0f;
		vdata[19] = 0.0f;
		glGenBuffers(1, &(win->data->l2D_buffer));
		glBindBuffer(GL_ARRAY_BUFFER, win->data->l2D_buffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 20,
			vdata, GL_STATIC_DRAW);
	}
	return (1);
}

void		MGLWclearer_legacy(mglwin *win)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	(void)win;
}

void		MGLWimagedraw_legacy(mglwin *win, mglimg *img, int x, int y)
{
	static mglsha	shr = (mglsha){ 0, 0, 0, NULL, NULL};

	if (!win || !img)
		return ;
	if (!shr.id)
	{
		shr = drawimage2d_shader;
		mgl_compile_shader(&shr);
		glBindAttribLocation(shr.id, 0, "v_pos");
		glBindAttribLocation(shr.id, 1, "v_uv");
		// glUniform1i(glGetUniformLocation(shr.id, "image" ), 0);
	}
	glUseProgram(shr.id);
	glPushAttrib(GL_COLOR_BUFFER_BIT|GL_CURRENT_BIT);
	glEnable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindBuffer(GL_ARRAY_BUFFER, win->data->l2D_buffer);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(float) * 12));
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, win->data->draw_tex[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->x, img->y, 0,
		img->format, img->type, img->pixels);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glBindTexture(GL_TEXTURE_2D, 0);
	(void)x;
	(void)y;
	glDisableVertexAttribArray(0);
	glPopAttrib(GL_COLOR_BUFFER_BIT|GL_CURRENT_BIT);
}

void		MGLWdrawer_legacy(mglwin *win)
{
	mglimg	*layer = (mglimg *)(win->data->layer2D);

	if (win->flags & MGLW_2DLAYER)
	{
		MGLWimagedraw_legacy(win, layer, 0, 0);
		// glPushAttrib(GL_COLOR_BUFFER_BIT|GL_CURRENT_BIT);
		// glEnable(GL_BLEND);
		// glEnable(GL_ALPHA_TEST);
		// glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		// glRasterPos2f(-1.0f,1.0f);
		// glPixelZoom(1.0f, -1.0f);
		// glDrawPixels(layer->x, layer->y,
		// 	layer->format, layer->type, layer->pixels);
		// glPopAttrib(GL_COLOR_BUFFER_BIT|GL_CURRENT_BIT);
	}
}

void		MGLWcloser_legacy(mglwin *win)
{
	(void)win;
}
