/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:03:51 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/21 14:05:05 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGL_IMAGE_TYPE_H
#define MGL_IMAGE_TYPE_H

# include "mglw/mglw_proto.h"

struct				mlg_image
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	bpp;
	mglw_if			flags;
	mglw_tf			format;
	mglw_tt			type;
	size_t			memlen;
	unsigned char	*pixels;
	double			creatime;
	mglimg			*next;
};

#endif
