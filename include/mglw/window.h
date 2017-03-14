/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:34:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/14 16:47:27 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGLW_WINDOW_H
# define MGLW_WINDOW_H

#include "mglw/mglw_header.h"

/* MiniGLwin Window management */

mglwin		*mglw_mkwin(mglw_m mode, mglw_f flags);
mglwin		*mglw_openwin(mglwin *win, int x, int y, const char *title);
mglwin		*mglw_initwin(mglwin *win, int x, int y);
mglwin		*mglw_closewin(mglwin *win);
void		mglw_rmwin(mglwin *win);

/* MiniGLwin Window lifecycle */

int			mglwin_run(mglwin *win);
void		mglwin_draw(mglwin *win);
int			mglwin_process_event(mglwin *win);
int			mglwin_is_running(mglwin *win);
void		mglwin_clear(mglwin *win);
mglwin		*mglwin_stop(mglwin *win);
mglwin		*mglwin_shouldclose(mglwin *win);

/* MiniGLwin Window tool */

mglwin		*mglw_setGLContext(mglwin *win);
mglwin		*mglw_togglefullscreen(mglwin *win, int fullres);
mglwin		*mglw_draw_itow(mglwin *win, mglimg *img, int x, int y);

/* MiniGLwin Window attributes access */

mgltex		*mglw_get2dlayer(mglwin *win);
mglwin		*mglw_setkcb(mglwin *win, int s, int (*f)(void *, int), void *a);
mglwin		*mglw_setsizecb(mglwin *win, void (*f)(void *, int, int), void *a);
mglwin		*mglw_setmcb(mglwin *win, int s,
				int (*f)(void *, double, double), void *a);

#endif
