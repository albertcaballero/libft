/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:23:28 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 10:10:30 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ft_isalpha(c) || ft_isdigit(c);
}

int	ft_isprint(int c)
{
	return c >= 32 && c < 127;
}

int	ft_isdigit(int c)
{
	return c >= 48 && c <= 57;
}

int	ft_isascii(int c)
{
	return c >= 0 && c <= 127;
}

int	ft_isalpha(int c)
{
	return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}
