/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 02:25:04 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/22 03:20:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mgl/shaders.h"

mglsha		*mgl_compile_shader(mglsha *shdr)
{
	GLint	result = GL_FALSE;
	int		error_len = 0;
	char	*err_msg = NULL;

	if (!shdr->vshid)
		shdr->vshid = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shdr->vshid, 1, &(shdr->vsh) , NULL);
	glCompileShader(shdr->vshid);
	glGetShaderiv(shdr->vshid, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shdr->vshid, GL_INFO_LOG_LENGTH, &error_len);
	if(error_len)
	{
		err_msg = malloc(error_len + 1);
		err_msg[error_len] = '\0';
		glGetShaderInfoLog(shdr->vshid, error_len, NULL, err_msg);
		printf("Vertex shader compile : %s\n", err_msg);
		free(err_msg);
	}
	if (!shdr->fshid)
		shdr->fshid = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shdr->fshid, 1, &(shdr->fsh) , NULL);
	glCompileShader(shdr->fshid);
	glGetShaderiv(shdr->fshid, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shdr->fshid, GL_INFO_LOG_LENGTH, &error_len);
	if(error_len)
	{
		err_msg = malloc(error_len + 1);
		err_msg[error_len] = '\0';
		glGetShaderInfoLog(shdr->fshid, error_len, NULL, err_msg);
		printf("Fragment shader compile : %s\n", err_msg);
		free(err_msg);
	}
	if (!shdr->id)
		shdr->id = glCreateProgram();
	glAttachShader(shdr->id, shdr->vshid);
	glAttachShader(shdr->id, shdr->fshid);
	glLinkProgram(shdr->id);
	glGetProgramiv(shdr->id, GL_LINK_STATUS, &result);
	glGetProgramiv(shdr->id, GL_INFO_LOG_LENGTH, &error_len);
	if(error_len)
	{
		err_msg = malloc(error_len + 1);
		err_msg[error_len] = '\0';
		glGetShaderInfoLog(shdr->vshid, error_len, NULL, err_msg);
		printf("Program link : %s\n", err_msg);
		free(err_msg);
	}
	return (shdr);
}
