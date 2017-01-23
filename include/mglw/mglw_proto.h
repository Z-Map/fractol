/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mglw_proto.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 04:23:16 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/23 10:48:35 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGLW_PROTO_H
# define MGLW_PROTO_H

# define MGLW_KEY_UNKNOWN            -1
# define MGLW_KEY_SPACE              32
# define MGLW_KEY_APOSTROPHE         39  /* ' */
# define MGLW_KEY_COMMA              44  /* , */
# define MGLW_KEY_MINUS              45  /* - */
# define MGLW_KEY_PERIOD             46  /* . */
# define MGLW_KEY_SLASH              47  /* / */
# define MGLW_KEY_0                  48
# define MGLW_KEY_1                  49
# define MGLW_KEY_2                  50
# define MGLW_KEY_3                  51
# define MGLW_KEY_4                  52
# define MGLW_KEY_5                  53
# define MGLW_KEY_6                  54
# define MGLW_KEY_7                  55
# define MGLW_KEY_8                  56
# define MGLW_KEY_9                  57
# define MGLW_KEY_SEMICOLON          59  /* ; */
# define MGLW_KEY_EQUAL              61  /* = */
# define MGLW_KEY_A                  65
# define MGLW_KEY_B                  66
# define MGLW_KEY_C                  67
# define MGLW_KEY_D                  68
# define MGLW_KEY_E                  69
# define MGLW_KEY_F                  70
# define MGLW_KEY_G                  71
# define MGLW_KEY_H                  72
# define MGLW_KEY_I                  73
# define MGLW_KEY_J                  74
# define MGLW_KEY_K                  75
# define MGLW_KEY_L                  76
# define MGLW_KEY_M                  77
# define MGLW_KEY_N                  78
# define MGLW_KEY_O                  79
# define MGLW_KEY_P                  80
# define MGLW_KEY_Q                  81
# define MGLW_KEY_R                  82
# define MGLW_KEY_S                  83
# define MGLW_KEY_T                  84
# define MGLW_KEY_U                  85
# define MGLW_KEY_V                  86
# define MGLW_KEY_W                  87
# define MGLW_KEY_X                  88
# define MGLW_KEY_Y                  89
# define MGLW_KEY_Z                  90
# define MGLW_KEY_LEFT_BRACKET       91  /* [ */
# define MGLW_KEY_BACKSLASH          92  /* \ */
# define MGLW_KEY_RIGHT_BRACKET      93  /* ] */
# define MGLW_KEY_GRAVE_ACCENT       96  /* ` */
# define MGLW_KEY_WORLD_1            161 /* non-US #1 */
# define MGLW_KEY_WORLD_2            162 /* non-US #2 */
# define MGLW_KEY_ESCAPE             256
# define MGLW_KEY_ENTER              257
# define MGLW_KEY_TAB                258
# define MGLW_KEY_BACKSPACE          259
# define MGLW_KEY_INSERT             260
# define MGLW_KEY_DELETE             261
# define MGLW_KEY_RIGHT              262
# define MGLW_KEY_LEFT               263
# define MGLW_KEY_DOWN               264
# define MGLW_KEY_UP                 265
# define MGLW_KEY_PAGE_UP            266
# define MGLW_KEY_PAGE_DOWN          267
# define MGLW_KEY_HOME               268
# define MGLW_KEY_END                269
# define MGLW_KEY_CAPS_LOCK          280
# define MGLW_KEY_SCROLL_LOCK        281
# define MGLW_KEY_NUM_LOCK           282
# define MGLW_KEY_PRINT_SCREEN       283
# define MGLW_KEY_PAUSE              284
# define MGLW_KEY_F1                 290
# define MGLW_KEY_F2                 291
# define MGLW_KEY_F3                 292
# define MGLW_KEY_F4                 293
# define MGLW_KEY_F5                 294
# define MGLW_KEY_F6                 295
# define MGLW_KEY_F7                 296
# define MGLW_KEY_F8                 297
# define MGLW_KEY_F9                 298
# define MGLW_KEY_F10                299
# define MGLW_KEY_F11                300
# define MGLW_KEY_F12                301
# define MGLW_KEY_F13                302
# define MGLW_KEY_F14                303
# define MGLW_KEY_F15                304
# define MGLW_KEY_F16                305
# define MGLW_KEY_F17                306
# define MGLW_KEY_F18                307
# define MGLW_KEY_F19                308
# define MGLW_KEY_F20                309
# define MGLW_KEY_F21                310
# define MGLW_KEY_F22                311
# define MGLW_KEY_F23                312
# define MGLW_KEY_F24                313
# define MGLW_KEY_F25                314
# define MGLW_KEY_KP_0               320
# define MGLW_KEY_KP_1               321
# define MGLW_KEY_KP_2               322
# define MGLW_KEY_KP_3               323
# define MGLW_KEY_KP_4               324
# define MGLW_KEY_KP_5               325
# define MGLW_KEY_KP_6               326
# define MGLW_KEY_KP_7               327
# define MGLW_KEY_KP_8               328
# define MGLW_KEY_KP_9               329
# define MGLW_KEY_KP_DECIMAL         330
# define MGLW_KEY_KP_DIVIDE          331
# define MGLW_KEY_KP_MULTIPLY        332
# define MGLW_KEY_KP_SUBTRACT        333
# define MGLW_KEY_KP_ADD             334
# define MGLW_KEY_KP_ENTER           335
# define MGLW_KEY_KP_EQUAL           336
# define MGLW_KEY_LEFT_SHIFT         340
# define MGLW_KEY_LEFT_CONTROL       341
# define MGLW_KEY_LEFT_ALT           342
# define MGLW_KEY_LEFT_SUPER         343
# define MGLW_KEY_RIGHT_SHIFT        344
# define MGLW_KEY_RIGHT_CONTROL      345
# define MGLW_KEY_RIGHT_ALT          346
# define MGLW_KEY_RIGHT_SUPER        347
# define MGLW_KEY_MENU               348
# define MGLW_KEY_LAST               GLFW_KEY_MENU

