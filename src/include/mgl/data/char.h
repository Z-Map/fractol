/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:13:19 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/01 08:18:44 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGL_CHAR_H
#define MGL_CHAR_H

typedef struct		mgl_character
{
	int				unicode;
	int				glyph;
	float			w;
	float			h;
	float			ofx;
	float			ofy;
}					mglchar;

#endif
