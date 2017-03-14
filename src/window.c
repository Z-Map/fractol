/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 04:05:38 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/14 19:46:55 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern/window.h"
#include "mglw_intern/image.h"

/* Coucou, je suis une bonne grosse globale des familles comme on les aime*/
static const struct wintypecb
{
	int		(*opener)(mglwin *, int, int, const char *);
	void	(*drawer)(mglwin *);
	void	(*imagedraw)(mglwin *, mglimg *, int, int);
	void	(*clearer)(mglwin *);
	void	(*closer)(mglwin *);
} MGLWtcb[] = {
	(struct wintypecb){ NULL, NULL, NULL, NULL, NULL },
	(struct wintypecb){
		&MGLWopener_legacy,
		&MGLWdrawer_legacy,
		&MGLWimagedraw_legacy,
		&MGLWclearer_legacy,
		&MGLWcloser_legacy,
	},
	(struct wintypecb){
		&MGLWopener_opengl3,
		&MGLWdrawer_opengl3,
		NULL,
		&MGLWclearer_opengl3,
		&MGLWcloser_opengl3,
	},
	(struct wintypecb){
		&MGLWopener_opengl4,
		&MGLWdrawer_opengl4,
		NULL,
		&MGLWclearer_opengl4,
		&MGLWcloser_opengl4,
	},
	(struct wintypecb){
		&MGLWopener_vulkan,
		&MGLWdrawer_vulkan,
		NULL,
		&MGLWclearer_vulkan,
		&MGLWcloser_vulkan,
	}
};

mglwin		*mglw_mkwin(mglw_m mode, mglw_f flags)
{
	mglw_sys *const	sys = MGLWgetsys();
	mglwin			win;
	mglw_wd			wdata;
	mglwin			*ret;

	if (!mode)
		return (NULL);
	wdata = (mglw_wd){ .user = 1, .state = 0,
		.win_x = 0, .win_y = 0,
		.win_w = sys->settings[MGLWS_DEFAULT_WWIDTH],
		.win_h = sys->settings[MGLWS_DEFAULT_WHEIGHT],
		.window = NULL,
		.flags = flags & MGLW_WINDATAFLAGS,
		.layer2D = NULL, .draw_vao = 0,
		.draw_buffers = {0, 0, 0, 0, 0, 0, 0, 0}, .draw_tex = {0, 0, 0, 0},
		.optime = 0.0,
		.kcb = {NULL, NULL, NULL}, .kcb_args = {NULL, NULL, NULL} };
	win = (mglwin){ .data = NULL, .next = NULL,
		.mode = mode, .flags = flags, .creatime = glfwGetTime()};
	if (!(ret = malloc(sizeof(mglwin))))
		return (NULL);
	if (!(win.data = malloc(sizeof(mglw_wd))))
	{
		free(ret);
		return (NULL);
	}
	*(win.data) = wdata;
	*ret = win;
	MGLWaddwin(ret);
	return (ret);
}

mglwin		*mglw_openwin(mglwin *win, int x, int y, const char *title)
{
	const int			m = win->mode;
	const GLFWvidmode	*mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int					w, h;

	if ((!win) || (win->data->state & 1) ||
		!(MGLWtcb[m].opener))
			return (NULL);
	w = x;
	h = y;
	if ((win->data->flags & MGLW_FULLRES) &&
		(win->data->flags & MGLW_FULLSCREEN))
	{
		x = mode->width;
		y = mode->height;
	}
	if (!MGLWtcb[m].opener(win, x, y, title))
		return (NULL);
	if (win->data->flags & MGLW_FULLSCREEN)
		glfwSetWindowMonitor(win->data->window, glfwGetPrimaryMonitor(),
			0, 0, x, y, mode->refreshRate);
	glfwGetWindowPos(win->data->window,
		&(win->data->win_x), &(win->data->win_y));
	win->data->win_w = w;
	win->data->win_h = h;
	win->data->screen_w = w;
	win->data->screen_h = h;
	glfwFocusWindow(win->data->window);
	return (win);
}

mglwin		*mglw_initwin(mglwin *win, int x, int y)
{
	if ((win->flags & MGLW_2DLAYER) &&
		!(win->data->layer2D = mglw_mktexture(
		(uint)x, (uint)y, MGLW_RGBA, MGLWI_DYNAMIC)))
		win->data->flags &= ~MGLW_2DLAYER;
	win->data->optime = glfwGetTime();
	win->data->state |= 1;
	glfwSetWindowUserPointer(win->data->window, win->data);
	glfwSetKeyCallback(win->data->window, &MGLWkeyprocess);
	glfwSetMouseButtonCallback(win->data->window, &MGLWmousebuttonprocess);
	glfwSetCursorPosCallback(win->data->window, &MGLWmouseprocess);
	glfwSetScrollCallback(win->data->window, &MGLWmousewheelprocess);
	glfwSetWindowPosCallback(win->data->window, &MGLWpositionprocess);
	glfwSetWindowSizeCallback(win->data->window, &MGLWsizeprocess);
	return (win);
}

