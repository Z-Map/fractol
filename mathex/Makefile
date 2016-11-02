# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/03 18:39:00 by qloubier          #+#    #+#              #
#    Updated: 2016/11/01 22:57:50 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPSYS=$(shell uname -s)
CC=gcc
CFLAGS=-Wall -Werror -Wextra
ifdef DEBUG
	CFLAGS+=-g
endif
ifdef OPTI
	CFLAGS+=-Ofast
endif
CHECK_MODE=off
NAME=libmathex.a
INCDIR=-I./include
ifeq ($(OPSYS),Linux)
	CFLAGS+=-Wno-strict-aliasing
endif
OBJ=basic.o\
	basicf.o\
	basicu.o\
	binary/bitaprox.o\
	transform/matf_multiply.o\
	transform/matf_rot.o\
	transform/matf_rotx.o\
	transform/matf_roty.o\
	transform/matf_rotz.o\
	transform/matf_scale.o\
	transform/matf_scalv.o\
	transform/matf_trans.o\
	transform/matf_utils.o\
	vector/normalize.o\
	vector/swapf.o\
	vector/swapi.o\
	vector/tov4f.o\
	vector/tov4d.o\
	vector/tov4i.o\
	vector/vec2d/add2i.o\
	vector/vec2d/sub2i.o\
	vector/vec2d/tov2f.o\
	vector/vec2d/tov2d.o\
	vector/vec2d/tov2i.o\
	vector/vec3d/add3f.o\
	vector/vec3d/add3i.o\
	vector/vec3d/div3f.o\
	vector/vec3d/div3i.o\
	vector/vec3d/mul3f.o\
	vector/vec3d/mul3i.o\
	vector/vec3d/sub3f.o\
	vector/vec3d/sub3i.o\
	vector/vec3d/tov3f.o\
	vector/vec3d/tov3d.o\
	vector/vec3d/tov3i.o

all: $(NAME)

ifeq ($(CHECK_MODE),on)

$(NAME): $(OBJ)
	rm -rf $(NAME)

%.o: %.c
	rm -f $@

else

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCDIR)

endif

.PHONY: clean fclean re
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
