/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mglw_intern.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:39:16 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/19 05:00:12 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGLW_INTERN_H
#define MGLW_INTERN_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "glload/gl_all.h"
#include "glload/gl_load.h"
#include "GLFW/glfw3.h"
#include "data/mglw_types.h"

/* MiniGLwin System management */

int			mglw_init();
mglw_sys	*MGLWgetsys();
int			mglw_close(mglw_sys *sys);

/* MiniGLwin System management */

int			mglw_getsetting(mglws setting);
void		mglw_setsetting(mglws setting, int value);

/* MiniGLwin System tools */

int			MGLWaddwin(mglwin *win);
int			MGLWdelwin(mglwin *win);
int			MGLWdelallwin();

int			MGLWaddimg(mglimg *img);
int			MGLWdelimg(mglimg *img);
int			MGLWdelallimg();

/* -------------------------------------------------------------------------- */

/* MiniGLwin Window management */

mglwin		*mglw_mkwin(mglwm mode, mglwf flags);
mglwin		*mglw_openwin(mglwin *win, int x, int y, const char *title);
mglwin		*mglw_initwin(mglwin *win, int x, int y);
int			mglwin_run(mglwin *win);
mglwin		*mglwin_stop(mglwin *win);
mglwin		*mglwin_shouldclose(mglwin *win);
mglwin		*mglw_closewin(mglwin *win);
void		mglw_rmwin(mglwin *win);

/* MiniGLwin Window lifecycle */

mglwin		*mglw_draw_itow(mglwin *win, mglimg *img, int x, int y);
void		mglwin_draw(mglwin *win);
int			mglwin_is_running(mglwin *win);

/* MiniGLwin Window attributes access */

mgltex		*mglw_get2dlayer(mglwin *win);
mglwin		*mglw_setkcb(mglwin *win, int s, int (*f)(void *, int), void *arg);

/* MiniGLwin Window event processing */

void		mglwin_keyprocess(GLFWwindow *win, int k, int sc, int s, int m);

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

/* -------------------------------------------------------------------------- */

/* MiniGLwin image management  */

mglimg		*mglw_mkimg(uint x, uint y);
mglimg		*mglw_mkimage(uint x, uint y, uint bpp, mglw_if flags);
mgltex		*mglw_mktex(uint x, uint y);
mgltex		*mglw_mktexture(uint x, uint y, mglw_tf fmt, mglw_if flags);
mglimg		*mglw_loadimg(const char *filename);
mglimg		*mglw_loadimage(const char *filename, mglw_if flags, int bpp);
mgltex		*mglw_loadtex(const char *filename);
mgltex		*mglw_loadtexture(const char *filename, mglw_if flags, GLenum fmt);
mglimg		*mglw_dupimg(mglimg *img);
mglimg		*mglw_setimg(mglimg *img, uchar *pixels);
mglimg		*mglw_unsetimg(mglimg *img);
mglimg		*mglw_resetimg(mglimg *img);
mglimg		*mglw_reloadimg(mglimg *img, const char *filename);
void		mglw_rmimg(mglimg *img);
void		mglw_unloadimg(mglimg *img);

/* MiniGLwin image management  */

int			MGLWgetBpp(mglw_tf fmt, mglw_if flags);
mglw_tf		MGLWgetFormat(int bpp, mglw_if flags);
mglw_tt		MGLWgetType(mglw_tf fmt, mglw_if flags);

/* -------------------------------------------------------------------------- */

/* MiniGLwin Error management */

void		mglw_seterror(int error, const char* msg);

#endif
