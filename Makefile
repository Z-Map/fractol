# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/03 18:39:00 by qloubier          #+#    #+#              #
#    Updated: 2016/11/01 23:13:37 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPSYS=$(shell uname -s)
FANCY_OUT=on
CC=gcc
CFLAGS=-g -Wall -Werror -Wextra
ifdef DEBUG
	CFLAGS+=-g3 -fsanitize=address
endif
ifdef OPTI
	CFLAGS+=-Ofast
endif
NAME=fractol
INCDIR=-Ilibdraw/include\
	   -Ilibft\
	   -Iminilibx\
	   -Imathex/include

LIBDIR=-Llibdraw\
	   -Llibft\
	   -Lminilibx\
	   -Lmathex

UNILIBS=-lpthread -ldraw -lmathex -lm -lft -lmlx
MACLIBS=-framework OpenGL -framework AppKit
LINUXLIBS=-lXext -lX11 -lbsd
ifeq ($(OPSYS),Linux)
	LIBS=$(UNILIBS) $(LINUXLIBS)
	INCDIR+=-Ilibdraw/os_config/linux
else
	LIBS=$(UNILIBS) $(MACLIBS)
	INCDIR+= -Ilibdraw/os_config/mac
endif
LIBTARGET=libft/libft.a minilibx/libmlx.a libdraw/libdraw.a mathex/libmathex.a

OBJ=main.o\
	parser.o\
	color.o\
	colorgen.o\
	colorgrad.o\
	colorparse.o\
	context.o\
	events.o\
	mouse.o\
	mandlebrot.o\
	burningship.o\
	julia.o\
	customfrac.o\
	render.o\
	iteration.o\
	thread.o\
	thread_utils.o\
	thread_manager.o\
	manager.o\
	view.o\
	fractol_expose.o\
	fractol.o

all: check $(LIBTARGET) $(NAME)

.PHONY: all clean fclean re check

check:
	@$(shell $(MAKE) -s -C libft libft.a CHECK_MODE=on FANCY_OUT=off)
	@$(shell $(MAKE) -s -C libdraw libdraw.a CHECK_MODE=on)
	@$(shell $(MAKE) -s -C mathex libmathex.a CHECK_MODE=on)
	@$(shell $(MAKE) -s -C minilibx libmlx.a CHECK_MODE=on)

ifeq ($(FANCY_OUT),on)

$(NAME): $(OBJ)
	@printf "Compile $@ ...\e[31m"
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(INCDIR) $(LIBDIR) $(LIBS)
	@printf "\e[32D\e[32m ______              _           _\n\
|  ____|            | |         | |\n\
| |__ _ __ __ _  ___| |_    ___ | |\n\
|  __| '__/ _\` |/ __| __|  / _ \| |\n\
| |  | | | (_| | (__| |_  | (_) | |\n\
|_|  |_|  \__,_|\___|\__|  \___/|_|\n\e(B\e[m\n"

$(LIBTARGET):
	@printf "\e[33mCall $@ : \e[31m"
	@$(MAKE) -s -C $(shell dirname $@) FANCY_OUT=off
	@printf "\e[32D\e[m[\e[32mok\e[m] $@ is \e[32mgood\e(B\e[m\n"

%.o: %.c
	@printf "\e[33mCompile $@\e[31m"
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCDIR)
	@printf "\e[32D\e[m[\e[32mok\e[m] \e[35m$@\e[m compiled !\e(B\e[m\n"

clean:
	@printf "\e[31mCleaning compile files ...\e(B\e[m\n"
	@rm -rf $(OBJ)
	@printf "\e[31mCleaning libs compile files ...\e(B\e[m\n"
	@$(MAKE) -s -C libdraw clean
	@$(MAKE) -s -C libft clean FANCY_OUT=off
	@$(MAKE) -s -C minilibx clean
	@$(MAKE) -s -C mathex clean

fclean:
	@printf "\e[31mCleaning $(NAME) & compile files ...\e(B\e[m\n"
	@rm -rf $(NAME) $(OBJ)
	@printf "\e[31mCleaning libs & libs compile files ...\e(B\e[m\n"
	@$(MAKE) -s -C libdraw fclean
	@$(MAKE) -s -C libft fclean FANCY_OUT=off
	@$(MAKE) -s -C minilibx clean
	@$(MAKE) -s -C mathex fclean
	@rm -rf minilibx/libmlx.a
	@rm -rf mathex/libmathex.a

else

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(INCDIR) $(LIBDIR) $(LIBS)

$(LIBTARGET):
	@$(MAKE) -C $(shell dirname $@) FANCY_OUT=off

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCDIR)

clean:
	rm -rf $(OBJ)
	@$(MAKE) -C libdraw clean
	@$(MAKE) -C libft clean FANCY_OUT=off
	@$(MAKE) -C minilibx clean
	@$(MAKE) -C mathex clean

fclean: clean
	rm -rf $(OBJ) $(NAME)
	@$(MAKE) -C libdraw fclean
	@$(MAKE) -C libft fclean FANCY_OUT=off
	@$(MAKE) -C minilibx clean
	@$(MAKE) -C mathex fclean
	rm -rf minilibx/libmlx.a
	rm -rf mathex/libmathex.a

endif

re: fclean all
