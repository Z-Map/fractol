# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/03 18:39:00 by qloubier          #+#    #+#              #
#    Updated: 2017/03/24 16:17:16 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPSYS		= $(shell uname -s)
NAME		= libmglw.a
LINKNAME	= mglw
PROJECTNAME	= mglw
PROJECTPATH	= $(CURDIR)
SILENT		= @
CFLAGS		= -Wall -Werror -Wextra

ifndef CC
	CC=clang
endif

ifndef config
	config	= release
endif
ifeq ($(config),debug)
	CFLAGS	+= -g -fsanitize=address
	LIBSUFIX= D
endif
ifeq ($(config),release)
	CFLAGS	+= -Ofast
	LIBSUFIX=
endif


INCDIR		= -Iinclude -Isrc/include -I$(LIBDIR)/glfw42/include -I$(LIBDIR)/glload/include
LIBDIR		= lib
BUILDDIR	= build/$(config)
TARGETDIR	= .
SRCDIR		= src

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
	monitor.c\
	image.c\
	texture.c\
	image_loader.c\
	error.c\
	mgl/shaders.c\

SHADERS	= pixelbox.vert pixelbox.frag\

OBJ=$(subst /,~,$(SRCS:%.c=%.o))

# Intern vars
INTERN_BD	= $(PROJECTPATH)/$(BUILDDIR)
INTERN_SRCS	= $(SRCS:%=$(SRCDIR)/%)
INTERN_OBJ	= $(OBJ:%=$(INTERN_BD)/mglw_%)
INTERN_DEP	= $(INTERN_OBJ:%.o=%.d)
INTERN_SHA	= $(SHADERS:%=$(SRCDIR)/include/mgl/ressources/shaders/%.h)
BOBJ_GUARD	= $(shell if [ -d $(INTERN_BD) ]; then printf "on"; else printf "off"; fi)
ALLOBJ		= $(INTERN_OBJ)
OSXLIBS		= -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
GLLOAD_OBJ	= $(INTERN_BD)/gl_load.o $(INTERN_BD)/gl_load_cpp.o
INTERN_SHADERCOMAND=
ifeq ($(OPSYS),Linux)
	INTERN_SHADERCOMAND += | head -c -1 | tail -c +3
	GLLOAD_OBJ += $(INTERN_BD)/glx_load.o $(INTERN_BD)/glx_load_cpp.o
endif

.PHONY: all clean fclean re $(TESTSRC) include/mglw_keys.h $(INTERN_DEP) shaders

all: $(INTERN_SHA) $(TARGETDIR)/$(NAME)

shaders:
	$(SILENT)$(MAKE) -s $(INTERN_SHA)

$(INTERN_SHA): %.h: %
	@printf "\e[33mShader $<\e[31m\e[80D"
	$(SILENT)printf "(const char[]){" > $@
	$(SILENT)xxd -i $< | grep -x "[0-9a-fx, ]*" $(INTERN_SHADERCOMAND) >> $@
	$(SILENT)printf " , 0x00}" >> $@
	@printf "\e[m[\e[32mok\e[m] \e[35m$@\e[m\e(B\e[m\n"

$(INTERN_BD):
	$(SILENT)mkdir -p $(INTERN_BD)

$(INTERN_BD)/libglfw3.a:
	$(SILENT)$(MAKE) -s -C $(LIBDIR)/glfw42 BUILDDIR=$(INTERN_BD) TARGETDIR=$(INTERN_BD) config=$(config)

$(GLLOAD_OBJ):
	$(SILENT)$(MAKE) -s -C $(LIBDIR)/glload objects BUILDDIR=$(INTERN_BD) config=$(config)

$(TARGETDIR)/$(NAME): $(INTERN_SHA) $(INTERN_BD) $(INTERN_BD)/libglfw3.a $(GLLOAD_OBJ) $(INTERN_OBJ)
ifeq ($(BOBJ_GUARD),off)
	$(SILENT)$(MAKE) -s $@ BOBJ_GUARD=on
else
	$(SILENT)cp $(INTERN_BD)/libglfw3.a $@
	$(SILENT)ar -rcs $@ $(ALLOBJ) $(GLLOAD_OBJ)
	@printf "\e[80D%-79.79b \e[m[\e[32mok\e[m]\n" "\e[35m$(NAME)\e[m compiled !\e(B\e[m"
endif

$(INTERN_OBJ):
ifeq ($(BOBJ_GUARD),on)
	@printf "\e[33mCompile $@\e[31m\e[80D"
	$(SILENT)$(CC) -MMD -MP $(CFLAGS) $(INCDIR) -o $@ -c $(subst ~,/,$(@:$(INTERN_BD)/mglw_%.o=$(SRCDIR)/%.c))
	@printf "\e[80D%-79.79b \e[m[\e[32mok\e[m]\n" "\e[35m$(notdir $@)\e[m compiled !\e(B\e[m"
endif

-include $(INTERN_DEP)

libclean:
	@printf "\e[31mCleaning lib files ...\e(B\e[m\n"
	$(SILENT)$(MAKE) -s -C $(LIBDIR)/glfw42 fclean BUILDDIR=$(INTERN_BD) TARGETDIR=$(INTERN_BD) config=$(config)
	$(SILENT)$(MAKE) -s -C $(LIBDIR)/glload clean BUILDDIR=$(INTERN_BD) config=$(config)

clean:
	@printf "\e[31mCleaning compile files ...\e(B\e[m\n"
	$(SILENT)rm -f $(INTERN_OBJ) $(INTERN_DEP)

fclean: clean
	@printf "\e[31mCleaning $(NAME) ...\e(B\e[m\n"
	$(SILENT)rm -f $(NAME)

re: fclean all
