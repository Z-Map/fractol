/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:17:56 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/26 19:11:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_H
# define BASIC_H

# include "utils.h"

int			mxabs(int a);
int			mxabsf(float a);
int			mxmax(int a, int b);
int			mxmin(int a, int b);
t_ui		mxmaxu(t_ui a, t_ui b);
t_ui		mxminu(t_ui a, t_ui b);
int			mxmaxf(float a, float b);
int			mxminf(float a, float b);
void		swap(unsigned int *a, unsigned int *b);
void		swapf(float *a, float *b);
int			modz(int a, int b);
int			modzu(t_ui a, t_ui b);

#endif
