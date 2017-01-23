/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:49:08 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/23 11:21:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGLW_WINDOW_TYPE_H
#define MGLW_WINDOW_TYPE_H

# include "mglw/mglw_proto.h"

struct			mglw_win_data
{
	unsigned int	user;
	int				state;
	int				win_x;
	int				win_y;
	int				win_w;
	int				win_h;
	GLFWwindow		*window;
	mglw_f			flags;
	mgltex			*layer2D;
	unsigned int	l2D_buffer;
	unsigned int	draw_vao;
	unsigned int	draw_buffers[8];
	unsigned int	draw_tex[4];
	double			optime;
	void			*kcb[3];
	void			*kcb_args[3];
	void			*sizecb;
	void			*sizecb_arg;
};

struct			mglw_win
{
	mglw_wd			*data;
	mglwin			*next;
	mglw_m			mode;
	mglw_f			flags;
	double			creatime;
};

#endif
