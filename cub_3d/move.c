/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:45:22 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/16 14:45:24 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_var *var)
{
	if (var->map.map[(int)(var->p_x + var->d_x * 0.06)][(int)(var->p_y)] == '0')
		var->p_x += var->d_x * 0.06;
	if (var->map.map[(int)var->p_x][(int)(var->p_y + var->d_y * 0.06)] == '0')
		var->p_y += var->d_y * 0.06;
}

void	move_down(t_var *var)
{
	if (var->map.map[(int)(var->p_x - var->d_x * 0.06)][(int)var->p_y] == '0')
		var->p_x -= var->d_x * 0.06;
	if (var->map.map[(int)var->p_x][(int)(var->p_y - var->d_y * 0.06)] == '0')
		var->p_y -= var->d_y * 0.06;
}

void	move_right(t_var *var)
{
	if (var->map.map[(int)(var->p_x + var->pl_x * 0.1)][(int)(var->p_y)] == '0')
		var->p_x += var->pl_x * 0.1;
	if (var->map.map[(int)var->p_x][(int)(var->p_y + var->pl_y * 0.1)] == '0')
		var->p_y += var->pl_y * 0.1;
}

void	move_left(t_var *var)
{
	if (var->map.map[(int)(var->p_x - var->pl_x * 0.1)][(int)(var->p_y)] == '0')
		var->p_x -= var->pl_x * 0.1;
	if (var->map.map[(int)var->p_x][(int)(var->p_y - var->pl_y * 0.1)] == '0')
		var->p_y -= var->pl_y * 0.1;
}
