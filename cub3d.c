/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <mbelaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:13:44 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/23 12:30:28 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d/cub3d.h"

void	init_raycast(t_var *var)
{
	var->cmr_x = 2 * var->x / (double)var->map.resol_w - 1;
	var->rd_x = var->d_x + var->pl_x * var->cmr_x;
	var->rd_y = var->d_y + var->pl_y * var->cmr_x;
	var->map_x = (int)var->p_x;
	var->map_y = (int)var->p_y;
	var->dd_x = fabs(1 / var->rd_x);
	var->dd_y = fabs(1 / var->rd_y);
	var->hit = 0;
	direction_ray(var);
	wall_is_hit(var);
	if (var->side == 0)
		var->p_w_d = (var->map_x - var->p_x + (1 - var->stp_x) / 2) / var->rd_x;
	else
		var->p_w_d = (var->map_y - var->p_y + (1 - var->stp_y) / 2) / var->rd_y;
}

int		draw_walls(t_var *var)
{
	var->x = 0;
	mlx_clear_window(var->mlx_ptr, var->win_ptr);
	var->texture = (int*)mlx_get_data_addr(var->img, &var->bpp,
	&var->sl, &var->endian);
	var->data = (int*)mlx_get_data_addr(var->img, &var->bpp,
	&var->sl, &var->endian);
	hundle_key(var);
	while (var->x < var->map.resol_w)
	{
		init_raycast(var);
		wall_line_height(var);
		draw_line_floor_ceilling(var);
		draw_texture(var);
		var->sprit.z_buffer[var->x] = var->p_w_d;
		var->x++;
	}
	sprite(var);
	if (var->save == 1)
		draw_in_file(var);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img, 0, 0);
	return (0);
}

void	protect_ptr(t_var *var)
{
	if (!var->xfi_no || !var->xfi_so || !var->xfi_ea
		|| !var->xfi_we || !var->sprit.spr_img)
		hundle_error(GNL_ERROR, var);
}

void	protect_data(t_var *var)
{
	if (!var->data_no || !var->data_so || !var->data_ea
		|| !var->data_we || !var->sprit.spr_img)
		hundle_error(GNL_ERROR, var);
}

int		main(int ac, char **av)
{
	t_var	var;

	if (ac == 1)
		hundle_error(NO_ARG, &var);
	if (ac == 3 && !ft_strncmp(av[2], "--save", len_1d(av[2])))
		var.save = 1;
	if (ac == 3 && ft_strncmp(av[2], "--save", len_1d(av[2])))
		hundle_error(ARG_ERR, &var);
	if (ac >= 4)
		hundle_error(ARG_ERR, &var);
	init_map(&var);
	check_map_2d(av[1], &var);
	initial_player(&var);
	ft_initaialize(&var);
	mlx_hook(var.win_ptr, 2, 0, key_press, &var);
	mlx_hook(var.win_ptr, 3, 0, key_release, &var);
	mlx_hook(var.win_ptr, 17, 0, exit_win, &var);
	mlx_loop_hook(var.mlx_ptr, draw_walls, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}
