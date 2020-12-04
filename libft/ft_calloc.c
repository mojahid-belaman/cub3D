/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:23:50 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/21 13:24:01 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d/cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	index;
	size_t	len;

	index = 0;
	len = count * size;
	ptr = malloc(len);
	if (ptr == NULL)
		return (NULL);
	while (index < len)
	{
		ptr[index] = '\0';
		index++;
	}
	return ((void *)ptr);
}
