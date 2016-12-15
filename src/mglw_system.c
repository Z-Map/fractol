/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mglw_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 00:28:32 by map               #+#    #+#             */
/*   Updated: 2016/12/15 01:24:40 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern.h"

static mglw_sys		mglw_Singletone_System = (mglw_sys){
	.error = 0, .wlst = NULL, .ilst = NULL,
	.settings={
		GLFW_KEY_UNKNOWN,
		MGLW_LEGACY_MODE, 0,
		MGLWI_NONE, 3, MGLW_RGB,
		MGLWI_NONE, MGLW_RGB,
		0 }
};

mglw_sys	*MGLWgetsys()
{
	return (&mglw_Singletone_System);
}

int			mglw_init()
{
	glfwSetErrorCallback(mglw_seterror);
	if (!glfwInit())
		return (0);
	return (1);
}

int			mglw_close(mglw_sys *sys)
{
	int		i;

	i = MGLWdelallwin(sys);
	i += MGLWdelallimg();
	glfwTerminate();
	return (i);
}
