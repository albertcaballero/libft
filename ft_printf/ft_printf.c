/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impresora.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:15:11 by alcaball          #+#    #+#             */
/*   Updated: 2023/12/02 11:29:26 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isvar(const char c)
{
	int		j;
	char	*varset;

	varset = "cspdiuxX%";
	j = 0;
	while (varset[j] != 0)
	{
		if (c == varset[j])
			return (1);
		j++;
	}
	return (0);
}

int	porc(int fd, char id, va_list varg)
{
	int		ret;

	ret = 0;
	if (id == 'c')
		ret = int_putchar_fd((char) va_arg(varg, int), fd);
	else if (id == 's')
		ret = int_putstr_fd(va_arg(varg, char *), fd);
	else if (id == 'p')
		ret = ft_put_add(va_arg(varg, size_t), fd);
	else if (id == 'd' || id == 'i')
		ret = int_putnbr_fd(va_arg(varg, int), fd);
	else if (id == 'u')
		ret = ft_putuns(va_arg(varg, unsigned int), fd);
	else if (id == 'x')
		ret = ft_puthex(va_arg(varg, int), MINUS, fd);
	else if (id == 'X')
		ret = ft_puthex(va_arg(varg, int), MAYUS, fd);
	else if (id == '%')
		ret = int_putchar_fd('%', fd);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	var;
	int		i;
	int		aux;
	int		ret;

	va_start(var, str);
	i = 0;
	ret = 0;
	while (str[i] != 0)
	{
		if (str[i] == 37 && isvar(str[++i]) == 1)
		{
			aux = porc(1, str[i++], var);
			if (aux == -1)
				return (-1);
			ret += aux - 2;
		}
		else if (str[i] != 37)
			if (int_putchar_fd(str[i++], 1) == -1)
				return (-1);
	}
	va_end (var);
	return (i + ret);
}


int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	var;
	int		i;
	int		aux;
	int		ret;

	va_start(var, str);
	i = 0;
	ret = 0;
	while (str[i] != 0)
	{
		if (str[i] == 37 && isvar(str[++i]) == 1)
		{
			aux = porc(fd, str[i++], var);
			if (aux == -1)
				return (-1);
			ret += aux - 2;
		}
		else if (str[i] != 37)
			if (int_putchar_fd(str[i++], fd) == -1)
				return (-1);
	}
	va_end (var);
	return (i + ret);
}