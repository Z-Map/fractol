/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:01:01 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/21 14:09:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGLW_SYSTEM_TYPE_H
#define MGLW_SYSTEM_TYPE_H

# include "mglw/mglw_proto.h"
# include "mglw/data/window.h"

struct			miniGLwin_system
{
	int			error;
	int			padding;
	mglwin		*wlst;
	mglimg		*ilst;
	int			settings[MGLWS_LENGHT + 1];
};

#endif
