/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:12:18 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/16 14:12:24 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	direction_ray(t_var *var)
{
	if (var->rd_x < 0)
	{
		var->stp_x = -1;
		var->sd_x = (var->p_x - var->map_x) * var->dd_x;
	}
	else
	{
		var->stp_x = 1;
		var->sd_x = (var->map_x + 1.0 - var->p_x) * var->dd_x;
	}
	if (var->rd_y < 0)
	{
		var->stp_y = -1;
		var->sd_y = (var->p_y - var->map_y) * var->dd_y;
	}
	else
	{
		var->stp_y = 1;
		var->sd_y = (var->map_y + 1.0 - var->p_y) * var->dd_y;
	}
}
