/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:22:46 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/21 13:23:10 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d/cub3d.h"

long long	ft_atoi(const char *str)
{
	long int	convert;
	int			sign;
	int			index;

	convert = 0;
	index = 0;
	sign = 1;
	while (str[index] == '\t' || str[index] == '\n' || str[index] == '\f'
			|| str[index] == '\v' || str[index] == '\r' || str[index] == ' ')
		index++;
	if (str[index] == '+' && str[index + 1] == '-')
		return (0);
	if (str[index] == '+')
		index++;
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9')
	{
		convert = (convert * 10) + (str[index] - '0');
		index++;
	}
	return (convert * sign);
}
