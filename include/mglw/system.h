/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 04:05:26 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/21 15:06:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGLW_SYSTEM_H
#define MGLW_SYSTEM_H

#include "mglw/mglw_header.h"

/* MiniGLwin System management */

int			mglw_init();
int			mglw_close(mglw_sys *sys);

/* MiniGLwin System management */

int			mglw_getsetting(mlgw_s setting);
void		mglw_setsetting(mlgw_s setting, int value);

/* MiniGLwin Error management */

void		mglw_seterror(int error, const char* msg);

#endif
