/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:58:26 by mbelaman          #+#    #+#             */
/*   Updated: 2019/12/23 15:58:55 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d/cub3d.h"

size_t	ft_strlen(const char *str)
{
	size_t index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	tmp = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	while (s1[i1])
	{
		tmp[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
	{
		tmp[i1 + i2] = s2[i2];
		i2++;
	}
	tmp[i1 + i2] = '\0';
	return (tmp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	index;

	index = 0;
	if (s == NULL)
		return (NULL);
	tmp = malloc(len + 1);
	if (tmp == NULL)
		return (NULL);
	while (index < len)
	{
		*(tmp + index) = *(s + start);
		s++;
		index++;
	}
	*(tmp + index) = '\0';
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	ch;

	index = 0;
	ch = c;
	while (s[index] && s[index] != ch)
		index++;
	if (s[index] == ch)
		return ((char *)&s[index]);
	else
		return (NULL);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*string;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	string = (char *)malloc((len + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	while (i < len)
	{
		string[i] = src[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
