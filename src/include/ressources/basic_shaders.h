/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_shaders.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:32:54 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/15 15:39:42 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_SHADERS_H
#define BASIC_SHADERS_H

struct				mglw_shader
{
	const char		*vsh;
	const char		*fsh;
};

struct mglw_shader	drawimage2d_shader = (struct mglw_shader){
	.vsh = "",
	.fsh = ""
};

#endif
