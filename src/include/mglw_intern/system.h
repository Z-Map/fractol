/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 04:05:26 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/21 15:17:36 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGLW_SYSTEM_H

#include "mglw_intern/mglw_header.h"
#include "mglw/system.h"

/* MiniGLwin System management */
mglw_sys	*MGLWgetsys();
/* MiniGLwin System tools */

int			MGLWaddwin(mglwin *win);
int			MGLWdelwin(mglwin *win);
int			MGLWdelallwin();

int			MGLWaddimg(mglimg *img);
int			MGLWdelimg(mglimg *img);
int			MGLWdelallimg();

#endif
