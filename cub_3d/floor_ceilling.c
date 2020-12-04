/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceilling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:37:35 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/16 14:37:40 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line_floor_ceilling(t_var *var)
{
	var->y = 0;
	while (var->y < var->map.resol_h)
	{
		if (var->y < var->ds)
			var->data[var->map.resol_w * var->y + var->x] =
			(var->map.ceilling.r << 16) + (var->map.ceilling.g << 8) +
			(var->map.ceilling.b);
		else if (var->y < var->map.resol_h)
			var->data[var->map.resol_w * var->y + var->x] =
			(var->map.floor.r << 16) + (var->map.floor.g << 8) +
			(var->map.floor.b);
		var->y++;
	}
}
