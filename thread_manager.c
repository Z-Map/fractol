/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 15:35:45 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:41:32 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <time.h>
#include "fractol.h"

static int		frac_th_draw_loop(t_thmgr *mgr, t_thctx *ctxs)
{
	int			i;

	i = -1;
	if (frac_mgr_render_request(&(mgr->ctx), &(mgr->mgr)))
	{
		pthread_mutex_unlock(&(mgr->data_acces));
		while (++i < THREADNUM)
		{
			ctxs[i].done = 0;
			frac_ctx_update(&(ctxs[i].ctx), &(mgr->mgr));
		}
		pthread_mutex_lock(&(mgr->start_mutex));
		pthread_cond_broadcast(&(mgr->drawstart));
		pthread_mutex_unlock(&(mgr->start_mutex));
	}
	else
		pthread_mutex_unlock(&(mgr->data_acces));
	return ((i == -1) ? 1 : 0);
}

static void		frac_th_internloop(t_thmgr *mgr, t_thctx *ctxs)
{
	pthread_mutex_lock(&(mgr->data_acces));
	if (mgr->mgr.activekey & K_REFRESH)
	{
		mgr->mgr.activetex = mgr->mgr.drawtex;
		mgr->ctx.img = mgr->mgr.textures[mgr->mgr.drawtex];
		mgr->view = mgr->mgr.texview[mgr->mgr.drawtex];
		mgr->mgr.activekey &= ~K_REFRESH;
		mgr->ctx.activekey = (mgr->ctx.activekey & ~K_REFRESH) | K_NEEDREFRESH;
	}
	if (frac_th_draw_loop(mgr, ctxs))
		frac_condwait(&(mgr->ref_mutex), &(mgr->refresh), NULL, NULL);
}

static void		thread_mgr_loop(t_thmgr *mgr, t_thctx *ctxs)
{
	int						i;
	int						j;
	const struct timespec	t = (struct timespec){0, 33000000L};

	i = 0;
	j = 0;
	while (!j && (i < THREADNUM))
		j = pthread_mutex_trylock(&(ctxs[i++].data_mutex));
	if (!j)
		frac_th_internloop(mgr, ctxs);
	else
		--i;
	while (--i >= 0)
		pthread_mutex_unlock(&(ctxs[i].data_mutex));
	nanosleep(&t, NULL);
}

void			*frac_thread_mgr(void *arg)
{
	pthread_t	threads[THREADNUM];
	t_thctx		ctxs[THREADNUM];
	int			i;
	t_thmgr		*mgr;

	i = -1;
	mgr = (t_thmgr *)arg;
	while (++i < THREADNUM)
	{
		ctxs[i].done = 1;
		ctxs[i].column_id = i;
		ctxs[i].mgr = mgr;
		ctxs[i].data_mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		pthread_create(&(threads[i]), NULL, &frac_thread_renderer, &(ctxs[i]));
	}
	while (!(mgr->quit))
		thread_mgr_loop(mgr, ctxs);
	i = -1;
	pthread_cond_broadcast(&(mgr->drawstart));
	while (++i < THREADNUM)
	{
		pthread_join(threads[i], NULL);
		pthread_mutex_destroy(&(ctxs[i].data_mutex));
	}
	pthread_exit(NULL);
}
