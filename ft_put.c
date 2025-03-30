/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:51:19 by alcaball          #+#    #+#             */
/*   Updated: 2023/05/23 15:47:39 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
	return ;
}

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen((const char *) s));
	write(fd, "\n", 1);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		neg;

	nb = (long) n;
	neg = (nb < 0);
	if (neg == 1)
		nb *= -1;
	if (neg == 1)
		ft_putchar_fd('-', fd);
	if (nb > 9)
	{
		ft_putnbr_fd (nb / 10, fd);
		nb = nb % 10;
	}
	if (nb <= 9)
		ft_putchar_fd(nb + '0', fd);
	return ;
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen((const char *) s));
	return ;
}
