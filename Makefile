# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/03 18:39:00 by qloubier          #+#    #+#              #
#    Updated: 2016/12/21 15:48:49 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPSYS		= $(shell uname -s)
NAME		= libmglw.a
LINKNAME	= mglw
PROJECTNAME	= mglw
SILENT		= @
CFLAGS		= -Wall -Werror -Wextra

ifndef CC
  CC=clang
endif

ifndef config
  config=release
endif
ifeq ($(config),debug)
  CFLAGS+=-g -fsanitize=address
  LIBSUFIX=D
endif
ifeq ($(config),release)
  CFLAGS+=-Ofast
  LIBSUFIX=
endif

INCDIR=-Iinclude -Isrc/include -I$(LIBDIR)/glfw/include -I$(LIBDIR)/glload/include
LIBDIR=lib
BUILDDIR=build
SRCDIR=src
SRCS=system.c\
	system/settings.c\
	system/wlst.c\
	system/ilst.c\
	window.c\
	window/event.c\
	window/layer.c\
	window/legacy.c\
	window/opengl3.c\
	window/opengl4.c\
	window/vulkan.c\
	image.c\
	texture.c\
	image_loader.c\
	error.c
OBJ=$(subst /,~,$(SRCS:%.c=%.o))

INTERN_SRCS	= $(SRCS:%=$(SRCDIR)/%)
INTERN_OBJ	= $(OBJ:%=$(BUILDDIR)/mglw_%)
INTERN_DEP	= $(INTERN_OBJ:%.o=%.d)
BOBJ_GUARD	= off
ALLOBJ		= $(INTERN_OBJ)
OSXLIBS		= -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
TESTSRC		= test/movesquare.c

.PHONY: all clean fclean re $(TESTSRC) include/mglw_keys.h $(INTERN_DEP)

all: $(NAME)
	@#echo "$(INTERN_OBJ)"

include/mglw_keys.h: glfw/include/GLFW/glfw3.h
	printf "#ifndef MGLW_KEYS_H\n# define MGLW_KEYS_H\n\n" > include/mglw_keys.h
	cat glfw/include/GLFW/glfw3.h | grep "#define GLFW_KEY" | sed "s/GLFW/MGLW/" >> include/mglw_keys.h
	printf "\n#endif\n" >> include/mglw_keys.h

$(BUILDDIR):
	$(SILENT)mkdir -p $(BUILDDIR)

$(BUILDDIR)/Makefile:
	$(SILENT)cd build && cmake ../$(LIBDIR)/glfw

$(BUILDDIR)/src/libglfw3.a: $(BUILDDIR)/Makefile
	$(SILENT)$(MAKE) -s -C $(BUILDDIR)

$(BUILDDIR)/libglload.a:
	$(SILENT)$(MAKE) -s -C $(LIBDIR)/glload BUILDDIR=$(CURDIR)/$(BUILDDIR) config=$(config)

$(NAME): $(BUILDDIR) $(BUILDDIR)/src/libglfw3.a \
	$(BUILDDIR)/libglload.a $(INTERN_OBJ)
ifeq ($(BOBJ_GUARD),off)
	$(SILENT)$(MAKE) -s $(NAME) BOBJ_GUARD=on
else
	$(SILENT)cp $(BUILDDIR)/src/libglfw3.a ./$(NAME)
	$(SILENT)ar -rcs $(NAME) $(ALLOBJ) $(BUILDDIR)/gl*.o
	$(SILENT)sed "s/-lglfw3/-l$(LINKNAME)/" $(BUILDDIR)/src/glfw3.pc > ./$(LINKNAME).pc
endif

$(INTERN_OBJ):
ifeq ($(BOBJ_GUARD),on)
	@printf "\e[33mCompile $@\e[31m\e[32D"
	$(SILENT)$(CC) -MMD -MP $(CFLAGS) $(INCDIR) -o $@ -c $(subst ~,/,$(@:$(BUILDDIR)/mglw_%.o=$(SRCDIR)/%.c))
	@printf "\e[m[\e[32mok\e[m] \e[35m$@\e[m compiled !\e(B\e[m\n"
endif

-include $(INTERN_OBJ:%.o=%.d)

libclean:
	@printf "\e[31mCleaning lib files ...\e(B\e[m\n"
	$(SILENT)rm -rf $(BUILDDIR)/src/libglfw3.a
	$(SILENT)rm -rf $(BUILDDIR)/libglload.a $(BUILDDIR)/gl_load*.o $(BUILDDIR)/glx_load*.o

clean:
	@printf "\e[31mCleaning compile files ...\e(B\e[m\n"
	$(SILENT)rm -f $(INTERN_OBJ) $(INTERN_DEP)

fclean: clean
	@printf "\e[31mCleaning $(NAME) ...\e(B\e[m\n"
	$(SILENT)rm -f $(NAME)

re: fclean all

$(TESTSRC):
ifeq ($(OPSYS),Linux)
	$(CC) -o test_mglw $@ $(CFLAGS) -Iinclude -L./ -lGL $(shell pkg-config --static --libs mglw.pc)
else
	$(CC) -o test_mglw $@ $(CFLAGS) -Iinclude -L./ -lmglw $(OSXLIBS)
endif
	./test_mglw

test: $(NAME)
	$(MAKE) $(TESTSRC)
