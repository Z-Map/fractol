/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:34:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/23 13:26:48 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGLW_WINDOW_H

#include "mglw_intern/mglw_header.h"
#include "mglw_intern/system.h"

#include "mglw/window.h"

/* MiniGLwin Window monitor tool */

GLFWmonitor	*MGLWgetWinMonitor(mglwin *win);

/* MiniGLwin Window event processing */

void		MGLWkeyprocess(GLFWwindow *win, int k, int sc, int s, int m);
void		MGLWsizeprocess(GLFWwindow *win, int w, int h);
void		MGLWpositionprocess(GLFWwindow *win, int x, int y);

/* MiniGLwin Window Type callbacks */

int			MGLWopener_legacy(mglwin *win, int x, int y, const char *title);
int			MGLWopener_opengl3(mglwin *win, int x, int y, const char *title);
int			MGLWopener_opengl4(mglwin *win, int x, int y, const char *title);
int			MGLWopener_vulkan(mglwin *win, int x, int y, const char *title);

void		MGLWclearer_legacy(mglwin *win);
void		MGLWclearer_opengl3(mglwin *win);
void		MGLWclearer_opengl4(mglwin *win);
void		MGLWclearer_vulkan(mglwin *win);

void		MGLWdrawer_legacy(mglwin *win);
void		MGLWdrawer_opengl3(mglwin *win);
void		MGLWdrawer_opengl4(mglwin *win);
void		MGLWdrawer_vulkan(mglwin *win);

void		MGLWimagedraw_legacy(mglwin *win, mglimg *img, int x, int y);
void		MGLWimagedraw_opengl3(mglwin *win, mglimg *img, int x, int y);
void		MGLWimagedraw_opengl4(mglwin *win, mglimg *img, int x, int y);
void		MGLWimagedraw_vulkan(mglwin *win, mglimg *img, int x, int y);

void		MGLWcloser_legacy(mglwin *win);
void		MGLWcloser_opengl3(mglwin *win);
void		MGLWcloser_opengl4(mglwin *win);
void		MGLWcloser_vulkan(mglwin *win);

#endif
