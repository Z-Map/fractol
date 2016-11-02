/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 17:50:53 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:28:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

void			up_iteration(t_frc *frc)
{
	if (frc->ctx.mxi > frc->params.maxiter)
		return ;
	frc->ctx.mxi += 32;
	frc->ctx.activekey |= K_NEEDREFRESH;
	if (!(frc->params.flags & DISP_KCODE))
		return ;
	ft_putnbr((int)frc->ctx.mxi);
	ft_putendl(" iterations");
}

void			down_iteration(t_frc *frc)
{
	if (frc->ctx.mxi <= 32)
		return ;
	frc->ctx.mxi -= 32;
	frc->ctx.activekey |= K_NEEDREFRESH;
	if (!(frc->params.flags & DISP_KCODE))
		return ;
	ft_putnbr((int)frc->ctx.mxi);
	ft_putendl(" iterations");
}
