/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:18:43 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:24:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "fractol.h"

int				frac_init_thread(t_frc *frc)
{
	t_thmgr		*mgr;

	mgr = frc->thmgr;
	mgr->ctx = frc->ctx;
	mgr->quit = 0;
	mgr->data_acces = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	mgr->ref_mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	mgr->start_mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	mgr->refresh = (pthread_cond_t)PTHREAD_COND_INITIALIZER;
	mgr->drawstart = (pthread_cond_t)PTHREAD_COND_INITIALIZER;
	pthread_create(&(frc->thid), NULL, &frac_thread_mgr, (void *)mgr);
	return (1);
}

void			frac_sync_thread(t_frc *frc)
{
	t_kc		k;

	pthread_mutex_lock(&(frc->thmgr->data_acces));
	if (frc->thmgr->ctx.activekey & K_NEEDREFRESH)
	{
		frc->ctx.img = frc->thmgr->ctx.img;
		frc->texview = frc->thmgr->view;
		frac_view_push(frc);
	}
	if (frc->ctx.activekey & K_NEEDREFRESH)
		frac_ctx_sync(&(frc->ctx), &(frc->thmgr->ctx));
	if (frc->ctx.activekey & K_REFCOL)
		frc->mgr->gradient = frc->params.gradient;
	k = frc->ctx.activekey & THREAD_PUSH;
	frc->ctx.activekey &= ~(k | THREAD_K);
	frc->ctx.activekey |= frc->thmgr->ctx.activekey & THREAD_PULL;
	frc->thmgr->ctx.activekey |= k;
	pthread_mutex_unlock(&(frc->thmgr->data_acces));
	if (k & K_RENDER)
		pthread_cond_signal(&(frc->thmgr->refresh));
}

int				frac_exit_thread(t_frc *frc)
{
	frc->params.flags &= ~(MULTITHREAD | AUTOREFRESH);
	pthread_mutex_lock(&(frc->thmgr->data_acces));
	frc->thmgr->quit = 1;
	pthread_mutex_unlock(&(frc->thmgr->data_acces));
	pthread_cond_signal(&(frc->thmgr->refresh));
	pthread_join(frc->thid, NULL);
	pthread_mutex_destroy(&(frc->thmgr->data_acces));
	pthread_cond_destroy(&(frc->thmgr->refresh));
	pthread_mutex_destroy(&(frc->thmgr->ref_mutex));
	pthread_cond_destroy(&(frc->thmgr->drawstart));
	pthread_mutex_destroy(&(frc->thmgr->start_mutex));
	ft_putendl("threads quit");
	return (1);
}

void			*frac_thread_renderer(void *arg)
{
	t_thctx		*ctx;

	ctx = (t_thctx *)arg;
	while (42)
	{
		pthread_mutex_lock(&(ctx->data_mutex));
		if (!ctx->done)
		{
			frac_render(&(ctx->ctx), ctx->column_id, THREADNUM,
				&(ctx->mgr->quit));
			ctx->done = 1;
		}
		pthread_mutex_unlock(&(ctx->data_mutex));
		if (ctx->mgr->quit)
			break ;
		pthread_mutex_lock(&(ctx->mgr->start_mutex));
		pthread_cond_wait(&(ctx->mgr->drawstart), &(ctx->mgr->start_mutex));
		pthread_mutex_unlock(&(ctx->mgr->start_mutex));
	}
	pthread_mutex_lock(&(ctx->mgr->start_mutex));
	ft_putstr("-- Quit render thread ");
	ft_putnbr((int)(ctx->column_id));
	ft_putendl(" --");
	pthread_mutex_unlock(&(ctx->mgr->start_mutex));
	pthread_exit(NULL);
}
