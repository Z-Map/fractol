/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 08:30:26 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/01 08:35:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGL_STRING_H
#define MGL_STRING_H

# include <string.h>

typedef struct		mgl_string
{
	size_t			length;
	char			*str;
}					mglstr;

#endif
