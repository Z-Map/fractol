# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 14:33:40 by qloubier          #+#    #+#              #
#    Updated: 2016/12/22 00:21:00 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Vars
NAME	= libglload.a
BUILDDIR= .
DEFINES	= -D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS -DBOOST_ALL_NO_LIB
INCLUDES= -Iinclude -Isource
CFLAGS	=
CPPFLAGS=
ARFLAG	= -rcs

OBJS	=$(BUILDDIR)/gl_load.o
CXXOBJS	=$(BUILDDIR)/gl_load_cpp.o

OPSYS=$(shell uname -s)
ifeq ($(OPSYS),Linux)
  DEFINES	+= -DLOAD_X11
  OBJS		+= $(BUILDDIR)/glx_load.o
  CXXOBJS	+= $(BUILDDIR)/glx_load_cpp.o
else
  CFLAGS	+= -Wno-pointer-sign -Wno-deprecated-declarations
endif

# Environnement Vars
ifndef config
  config = release
endif

ifndef verbose
  SILENT = @
endif

ifndef CC
  CC = gcc
endif

ifndef CXX
  CXX = g++
endif

ifndef AR
  AR = ar
endif

ifeq ($(config),debug)
  DEFINES	+= -DDEBUG -D_DEBUG -DMEMORY_DEBUGGING
  CFLAGS	+= -g
else
  DEFINES	+= -DNDEBUG -DRELEASE
  CFLAGS	+= -O3 -fomit-frame-pointer -Wall
endif

CFLAGS		+= -MMD -MP $(DEFINES) $(INCLUDES)
CXXFLAGS	+= $(CFLAGS)
RESFLAGS	= $(DEFINES) $(INCLUDES)

ALLOBJS	= $(CXXOBJS) $(OBJS)
OAR		= $(ALLOBJS:%.o=%.d)

# Rules

.PHONY: clean fclean re objects

all: $(NAME)

objects: $(ALLOBJS)

$(OBJS): $(BUILDDIR)/%.o: source/%.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"

$(CXXOBJS): $(BUILDDIR)/%.o: source/%.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OAR)

$(NAME): $(ALLOBJS)
	@echo Linking glload
	$(SILENT) $(AR) $(ARFLAG) $(NAME) $(OBJS) $(CXXOBJS)

clean:
	@echo Cleaning glload
	$(SILENT) rm -rf $(ALLOBJS) $(OAR)

fclean: clean
	$(SILENT) rm -f  $(NAME)

re: fclean all
