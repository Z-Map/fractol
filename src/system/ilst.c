/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:50:34 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/21 15:26:21 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern/system.h"
#include "mglw_intern/image.h"

int					MGLWaddimg(mglimg *img)
{
	mglw_sys *const	sys = MGLWgetsys();
	mglimg			*imgs;

	if (!sys->ilst)
	{
		img->next = NULL;
		sys->ilst = img;
		return (1);
	}
	imgs = sys->ilst;
	while ((imgs != img) && (imgs->next))
		imgs = imgs->next;
	if (imgs == img)
		return (0);
	img->next = NULL;
	imgs->next = img;
	return (1);
}

int					MGLWdelimg(mglimg *img)
{
	mglw_sys *const	sys = MGLWgetsys();
	mglimg			**imgs;

	if (!sys->ilst)
		return (0);
	imgs = &(sys->ilst);
	while ((*imgs != img) && ((*imgs)->next))
		imgs = &((*imgs)->next);
	if (*imgs != img)
		return (0);
	*imgs = img->next;
	img->next = NULL;
	return (1);
}

static void			intern_delallimg(mglimg *img, int *i)
{
	if (!img)
		return ;
	intern_delallimg(img->next, i);
	img->next = NULL;
	mglw_rmimg(img);
	++(*i);
}

int					MGLWdelallimg()
{
	mglw_sys *const	sys = MGLWgetsys();
	int				i;
	mglimg			*imgs;

	if (!sys->ilst)
		return (0);
	i = 0;
	imgs = sys->ilst;
	sys->ilst = NULL;
	intern_delallimg(imgs, &i);
	return (i);
}
