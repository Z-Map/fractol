/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mglw_window_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:59:43 by map               #+#    #+#             */
/*   Updated: 2016/12/15 00:40:31 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern.h"

mglwin		*mglw_setkcb(mglwin *win, int s, int (*f)(void *, int), void *arg)
{
	if (s == GLFW_RELEASE)
	{
		win->data->kcb[0] = f;
		win->data->kcb_args[0] = arg;
	}
	if (s & GLFW_PRESS)
	{
		win->data->kcb[1] = f;
		win->data->kcb_args[1] = arg;
	}
	if (s & GLFW_REPEAT)
	{
		win->data->kcb[2] = f;
		win->data->kcb_args[2] = arg;
	}
	return (win);
}

void		mglwin_keyprocess(GLFWwindow *win, int k, int sc, int s, int m)
{
	mglwindata *const	wdata = (mglwindata *)glfwGetWindowUserPointer(win);
	int					(*kcb)(void *, int) = wdata->kcb[s];
	int					ret;

	(void)m;
	(void)sc;
	ret = -1;
	if (((k == mglw_getsetting(MGLWS_EXITKEY))
			&& (s & (GLFW_PRESS | GLFW_REPEAT)))
		|| ((kcb) && ((ret = kcb(wdata->kcb_args[s], k) < 0))))
		glfwSetWindowShouldClose(win, GLFW_TRUE);
}

mglwin		*mglwin_shouldclose(mglwin *win)
{
	glfwSetWindowShouldClose(win->data->window, GLFW_TRUE);
	return (win);
}
