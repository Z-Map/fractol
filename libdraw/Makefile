# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/03 18:39:00 by qloubier          #+#    #+#              #
#    Updated: 2016/11/01 23:13:44 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPSYS=$(shell uname -s)
CC=gcc
CFLAGS=-Wall -Werror -Wextra
ifdef DEBUG
	CFLAGS+=-g3 -fsanitize=address
endif
ifdef OPTI
	CFLAGS+=-Ofast
endif
CHECK_MODE=off
NAME=libdraw.a
INCDIR=-I./include\
	   -I../libft\
	   -I../minilibx\
	   -I../mathex/include
ifeq ($(OPSYS),Linux)
	INCDIR+=-Ios_config/linux
else
	INCDIR+= -Ios_config/mac
endif
OBJ=draw_init.o\
	draw_free.o\
	draw_hook.o\
	draw_clip.o\
	draw_exit.o\
	draw_window.o\
	draw_canvas.o\
	draw_texture.o\
	draw_render.o\
	draw_pixel.o\
	draw_gradient.o\
	draw_color.o\
	draw_point.o\
	draw_line.o

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
