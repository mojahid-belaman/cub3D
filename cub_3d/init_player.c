/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:35:09 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/21 13:35:19 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cont_init_pl(t_var *var)
{
	if (var->map.orient == 'W' || var->map.orient == 'E')
	{
		if (var->map.orient == 'W')
		{
			var->d_y = -1;
			var->pl_x = -0.66;
		}
		else
		{
			var->d_y = 1;
			var->pl_x = 0.66;
		}
		var->d_x = 0;
		var->pl_y = 0;
	}
}

void	initial_player(t_var *var)
{
	var->p_x = var->map.pos_x + 0.5;
	var->p_y = var->map.pos_y + 0.5;
	if (var->map.orient == 'N' || var->map.orient == 'S')
	{
		if (var->map.orient == 'N')
		{
			var->d_x = -1;
			var->pl_y = 0.66;
		}
		else
		{
			var->d_x = 1;
			var->pl_y = -0.66;
		}
		var->d_y = 0;
		var->pl_x = 0;
	}
	cont_init_pl(var);
}

void	spec_xmp_file(t_var *var)
{
	var->xfi_no = mlx_xpm_file_to_image(var->mlx_ptr, var->map.north,
	&var->tex_w, &var->tex_h);
	var->xfi_so = mlx_xpm_file_to_image(var->mlx_ptr, var->map.south,
	&var->tex_w, &var->tex_h);
	var->xfi_we = mlx_xpm_file_to_image(var->mlx_ptr, var->map.west,
	&var->tex_w, &var->tex_h);
	var->xfi_ea = mlx_xpm_file_to_image(var->mlx_ptr, var->map.east,
	&var->tex_w, &var->tex_h);
	var->sprit.spr_img = mlx_xpm_file_to_image(var->mlx_ptr, var->map.sprite,
	&var->sprit.spr_w, &var->sprit.spr_h);
	protect_ptr(var);
}

void	fill_data_img(t_var *var)
{
	var->data_no = (int*)mlx_get_data_addr(var->xfi_no, &var->bpp,
	&var->sl, &var->endian);
	var->data_so = (int*)mlx_get_data_addr(var->xfi_so, &var->bpp,
	&var->sl, &var->endian);
	var->data_we = (int*)mlx_get_data_addr(var->xfi_we, &var->bpp,
	&var->sl, &var->endian);
	var->data_ea = (int*)mlx_get_data_addr(var->xfi_ea, &var->bpp,
	&var->sl, &var->endian);
	var->sprit.spr_data = (int *)mlx_get_data_addr(var->sprit.spr_img,
	&var->sprit.spr_bbp, &var->sprit.spr_s_l, &var->sprit.spr_end);
	protect_data(var);
}

void	ft_initaialize(t_var *var)
{
	var->x = 0;
	var->y = 0;
	var->up = 0;
	var->down = 0;
	var->right = 0;
	var->left = 0;
	var->rt_r = 0;
	var->rt_l = 0;
	var->map.map[(int)var->map.pos_x][(int)var->map.pos_y] = '0';
	var->sprit.z_buffer = (double *)malloc(var->map.resol_w * sizeof(double));
	var->mlx_ptr = mlx_init();
	var->win_ptr = mlx_new_window(var->mlx_ptr, var->map.resol_w,
	var->map.resol_h, "Cub3D");
	var->img = mlx_new_image(var->mlx_ptr, var->map.resol_w, var->map.resol_h);
	spec_xmp_file(var);
	fill_data_img(var);
}
