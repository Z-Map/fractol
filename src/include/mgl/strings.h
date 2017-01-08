/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 05:02:29 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/01 08:34:35 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGL_STRINGS_H
# define MGL_STRINGS_H

# include "mgl/data/char.h"
# include "mgl/data/string.h"
# include "mgl/data/charatlas.h"

mglca		mgl_ttf_to_charatlas(const char *ttfpath, int *chartab, size_t len);

mglstr		*mgl_cstrtomglstr(mglca *charatlas, const char *str);

void		mgl_drawcstr(mglca *ca_ascii, const char *str, v2f pos, float size);
void		mgl_drawmglstr(mglca *ca, mglstr *str, v2f pos, float size);

#endif
