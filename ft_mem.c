/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:13:21 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 10:13:26 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *) s;
	while (i < n)
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	while (i < n)
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*pdst;
	char	*psrc;

	i = 0;
	pdst = (char *) dst;
	psrc = (char *) src;
	if (dst == 0 && src == 0)
		return (NULL);
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (pdst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == src || len == 0)
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			*((char *) dst + len - 1) = *((char *) src + len - 1);
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			*((char *) dst + i) = *((char *) src + i);
			i++;
		}
	}
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
