/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:40:49 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 10:20:35 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != 0)
		++i;
	return (i);
}

//finds a char inside a str and returns the pointer to the str at that char
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ps;

	i = 0;
	ps = (char *) s;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (&ps[i]);
		i++;
	}
	if ((char) c == 0)
		return (&ps[i]);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*ps;

	ps = (char *)s;
	len = ft_strlen(s) + 1;
	while (len > 0)
	{
		len--;
		if (ps[len] == (char) c)
			return (&ps[len]);
	}
	return (NULL);
}

char	*ft_strnstr(const char *hayst, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(need) == 0)
		return ((char *)hayst);
	while (hayst[i] != 0 && i < len)
	{
		j = 0;
		if (hayst[i] == need[j])
		{
			while (hayst[i + j] == need[j] && need[j] != '\0' && i + j < len)
			{
				if (need [j + 1] == '\0')
					return ((char *)&hayst[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	i = 0;
	while ((i < n) && ((s1[i] != '\0') || (s2[i] != '\0')))
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		i++;
	}
	return (s1[i] != s2[i]);
}
