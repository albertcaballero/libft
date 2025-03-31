/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:40:50 by alcaball          #+#    #+#             */
/*   Updated: 2023/05/23 16:45:17 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		++i;
	}
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	newstr = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		++i;
	}
	newstr[i] = 0;
	return (newstr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*pdst;
	char	*psrc;

	i = 0;
	pdst = (char *) dst;
	psrc = (char *) src;
	if (dstsize == 0)
		return (ft_strlen(src));
	dstsize--;
	while (i < dstsize && psrc[i] != '\0')
	{
		pdst[i] = psrc[i];
		i++;
	}
	pdst[i] = '\0';
	return (ft_strlen(src));
}


// ==========

static size_t	minlen(char *dst, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		++i;
	return (i);
}

//hell, do not use
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	app;
	size_t	aux;

	i = minlen(dst, dstsize);
	aux = i;
	j = 0;
	app = dstsize - i - 1;
	while (j < app && src[j] != '\0' && aux < dstsize)
	{
		dst[i] = (char) src[j];
		i++;
		j++;
	}
	if (j > 0)
		dst[i] = '\0';
	return (aux + ft_strlen(src));
}