mglwin		*mglw_closewin(mglwin *win)
{
	const int	m = win->mode;

	if ((win) && (win->data->state & 1))
	{
		if (win->flags & MGLW_2DLAYER)
			mglw_rmimg((mglimg *)(win->data->layer2D));
		if (MGLWtcb[m].closer)
			MGLWtcb[m].closer(win);
		glfwDestroyWindow(win->data->window);
		win->data->state = 0;
	}
	return (win);
}

void		mglw_rmwin(mglwin *win)
{
	if (!win)
		return ;
	MGLWdelwin(win);
	win->data->user -= 1;
	if (!(win->data->user))
	{
		mglw_closewin(win);
		free(win->data);
	}
	free(win);
}

int			mglwin_run(mglwin *win)
{
	const int	m = win->mode;

	if ((win) && (win->data->state & 1))
	{
		glfwMakeContextCurrent(win->data->window);
		if (MGLWtcb[m].drawer)
			MGLWtcb[m].drawer(win);
		glfwSwapBuffers(win->data->window);
		glfwPollEvents();
		if (glfwWindowShouldClose(win->data->window))
		{
			mglw_closewin(win);
			return (0);
		}
		if ((win->flags | win->data->flags)  & MGLW_STOP)
		{
			win->flags &= ~MGLW_STOP;
			win->data->flags &= ~MGLW_STOP;
			return (0);
		}
		glfwMakeContextCurrent(win->data->window);
		if (MGLWtcb[m].clearer)
			MGLWtcb[m].clearer(win);
		return (1);
	}
	return (0);
}

void		mglwin_draw(mglwin *win)
{
	const int	m = win->mode;

	if ((win) && (win->data->state & 1))
	{
		glfwMakeContextCurrent(win->data->window);
		if (MGLWtcb[m].drawer)
			MGLWtcb[m].drawer(win);
		glfwSwapBuffers(win->data->window);
	}
}

int			mglwin_process_event(mglwin *win)
{
	if ((win) && (win->data->state & 1))
	{
		glfwPollEvents();
		if (glfwWindowShouldClose(win->data->window))
		{
			mglw_closewin(win);
			return (0);
		}
		if ((win->flags | win->data->flags)  & MGLW_STOP)
		{
			win->flags &= ~MGLW_STOP;
			win->data->flags &= ~MGLW_STOP;
			return (0);
		}
		return (1);
	}
	return (0);
}

int			mglwin_is_running(mglwin *win)
{
	if ((win) && (win->data->state & 1) &&
		!(glfwWindowShouldClose(win->data->window)
		|| ((win->flags | win->data->flags)  & MGLW_STOP)))
		return (1);
	return (0);
}

void		mglwin_clear(mglwin *win)
{
	const int	m = win->mode;

	if ((win) && (win->data->state & 1))
	{
		glfwMakeContextCurrent(win->data->window);
		if (MGLWtcb[m].clearer)
			MGLWtcb[m].clearer(win);
	}
}

mglwin		*mglwin_stop(mglwin *win)
{
	win->flags |= MGLW_STOP;
	return (win);
}

mglwin		*mglw_setGLContext(mglwin *win)
{
	if (!win)
		glfwMakeContextCurrent(NULL);
	else if (win->data->state & 1)
		glfwMakeContextCurrent(win->data->window);
	else
		return (NULL);
	return (win);
}

mglwin		*mglw_togglefullscreen(mglwin *win, int fullres)
{
	const GLFWvidmode	*mode;
	GLFWmonitor			*monitor;
	int					x, y;

	if (!win)
		return (NULL);
	if (win->data->flags & MGLW_FULLSCREEN)
	{
		win->data->flags &= ~MGLW_FULLSCREEN;
		if (fullres > 0)
			win->data->flags &= ~MGLW_FULLRES;
		if (win->data->state & 1)
			glfwSetWindowMonitor(win->data->window, NULL,
				win->data->win_x, win->data->win_y,
				win->data->win_w, win->data->win_h, 0);
		glfwFocusWindow(win->data->window);
	}
	else
	{
		monitor = MGLWgetWinMonitor(win);
		mode = glfwGetVideoMode(monitor);
		x = win->data->win_w;
		y = win->data->win_h;
		if (fullres > 0 || ((fullres < 0) && (win->flags & MGLW_FULLRES)))
		{
			x = mode->width;
			y = mode->height;
			win->data->flags |= MGLW_FULLRES;
		}
		win->data->flags |= MGLW_FULLSCREEN;
		if (win->data->state & 1)
			glfwSetWindowMonitor(win->data->window, monitor,
				0, 0, x, y, mode->refreshRate);
		glfwFocusWindow(win->data->window);
	}
	return (win);
}


mglwin			*mglw_draw_itow(mglwin *win, mglimg *img, int x, int y)
{
	const int	m = win->mode;

	if ((win) && (win->data->state & 1))
	{
		if (MGLWtcb[m].imagedraw)
			MGLWtcb[m].imagedraw(win, img, x, y);
	}
	return (win);
}
