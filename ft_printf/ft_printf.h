/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:12:09 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 11:33:17 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include "../libft.h"

int		ft_printf(const char *str, ...);
int		int_putnbr_fd(int n, int fd);
int		int_putchar_fd(char c, int fd);
int		int_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int		porc(char id, va_list varg);
int		ft_isneg(long n, int flag);
int		ft_puthex(int num, int cse);
int		ft_put_add(size_t ad);
int		ft_putuns(unsigned int n);

#endif