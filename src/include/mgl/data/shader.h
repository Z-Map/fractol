/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 20:19:31 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/20 18:01:04 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGL_SHADER_H
#define MGL_SHADER_H

#include "glload/gl_2_1.h"

typedef struct				mgl_shader
{
	GLuint					id;
	GLuint					vshid;
	GLuint					fshid;
	const char				*vsh;
	const char				*fsh;
}							mglsha;

# endif
