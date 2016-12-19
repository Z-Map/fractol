/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mglw_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 22:47:57 by map               #+#    #+#             */
/*   Updated: 2016/12/19 04:42:25 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGLW_TYPES_H
# define MGLW_TYPES_H

# include <stdlib.h>
# include "GLFW/glfw3.h"

/* MiniGLwin type prototype */

typedef unsigned char				uchar;
typedef unsigned int				uint;
typedef unsigned long				ulong;

typedef struct mlgw_image			mglimg;
typedef struct mlgw_texture			mgltex;
typedef struct mlgw_layertex		mgltexlayer;
typedef struct mglw_win_data		mglwindata;
typedef struct mglw_win				mglwin;
typedef struct miniGLwin_system		mglw_sys;

/* -------------------------------------------------------------------------- */

/* MiniGLwin type declaration */

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
}				mglws;

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
}				mglwm;

typedef enum	mglwin_flag
{
	MGLW_NONE = 0,
	MGLW_2DLAYER = 1,
	MGLW_UNKNOWN = 1 << 1,
	MGLW_DRAWTOOLS = 1 << 2,
	MGLW_STOP = 1 << 3,
	MGLW_WINDATAFLAGS = MGLW_2DLAYER | MGLW_DRAWTOOLS
}				mglwf;

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

struct			mlgw_image
{
	uint		x;
	uint		y;
	uint		bpp;
	mglw_if		flags;
	mglw_tf		format;
	mglw_tt		type;
	size_t		memlen;
	uchar		*pixels;
	double		creatime;
	mglimg		*next;
};

struct			mlgw_texture
{
	mglimg		cpuimage;
	GLuint		texid;
	GLenum		format;
};

struct			mlgw_texlayer
{
	mgltex		texture;
	GLuint		fbid;
};

struct			mglw_win_data
{
	uint		user;
	int			state;
	GLFWwindow	*window;
	mglwf		flags;
	mgltex		*layer2D;
	GLuint		l2D_buffer;
	GLuint		draw_vao;
	GLuint		draw_buffers[8];
	GLuint		draw_tex[4];
	double		optime;
	void		*kcb[3];
	void		*kcb_args[3];
};

struct			mglw_win
{
	mglwindata	*data;
	mglwin		*next;
	mglwm		mode;
	mglwf		flags;
	double		creatime;
};

struct			miniGLwin_system
{
	int			error;
	int			padding;
	mglwin		*wlst;
	mglimg		*ilst;
	int			settings[MGLWS_LENGHT + 1];
};

#endif
