/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:15:23 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 10:21:07 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*arr;

	i = 0;
	arr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!arr)
		return (NULL);
	while (s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	stt;
	size_t	j;
	char	*sub;

	j = 0;
	stt = (size_t) start;
	if (stt > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s + stt);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (j < len)
		sub[j++] = s[stt++];
	sub[j] = 0;
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] != 0)
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != 0)
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = 0;
	return (s3);
}


// =================
static int	valcheck(char a, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	while (valcheck(s1[i], set) == 1)
		i++;
	if (i == (int)ft_strlen(s1) || s1[0] == 0)
	{
		s3 = ft_strdup("");
		return (s3);
	}
	if (set[0] == 0)
	{
		s3 = ft_strdup(s1);
		return (s3);
	}
	j = ft_strlen(s1) - 1;
	while (valcheck(s1[j], set) == 1)
		j--;
	s3 = ft_substr(s1, i, j - i + 1);
	if (!s3)
		return (NULL);
	return (s3);
}
