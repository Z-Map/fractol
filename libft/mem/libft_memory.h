/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_memory.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 10:24:59 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/25 18:38:18 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEMORY_H
# define LIBFT_MEMORY_H
# include <string.h>

void				ft_bzero (void *s, size_t n);
void				*ft_memset (void *b, int c, size_t len);
void				*ft_memcpy (void *dst, const void *src, size_t n);
void				*ft_memccpy (void *dst, const void *src, int c, size_t n);
void				*ft_memmove (void *dst, const void *src, size_t len);
void				*ft_memchr (const void *s, int c, size_t n);
int					ft_memcmp (const void *s1, const void *s2, size_t n);
void				*ft_memdup (const void *s1, size_t n);
void				*ft_memalloc (size_t size);
void				ft_memdel (void **ap);

#endif
