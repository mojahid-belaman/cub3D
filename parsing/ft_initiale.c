/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:41:53 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/16 11:42:02 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d/cub3d.h"

void	init_color(t_rgb *color)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
}

void	init_map(t_var *var)
{
	var->map.dir_count = 0;
	var->map.resol_w = -1;
	var->map.resol_h = -1;
	var->map.sp_count = 0;
	var->map.north = NULL;
	var->map.south = NULL;
	var->map.west = NULL;
	var->map.east = NULL;
	var->map.sprite = NULL;
	init_color(&var->map.floor);
	init_color(&var->map.ceilling);
}
