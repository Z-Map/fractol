/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:50:34 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/21 15:26:19 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern/system.h"
#include "mglw_intern/window.h"

int					MGLWaddwin(mglwin *win)
{
	mglw_sys *const	sys = MGLWgetsys();
	mglwin			*wins;

	if (!sys->wlst)
	{
		win->next = NULL;
		sys->wlst = win;
		return (1);
	}
	wins = sys->wlst;
	while ((wins != win) && (wins->next))
		wins = wins->next;
	if (wins == win)
		return (0);
	win->next = NULL;
	wins->next = win;
	return (1);
}

int					MGLWdelwin(mglwin *win)
{
	mglw_sys *const	sys = MGLWgetsys();
	mglwin			**wins;

	if (!sys->wlst)
		return (0);
	wins = &(sys->wlst);
	while ((*wins != win) && ((*wins)->next))
		wins = &((*wins)->next);
	if (*wins != win)
		return (0);
	*wins = win->next;
	win->next = NULL;
	return (1);
}

static void			intern_delallwin(mglwin *win, int *i)
{
	if (!win)
		return ;
	intern_delallwin(win->next, i);
	win->next = NULL;
	mglw_rmwin(win);
	++(*i);
}

int					MGLWdelallwin()
{
	mglw_sys *const	sys = MGLWgetsys();
	int				i;
	mglwin			*wins;

	if (!sys->wlst)
		return (0);
	i = 0;
	wins = sys->wlst;
	sys->wlst = NULL;
	intern_delallwin(wins, &i);
	return (i);
}
