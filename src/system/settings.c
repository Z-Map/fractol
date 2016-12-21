/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 00:28:32 by map               #+#    #+#             */
/*   Updated: 2016/12/21 15:27:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern/system.h"

int			mglw_getsetting(mlgw_s setting)
{
	mglw_sys *const	sys = MGLWgetsys();

	return (sys->settings[setting]);
}

void		mglw_setsetting(mlgw_s setting, int value)
{
	mglw_sys *const	sys = MGLWgetsys();

	sys->settings[setting] = value;
}
