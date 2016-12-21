/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mglw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:39:16 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/21 14:17:07 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGLW_H
#define MGLW_H

#include <string.h>
#include "mglw_gldef.h"
#include "mglw_keys.h"

typedef unsigned char	uchar;
typedef unsigned int	uint;
typedef unsigned long	ulong;

typedef enum	mglw_settings
{
	MGLWS_EXITKEY = 0,
	MGLWS_DEFAULT_WM,
	MGLWS_LEGACY_MODERN,
	MGLWS_DEFAULT_IFLAG,
	MGLWS_DEFAULT_IBPP,
	MGLWS_DEFAULT_IFORMAT,
	MGLWS_DEFAULT_TFLAG,
	MGLWS_DEFAULT_TEXFORMAT,
	MGLWS_LENGHT
}				mlgw_s;

typedef enum	mglw_texture_format
{
	MGLW_TF_UNDEFINED = 0,
	MGLW_RED = GL_RED,
	MGLW_RG = GL_RG,
	MGLW_RGB = GL_RGB,
	MGLW_BGR = GL_BGR,
	MGLW_RGBA = GL_RGBA,
	MGLW_BGRA = GL_BGRA,
	MGLW_STEN = GL_STENCIL_INDEX,
	MGLW_DEPTH = GL_DEPTH_COMPONENT,
	MGLW_DEPTH_STEN = GL_DEPTH_STENCIL
}				mglw_tf;

typedef enum	mglw_texture_type
{
	MGLW_TT_DONTCARE = 0,
	MGLW_BYTE = GL_BYTE,
	MGLW_UBYTE = GL_UNSIGNED_BYTE,
	MGLW_INT = GL_INT,
	MGLW_UINT = GL_UNSIGNED_INT,
	MGLW_FLOAT = GL_FLOAT,
}				mglw_tt;

typedef enum	mglwin_mode
{
	MGLW_NONE_MODE = 0,
	MGLW_LEGACY_MODE = 1,
	MGLW_OPENGL3_MODE = 2,
	MGLW_OPENGL4_MODE = 3,
	MGLW_VULKAN_MODE = 4
}				mglw_m;

typedef enum	mglwin_flag
{
	MGLW_NONE = 0,
	MGLW_2DLAYER = 1,
	MGLW_UNKNOWN = 1 << 1,
	MGLW_DRAWTOOLS = 1 << 2,
	MGLW_STOP = 1 << 3,
	MGLW_WINDATAFLAGS = MGLW_2DLAYER | MGLW_DRAWTOOLS
}				mglw_f;

typedef enum	mglw_imgflag
{
	MGLWI_NONE = 0,
	MGLWI_DYNAMIC = 1,
	MGLWI_LOADED = 1 << 1,
	MGLWI_LOAD = MGLWI_DYNAMIC | MGLWI_LOADED,
	MGLWI_LAYER = 1 << 2,
	MGLWI_TEXTURE = 1 << 3,
	MGLWI_TEXLAY = MGLWI_LAYER | MGLWI_TEXTURE,
	MGLWI_INT = 1 << 4,
	MGLWI_FLOAT = 1 << 5,
	MGLWI_NOALLOC = 1 << 6,
	MGLWI_USERALLOC = MGLWI_NOALLOC | MGLWI_DYNAMIC,
	MGLWI_LOADFLAG = MGLWI_USERALLOC,
	MGLWI_USERFLAG = MGLWI_LOADFLAG | MGLWI_INT | MGLWI_FLOAT
}				mglw_if;

typedef struct			mlgw_image
{
	const unsigned int			x;
	const unsigned int			y;
	const unsigned int			bpp;
	const mglw_if		flags;
	const mglw_tf		format;
	const mglw_tt		type;
	const size_t		memlen;
	uchar *const		pixels;
	const double		creatime;
	const void *const	next;
}						mglimg;


typedef void			mglwin; /*
typedef struct mglw_win_data		mglw_wd;
typedef struct mglw_win				mglwin;

struct			mglw_win_data
{
	unsigned int		user;
	int			state;
	void		*window;
	mglw_f		flags;
	mglimg		*layer2D;
};

struct			mglw_win
{
	mglw_wd	*data;
	mglwin		*next;
	mglw_m		mode;
	mglw_f		flags;
	double		creatime;
};
//*/

typedef void			mglw_sys;

int						mglw_init();
int						mglw_close();
int						mglw_getsetting(mlgw_s setting);
void					mglw_setsetting(mlgw_s setting, int value);

mglwin					*mglw_mkwin(mglw_m mode, mglw_f flags);
mglwin					*mglw_openwin(mglwin *win, int x, int y, const char *t);
int						mglwin_run(mglwin *win);
void					mglwin_draw(mglwin *win);
int						mglwin_is_running(mglwin *win);
mglimg					*mglw_get2dlayer(mglwin *win);
mglwin					*mglw_setkcb(mglwin *win, int s,
							int (*f)(void *, int), void *arg);
mglwin					*mglw_closewin(mglwin *win);
void					mglw_rmwin(mglwin *win);

mglimg					*mglw_mkimg(unsigned int x, unsigned int y, unsigned int bpp, mglw_if flags);
mglimg					*mglw_loadimg(const char *fname, mglw_if flags, int n);
mglimg					*mglw_reloadimg(mglimg *img, const char *filename);
void					mglw_rmimg(mglimg *img);

#endif
