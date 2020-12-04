/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:12:54 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/23 09:13:10 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calucle_sp(t_var *var, int i)
{
	var->sprit.sp_x = 0.5 + var->map.pos[var->sprit.sp_ord[i]].x_sp - var->p_x;
	var->sprit.sp_y = 0.5 + var->map.pos[var->sprit.sp_ord[i]].y_sp - var->p_y;
	var->sprit.inv_det = 1.0 / (var->pl_x * var->d_y - var->d_x * var->pl_y);
	var->sprit.tsf_x = var->sprit.inv_det *
	(var->d_y * var->sprit.sp_x - var->d_x * var->sprit.sp_y);
	var->sprit.tsf_y = var->sprit.inv_det *
	(-var->pl_y * var->sprit.sp_x + var->pl_x * var->sprit.sp_y);
	var->sprit.sp_scrn_x = (int)((var->map.resol_w / 2) *
	(1 + var->sprit.tsf_x / var->sprit.tsf_y));
	var->sprit.sp_h = abs((int)(var->map.resol_h / (var->sprit.tsf_y)));
	var->sprit.dr_st_y = -var->sprit.sp_h / 2 + var->map.resol_h / 2;
	if (var->sprit.dr_st_y < 0)
		var->sprit.dr_st_y = 0;
	var->sprit.dr_en_y = var->sprit.sp_h / 2 + var->map.resol_h / 2;
	if (var->sprit.dr_en_y >= var->map.resol_h)
		var->sprit.dr_en_y = var->map.resol_h - 1;
	var->sprit.sp_wdth = abs((int)(var->map.resol_h / (var->sprit.tsf_y)));
	var->sprit.dr_st_x = -var->sprit.sp_wdth / 2 + var->sprit.sp_scrn_x;
	if (var->sprit.dr_st_x < 0)
		var->sprit.dr_st_x = 0;
	var->sprit.dr_en_x = var->sprit.sp_wdth / 2 + var->sprit.sp_scrn_x;
	if (var->sprit.dr_en_x >= var->map.resol_w)
		var->sprit.dr_en_x = var->map.resol_w - 1;
}

void	draw_sprite(t_var *var, int *stripe)
{
	int	y;

	while (++(*stripe) < var->sprit.dr_en_x)
	{
		var->sprit.tex_x = (int)(256 * (*stripe - (-var->sprit.sp_wdth / 2 +
		var->sprit.sp_scrn_x)) * var->sprit.spr_w / var->sprit.sp_wdth) / 256;
		if (var->sprit.tsf_y > 0 && *stripe > 0 && *stripe < var->map.resol_w
			&& var->sprit.tsf_y < var->sprit.z_buffer[*stripe])
		{
			y = var->sprit.dr_st_y - 1;
			while (++y < var->sprit.dr_en_y)
			{
				var->sprit.d = (y) * 256 - var->map.resol_h * 128 +
				var->sprit.sp_h * 128;
				var->sprit.tex_y = ((var->sprit.d * var->tex_h) /
				var->sprit.sp_h) / 256;
				var->sprit.color = var->sprit.spr_data[var->sprit.spr_w *
				var->sprit.tex_y + var->sprit.tex_x];
				if (var->sprit.color != 9961608)
					var->texture[y * var->map.resol_w + *stripe] =
					var->sprit.color;
			}
		}
	}
}

void	sort_sprite(t_var *var)
{
	int		i;
	int		j;
	int		p;
	double	max;

	i = -1;
	while (++i <= var->map.sp_count)
	{
		max = var->sprit.sp_dst[i];
		j = 0;
		while (j <= var->map.sp_count)
		{
			if (max <= var->sprit.sp_dst[j])
			{
				max = var->sprit.sp_dst[j];
				p = j;
			}
			j++;
		}
		var->sprit.sp_dst[p] = 0;
		var->sprit.sp_ord[i] = p;
	}
}

void	sprite(t_var *var)
{
	int i;
	int stripe;

	i = -1;
	while (++i < var->map.sp_count)
	{
		var->sprit.sp_ord[i] = i;
		var->sprit.sp_dst[i] = pow(var->p_x - var->map.pos[i].x_sp, 2) +
		pow(var->p_y - var->map.pos[i].y_sp, 2);
	}
	sort_sprite(var);
	i = -1;
	while (++i < var->map.sp_count)
	{
		calucle_sp(var, i);
		stripe = var->sprit.dr_st_x - 1;
		draw_sprite(var, &stripe);
	}
}
