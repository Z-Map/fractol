/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_proto.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 19:03:46 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:31:39 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_PROTO_H
# define FRACTOL_PROTO_H

typedef long double									t_frac;

typedef struct s_mode_parse							t_mparse;

typedef struct s_colorgrad							t_cgr;
typedef struct s_frac_vector						t_vec;
typedef struct s_view_fractal						t_frv;
typedef struct s_render_ctx							t_frctx;
typedef struct s_render_mgr							t_frmgr;
typedef struct s_fractol_param						t_frprm;

typedef struct s_thread_ctx							t_thctx;
typedef struct s_thread_mgr							t_thmgr;
typedef struct s_fractol_root						t_frc;

#endif
