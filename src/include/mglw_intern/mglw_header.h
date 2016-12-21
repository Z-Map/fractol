/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mglw_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:36:23 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/21 15:36:31 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGLW_HEADER_H
#define MGLW_HEADER_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "glload/gl_all.h"
#include "glload/gl_load.h"
#include "GLFW/glfw3.h"

#include "mglw/mglw_proto.h"

typedef unsigned char	uchar;
typedef unsigned int	uint;
typedef unsigned long	ulong;

#include "mglw/data/system.h"
#include "mglw/data/image.h"
#include "mglw/data/texture.h"
#include "mglw/data/window.h"

#endif
