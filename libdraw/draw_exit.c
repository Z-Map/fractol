/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:09:06 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/04 04:59:35 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"
#include <stdlib.h>

int			draw_clean_exit(void *sys, char *message)
{
	t_dsys	*ds;

	ds = (t_dsys *)sys;
	ft_putendl(message);
	ft_putendl("<<[ Start cleaning ... ]>>");
	ft_lstdel(&(ds->win_lst), &draw_free_win);
	ft_lstdel(&(ds->cvs_lst), &draw_free_cvs);
	ft_lstdel(&(ds->tex_lst), &draw_free_tex);
	ft_putendl("<<[ End cleaning ... ]>>");
	exit(0);
	return (0);
}