typedef enum	mglw_settings
{
	MGLWS_EXITKEY		= 0,
	MGLWS_DEFAULT_WM,
	MGLWS_DEFAULT_WWIDTH,
	MGLWS_DEFAULT_WHEIGHT,
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
	MGLW_TF_UNDEFINED	= 0,
	MGLW_RED			= 0x1903, // GL_RED
	MGLW_RG				= 0x8227, // GL_RG
	MGLW_RGB			= 0x1907, // GL_RGB
	MGLW_BGR			= 0x80E0, // GL_BGR
	MGLW_RGBA			= 0x1908, // GL_RGBA
	MGLW_BGRA			= 0x80E1, // GL_BGRA
	MGLW_STEN			= 0x1901, // GL_STENCIL_INDEX
	MGLW_DEPTH			= 0x1902, // GL_DEPTH_COMPONENT
	MGLW_DEPTH_STEN		= 0x84F9  // GL_DEPTH_STENCIL
}				mglw_tf;

typedef enum	mglw_texture_type
{
	MGLW_TT_DONTCARE	= 0,
	MGLW_BYTE			= 0x1400, // GL_BYTE
	MGLW_UBYTE			= 0x1401, // GL_UNSIGNED_BYTE
	MGLW_INT			= 0x1404, // GL_INT
	MGLW_UINT			= 0x1405, // GL_UNSIGNED_INT
	MGLW_FLOAT			= 0x1406  // GL_FLOAT
}				mglw_tt;

typedef enum	mglwin_mode
{
	MGLW_NONE_MODE		= 0,
	MGLW_LEGACY_MODE	= 1,
	MGLW_OPENGL3_MODE	= 2,
	MGLW_OPENGL4_MODE	= 3,
	MGLW_VULKAN_MODE	= 4
}				mglw_m;

typedef enum	mglwin_flag
{
	MGLW_NONE			= 0,
	MGLW_2DLAYER		= 1,
	MGLW_UNKNOWN		= 1 << 1,
	MGLW_DRAWTOOLS		= 1 << 2,
	MGLW_STOP			= 1 << 3,
	MGLW_FULLSCREEN		= 1 << 4,
	MGLW_FULLRES		= 1 << 5,
	MGLW_WINDATAFLAGS	= MGLW_2DLAYER | MGLW_DRAWTOOLS |
		MGLW_FULLSCREEN | MGLW_FULLRES
}				mglw_f;

typedef enum	mglw_imgflag
{
	MGLWI_NONE			= 0,
	MGLWI_DYNAMIC		= 1,
	MGLWI_LOADED		= 1 << 1,
	MGLWI_LOAD			= MGLWI_DYNAMIC | MGLWI_LOADED,
	MGLWI_LAYER			= 1 << 2,
	MGLWI_TEXTURE		= 1 << 3,
	MGLWI_TEXLAY		= MGLWI_LAYER | MGLWI_TEXTURE,
	MGLWI_INT			= 1 << 4,
	MGLWI_FLOAT			= 1 << 5,
	MGLWI_NOALLOC		= 1 << 6,
	MGLWI_USERALLOC		= MGLWI_NOALLOC | MGLWI_DYNAMIC,
	MGLWI_LOADFLAG		= MGLWI_USERALLOC,
	MGLWI_USERFLAG		= MGLWI_LOADFLAG | MGLWI_INT | MGLWI_FLOAT
}				mglw_if;

/* -------------------------------------------------------------------------- */

/* MiniGLwin type prototype */

typedef struct mglw_win_data		mglw_wd;
typedef struct miniGLwin_system		mglw_sys;
typedef struct mglw_win				mglwin;
typedef struct mlgw_layertex		mgltexlayer;

/* MiniGL type prototype */

typedef struct mlg_image			mglimg;
typedef struct mlg_texture			mgltex;

# ifndef _glfw3_h_
typedef void						GLFWwindow;
# endif

# ifndef __gl_h_
typedef unsigned int				GLuint;
typedef unsigned int				GLenum;
# endif

#endif
