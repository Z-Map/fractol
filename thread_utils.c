/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 15:19:53 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:24:24 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "fractol.h"

int			frac_condwait(pthread_mutex_t *m, pthread_cond_t *c,
				void (*f)(void *), void *arg)
{
	pthread_mutex_lock(m);
	pthread_cond_wait(c, m);
	if (f)
		f(arg);
	pthread_mutex_unlock(m);
	return (1);
}
