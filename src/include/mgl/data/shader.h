/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 20:19:31 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/19 21:17:13 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# if MGL_PROTO_MODE
typedef struct mgl_shader	mgl_sh;
# else

#ifndef MGL_SHADER_H
#define MGL_SHADER_H

struct						mgl_shader
{
	GLuint					id;
	GLuint					vshid;
	GLuint					fshid;
	const char				*vsh;
	const char				*fsh;
};

# endif

#endif
