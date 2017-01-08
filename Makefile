# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/03 18:39:00 by qloubier          #+#    #+#              #
#    Updated: 2017/01/05 07:23:38 by qloubier         ###   ########.fr        #
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

SRCS	=\
	system.c\
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
	error.c\
	mgl/shaders.c\
	mgl/strings/atlas.c\
	mgl/strings/fromttf.c

SHADERS	= pixelbox.vert pixelbox.frag\

TESTSRC	= test/movesquare.c\
		test/font.c

OBJ=$(subst /,~,$(SRCS:%.c=%.o))

INTERN_SRCS	= $(SRCS:%=$(SRCDIR)/%)
INTERN_OBJ	= $(OBJ:%=$(BUILDDIR)/mglw_%)
INTERN_DEP	= $(INTERN_OBJ:%.o=%.d)
INTERN_SHA	= $(SHADERS:%=$(SRCDIR)/include/mgl/ressources/shaders/%.h)
BOBJ_GUARD	= $(shell if [ -d $(BUILDDIR) ]; then printf "on"; else printf "off"; fi)
ALLOBJ		= $(INTERN_OBJ)
OSXLIBS		= -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
GLLOAD_OBJ	= $(BUILDDIR)/gl_load.o $(BUILDDIR)/gl_load_cpp.o
ifeq ($(OPSYS),Linux)
  GLLOAD_OBJ += $(BUILDDIR)/glx_load.o $(BUILDDIR)/glx_load_cpp.o
endif

.PHONY: all clean fclean re $(TESTSRC) include/mglw_keys.h $(INTERN_DEP)

all: $(NAME)

include/mglw_keys.h: glfw/include/GLFW/glfw3.h Makefile
	printf "#ifndef MGLW_KEYS_H\n# define MGLW_KEYS_H\n\n" > include/mglw_keys.h
	cat glfw/include/GLFW/glfw3.h | grep "#define GLFW_KEY" | sed "s/GLFW/MGLW/" >> include/mglw_keys.h
	printf "\n#endif\n" >> include/mglw_keys.h

$(INTERN_SHA): %.h: % Makefile
	@printf "\e[33mShader $<\e[31m\e[80D"
	$(SILENT)printf "(const char[]){" > $@
	$(SILENT)xxd -i $< | grep -x "[0-9a-fx, ]*" | head -c -1 | tail -c +3 >> $@
	$(SILENT)printf " , 0x00}" >> $@
	@printf "\e[m[\e[32mok\e[m] \e[35m$@\e[m\e(B\e[m\n"

$(BUILDDIR):
	$(SILENT)mkdir -p $(BUILDDIR)

$(BUILDDIR)/Makefile:
	$(SILENT)cd build && cmake ../$(LIBDIR)/glfw

$(BUILDDIR)/src/libglfw3.a: $(BUILDDIR)/Makefile
	$(SILENT)$(MAKE) -s -C $(BUILDDIR)

$(GLLOAD_OBJ):
	$(SILENT)$(MAKE) -s -C $(LIBDIR)/glload $(CURDIR)/$@ BUILDDIR=$(CURDIR)/$(BUILDDIR) config=$(config)

$(NAME): $(BUILDDIR) $(INTERN_SHA) $(BUILDDIR)/src/libglfw3.a $(INTERN_OBJ) $(GLLOAD_OBJ) Makefile
ifeq ($(BOBJ_GUARD),off)
	$(SILENT)$(MAKE) -s $(NAME) BOBJ_GUARD=on
else
	$(SILENT)cp $(BUILDDIR)/src/libglfw3.a ./$(NAME)
	$(SILENT)ar -rcs $(NAME) $(ALLOBJ) $(GLLOAD_OBJ)
	$(SILENT)sed "s/-lglfw3/-l$(LINKNAME)/" $(BUILDDIR)/src/glfw3.pc > ./$(LINKNAME).pc
	@printf "\e[m[\e[32mok\e[m] \e[35m$@\e[m compiled !\e(B\e[m\n"
endif

$(INTERN_OBJ): Makefile
ifeq ($(BOBJ_GUARD),on)
	@printf "\e[33mCompile $@\e[31m\e[80D"
	$(SILENT)$(CC) -MMD -MP $(CFLAGS) $(INCDIR) -o $@ -c $(subst ~,/,$(@:$(BUILDDIR)/mglw_%.o=$(SRCDIR)/%.c))
	@printf "\e[m[\e[32mok\e[m] \e[35m$@\e[m compiled !\e(B\e[m\n"
else
	@echo "$<"
endif

-include $(INTERN_DEP)

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
	$(CC) -o test_mglw $@ $(CFLAGS) $(INCDIR) -L./ -lGL $(shell pkg-config --static --libs mglw.pc)
else
	$(CC) -o test_mglw $@ $(CFLAGS) $(INCDIR) -L./ -lmglw $(OSXLIBS)
endif
	./test_mglw

test: $(NAME)
	$(MAKE) $(TESTSRC)
