/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:12:09 by alcaball          #+#    #+#             */
/*   Updated: 2023/12/02 11:27:38 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include "../libft.h"

# define FT_PRINTF_UPPER    1
# define FT_PRINTF_LOWER    2
# define FT_PRINTF_BUFSIZE  128

typedef struct s_printf_buffer{
    char buf[FT_PRINTF_BUFSIZE];
    int idx;
    int fd;
    int bytes;
} t_pf_buf;


int		ft_printf(const char *str, ...);
int		ft_dprintf(int fd, const char *str, ...);
void    buf_add_char(char c, t_pf_buf* buf);

//put buffer
void    buf_add_char(char c, t_pf_buf* buf);
void    buffer_putstr(char *s, t_pf_buf* buf);
void    buffer_putnbr(int n, t_pf_buf* buf);
void    buffer_putuint(unsigned int n, t_pf_buf* buf);
void	ft_puthex(int num, int cse, t_pf_buf* buf);
void	ft_put_add(size_t ad, t_pf_buf* buf);



#endif
