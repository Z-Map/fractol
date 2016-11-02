/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:05:20 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:46:36 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>
# include "mem/libft_memory.h"
# include "str/libft_string.h"
# include "lst/libft_list.h"

# ifndef BUFF_SIZE
#  define BUFF_SIZE 64
# endif

# if BUFF_SIZE < 64
#  define GROW_SIZE 64
# else
#  define GROW_SIZE BUFF_SIZE
# endif
# if BUFF_SIZE > 128
#  define START_SIZE BUFF_SIZE
# else
#  define START_SIZE 128
# endif

typedef unsigned int	t_idx;

typedef struct			s_gnl_buffer
{
	int					fd;
	t_idx				buf_size;
	t_idx				cursor;
	char				*strb;
}						t_gnlb;

int						ft_get_line(int const fd, char **line);
int						ft_atoi (const char *str);
char					*ft_itoa(int n);
void					ft_putchar (char c);
void					ft_putstr (char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);

#endif
