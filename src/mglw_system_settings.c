/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mglw_system_settings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 00:28:32 by map               #+#    #+#             */
/*   Updated: 2016/11/21 18:17:29 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern.h"

int			mglw_getsetting(mglws setting)
{
	mglw_sys *const	sys = MGLWgetsys();

	return (sys->settings[setting]);
}

void		mglw_setsetting(mglws setting, int value)
{
	mglw_sys *const	sys = MGLWgetsys();

	sys->settings[setting] = value;
}
