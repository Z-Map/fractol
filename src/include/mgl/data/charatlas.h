/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charatlas.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 06:21:04 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/05 16:41:57 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGL_CHARATLAS_H
# define MGL_CHARATLAS_H

# include "glload/gl_all.h"
# include "mgl/data/vector.h"

typedef struct		mgl_char_atlas
{
	unsigned int	*glyphs;
	v4f				*texoffset;
	v4f				*metrics;
	size_t			length;
	v2i				box;
	float			linesize;
	GLuint			texture;
}					mglca;

#endif
