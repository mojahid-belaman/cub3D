/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:31:15 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/21 13:31:27 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_texture(t_var *var)
{
	if (var->side == 0)
		var->wal_x = var->p_y + var->p_w_d * var->rd_y;
	else
		var->wal_x = var->p_x + var->p_w_d * var->rd_x;
	var->wal_x -= floor((var->wal_x));
	var->tex_x = (int)(var->wal_x * (double)var->tex_w);
	if (var->side == 0 && var->rd_x > 0)
		var->tex_x = var->tex_w - var->tex_x - 1;
	if (var->side == 1 && var->rd_y < 0)
		var->tex_x = var->tex_w - var->tex_x - 1;
	var->step = 1.0 * var->tex_h / var->l_h;
	var->tex_pos = (var->ds - var->map.resol_h / 2 + var->l_h / 2) * var->step;
	while (var->ds < var->de)
	{
		var->tex_y = (int)var->tex_pos;
		var->tex_pos += var->step;
		specifie_side(var);
		var->texture[var->map.resol_w * var->ds + var->x] = var->color;
		var->ds++;
	}
}
