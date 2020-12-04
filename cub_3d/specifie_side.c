/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifie_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:50:41 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/16 14:50:44 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	specifie_side(t_var *var)
{
	if (var->side == 0)
	{
		if (var->map_x - var->p_x > 0)
			var->color = var->data_so[var->tex_w * var->tex_y + var->tex_x];
		else
			var->color = var->data_no[var->tex_w * var->tex_y + var->tex_x];
	}
	else
	{
		if (var->map_y - var->p_y > 0)
			var->color = var->data_ea[var->tex_w * var->tex_y + var->tex_x];
		else
			var->color = var->data_we[var->tex_w * var->tex_y + var->tex_x];
	}
}
