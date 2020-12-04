/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:00:56 by mbelaman          #+#    #+#             */
/*   Updated: 2019/11/09 08:55:13 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d/cub3d.h"

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
	tmp = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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
