/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_is_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:34:12 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/21 13:34:20 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_is_hit(t_var *var)
{
	char pos;

	while (var->hit == 0)
	{
		if (var->sd_x < var->sd_y)
		{
			var->sd_x += var->dd_x;
			var->map_x += var->stp_x;
			var->side = 0;
		}
		else
		{
			var->sd_y += var->dd_y;
			var->map_y += var->stp_y;
			var->side = 1;
		}
		pos = var->map.map[var->map_x][var->map_y];
		if (pos == '1')
			var->hit = 1;
	}
}
