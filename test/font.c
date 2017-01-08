/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 04:05:55 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/05 18:45:57 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "mglw/mglw.h"
#include "mgl/shaders.h"
#include "mgl/ressources/shaders/basic.h"
#include "mgl/ressources/quads.h"
#include "mgl/strings.h"

int		main()
{
	const struct timespec	t = (struct timespec){0, 12000000L};
	mglwin					*win;
	mglimg					*img;
	mglca					ca;
	// mglimg					*pinguin;
	unsigned int			*tex;
	unsigned char			*catex;
	// unsigned int			x,y,i;

	if (!(mglw_init()) ||
		!(win = mglw_openwin(
			mglw_mkwin(MGLW_LEGACY_MODE, MGLW_2DLAYER),
			800, 600, "Coucou !")))
		return (-1);
	mglw_setsetting(MGLWS_EXITKEY, MGLW_KEY_ESCAPE);
	img = (mglimg *)mglw_get2dlayer(win);
	tex = (unsigned int *)img->pixels;
	// pinguin = mglw_loadimage("ping.jpg", MGLWI_NONE, 4);
	//memcpy(img->pixels, pinguin->pixels, img->memlen);
	puts("coucou1");
	ca = mgl_ttf_to_charatlas("font.ttf", NULL, 0);
	catex = (unsigned char *)ca.glyphs;
	puts("coucou2");
	// for (y = 0; y < img->y; y++){
	// for (x = 0; x < img->x; x++)
	// {
	// 	i = x + (y * 1024);
	// 	tex[x + (y * img->x)] = 0xff << 24 | catex[i] |
	// 		(catex[i] << 16) | (catex[i] << 8);
	// }
	// }
	puts("coucou3");
	while (mglwin_run(win))
		nanosleep(&t, NULL);
	mglw_close();
	return (0);
}
