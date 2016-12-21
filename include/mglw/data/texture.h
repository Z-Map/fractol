/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:02:49 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/21 14:05:26 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGL_TEXTURE_TYPE_H
#define MGL_TEXTURE_TYPE_H

# include "mglw/mglw_proto.h"
# include "mglw/data/image.h"

struct				mlg_texture
{
	mglimg			cpuimage;
	unsigned int	texid;
	GLenum			format;
};

struct				mlgw_texlayer
{
	mgltex			texture;
	unsigned int	fbid;
};

#endif
