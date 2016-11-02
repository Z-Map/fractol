/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdraw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:50:18 by qloubier          #+#    #+#             */
/*   Updated: 2016/09/07 19:23:17 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDRAW_H
# define LIBDRAW_H

# include "mlx.h"
# include "libft.h"
# include "utils.h"
# include "binary.h"
# include "vector.h"
# include "matrix.h"
# include "os_config.h"

typedef struct	s_draw_system
{
	void		*mlx;
	t_list		*win_lst;
	t_list		*cvs_lst;
	t_list		*tex_lst;
	int			win_id;
	int			cvs_id;
	int			tex_id;
	int			(*quit)();
}				t_dsys;

typedef enum	e_ibflag
{
	FRAME_BUFFER = 0,
	TEXTURE_BUFFER = 1,
	HAS_MIPMAP = 2
}				t_ibflag;

typedef	struct	s_draw_image_buffer_settings
{
	int			bpp;
	int			pbw;
	int			lbs;
	t_ui		ibs;
	int			cbe;
	t_ibflag	flags;
}				t_ibset;

typedef struct	s_image_buffer
{
	t_dsys		*sys;
	void		*id;
	t_uc		*image_data;
	t_v2ui		size;
	t_ibset		opt;
}				t_ibuf;

typedef struct	s_draw_texture
{
	t_dsys		*sys;
	t_ibuf		texture_buffer;
	int			draw_id;
	t_v2ui		size;
}				t_tex;

typedef struct	s_draw_canvas
{
	t_cola		color;
	t_cola		color2;
	t_mattf		transform;
	t_mattf		winmat;
	t_mattf		projection;
	t_mattf		modelview;
	t_mattf		mt_object;
	t_mattf		mt_rotation;
	t_mattf		mt_camera;
	t_dsys		*sys;
	int			draw_id;
	t_ibuf		render_buffer;
}				t_cvs;

enum			e_hook
{
	KEYDOWN = 2,
	KEYUP = 3,
	MOUSEDOWN = 4,
	MOUSEUP = 5,
	MOUSEMOVE = 6,
	EXPOSE = 12,
	CLOSE = 17
};

typedef struct	s_draw_window
{
	t_dsys		*sys;
	void		*id;
	int			draw_id;
	t_cvs		buffer;
	t_v2ui		size;
}				t_win;

t_dsys			draw_init(void);
t_win			draw_init_win(t_dsys *sys, t_v2ui size, char *name);
t_cvs			draw_init_cvs(t_dsys *sys, t_v2ui size);
t_tex			draw_init_tex(t_dsys *sys, t_v2ui size);

void			draw_cvs_to_win(t_win *win, t_cvs *cvs, int x, int y);
void			draw_clear_cvs(t_cvs *cvs);
void			draw_render_matrix(t_cvs *cvs);

void			draw_tex_to_cvs(t_cvs *cvs, t_tex *tex, t_v2f p, float zoom);
void			draw_clear_tex(t_tex *tex, t_col c);
t_col			draw_gettexel(t_tex *tex, t_v2f *p);

void			draw_clear_win(t_win *win);

void			draw_free_win(void *ptr, size_t s);
void			draw_free_cvs(void *ptr, size_t s);
void			draw_free_tex(void *ptr, size_t s);
int				draw_clean_exit(void *sys, char *message);
void			draw_hook(t_win *w, int (*f)(), void *ud,
	const enum e_hook hook);

/*
** Scene Logic
*/

typedef enum	e_draw_type
{
	POINT = 1,
	LINES = 1 << 1,
	TRIS = 1 << 2,
	POLY = 1 << 3
}				t_draw_type;

typedef struct	s_nd
{
	struct s_nd	*parent;
	struct s_nd	*next;
	struct s_nd	*previous;
	struct s_nd	*firstchild;
	struct s_nd	*lastchild;
	t_ui		len;
}				t_node;

typedef struct	s_draw_scene
{
	t_node		*root;
}				t_sce;

void			draw_render(void);

/*
** Draw Logic
*/

typedef struct	s_2d_line
{
	t_v2ui		from;
	t_v2ui		to;
	t_v2i		d;
	int			vy;
}				t_2dl;

typedef struct	s_gradient
{
	t_col		s;
	t_col		e;
	int			step;
	int			c;
	int			ic;
}				t_gradient;

typedef struct	s_texture_filter
{
	t_v4ui		p;
	t_v4f		ptex;
	t_v4ui		d;
	t_v2f		texel;
	t_v4f		tc;
}				t_texfilter;

t_col			draw_col(t_uc r, t_uc g, t_uc b);
t_cola			draw_cola(t_uc r, t_uc g, t_uc b, t_uc a);
unsigned int	draw_lerp_col(t_col *col, t_col *col2, unsigned char fac);
unsigned int	draw_autocol(void *param);

t_col			draw_getpx(t_ibuf *i, t_ui x, t_ui y);
void			draw_px(t_ibuf *i, t_v2ui *p, t_ui *c);
void			draw_pxc(t_ibuf *i, t_v2ui p, t_ui c);
void			draw_px_rgba(t_ibuf *i, t_v2ui *p, t_cola *c);
void			draw_px_line(t_ibuf *i, t_v2ui *p, t_ui num, t_ui *c);
void			draw_px_column(t_ibuf *i, t_v2ui *p, t_ui num, t_ui *c);
void			draw_grad_px(t_ibuf *i, t_v2ui *p, t_ui (*c)(void *));
void			draw_grad_hl(t_ibuf *i, t_v2ui *p, t_ui n, t_ui (*c)(void *));
void			draw_grad_vl(t_ibuf *i, t_v2ui *p, t_ui n, t_ui (*c)(void *));

int				draw_clip_pos(t_v3f *s, t_v3f *e, t_v2i *d, t_v2ui *limit);
int				draw_clip_neg(t_v3f *s, t_v3f *e, t_v2i *d, t_v2ui *limit);
void			draw_swap(t_v3f *s, t_v3f *e, t_gradient *gr, int swp);

void			draw_point(t_cvs *c, t_v2ui *p);

t_2dl			mkline(t_v3f s, t_v3f e, t_v2ui *limit, t_gradient *gr);
void			draw_line(t_cvs *cvs, t_2dl *l);
void			draw_grad_line(t_cvs *cvs, t_2dl *l, t_gradient *gr);

void			draw_texlerp_filter(t_ibuf *img, t_texfilter *tf, t_tex *tex);
void			draw_mipmap_filter(t_ibuf *img, t_texfilter *tf, t_tex *tex);

#endif
