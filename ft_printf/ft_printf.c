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
#include <unistd.h>

static void flush_buf(t_pf_buf* buf){
    int aux;

    aux = write(buf->fd, buf->buf, buf->idx);
    if (aux < 0 || buf->bytes < 0)
        buf->bytes = -1;
    else
        buf->bytes += aux;
    buf->idx = 0;
}

void buf_add_char(char c, t_pf_buf* buf)
{
    buf->buf[buf->idx] = c;
    ++buf->idx;
    if (buf->idx >= FT_PRINTF_BUFSIZE){
        flush_buf(buf);
    }
}

static void init_buffer(t_pf_buf* buf, int fd){
    ft_bzero(buf->buf, FT_PRINTF_BUFSIZE);
    buf->bytes = 0;
    buf->idx = 0;
    buf->fd = fd;
}

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

void	handle_percentage(char id, va_list varg, t_pf_buf* buf)
{
	if (id == 'c')
		buf_add_char((char) va_arg(varg, int), buf);
	else if (id == 's')
		buffer_putstr(va_arg(varg, char *), buf);
	else if (id == 'p')
		ft_put_add(va_arg(varg, size_t), buf);
	else if (id == 'd' || id == 'i')
		buffer_putnbr(va_arg(varg, int), buf);
	else if (id == 'u')
		buffer_putuint(va_arg(varg, unsigned int), buf);
	else if (id == 'x')
		ft_puthex(va_arg(varg, int), FT_PRINTF_LOWER, buf);
	else if (id == 'X')
		ft_puthex(va_arg(varg, int), FT_PRINTF_UPPER, buf);
	else if (id == '%')
		buf_add_char('%', buf);
}


int	ft_vdprintf(int fd, const char *str, va_list var)
{
	int		i;
	t_pf_buf buffer;

	i = 0;
	init_buffer(&buffer, fd);
	while (str[i] != 0)
	{
		if (str[i] == '%' && isvar(str[++i]) == 1)
		{
			handle_percentage(str[i++], var, &buffer);
		}
		else if (str[i] != '%')
			buf_add_char(str[i++], &buffer);
	}
	flush_buf(&buffer);
	return (buffer.bytes);
}

int	ft_printf(const char *str, ...)
{
	va_list	var;
	int		ret;

	va_start(var, str);
	ret = ft_vdprintf(1, str, var);
	va_end (var);
	return (ret);
}


int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	var;
	int		ret;

	va_start(var, str);
	ret = ft_vdprintf(fd, str, var);
	va_end (var);
	return (ret);
}
