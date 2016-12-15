# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 05:39:55 by qloubier          #+#    #+#              #
#    Updated: 2016/12/15 05:47:37 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFLST = GL_RED \
	GL_RG \
	GL_RGB \
	GL_BGR \
	GL_RGBA \
	GL_BGRA \
	GL_STENCIL_INDEX \
	GL_DEPTH_COMPONENT \
	GL_DEPTH_STENCIL \
	GL_BYTE \
	GL_UNSIGNED_BYTE \
	GL_INT \
	GL_UNSIGNED_INT \
	GL_FLOAT

.PHONY: hfile

all: hfile

hfile:
	echo "" >  mglw_gldef.h
	$(MAKE) $(DEFLST)

$(DEFLST):
	@grep -h " $@ " ../lib/glload/include/glload/*.h >> mglw_gldef.h
