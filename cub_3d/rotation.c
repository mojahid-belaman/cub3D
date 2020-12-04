/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:49:24 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/16 14:49:26 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotation_left(t_var *var)
{
	var->o_d_x = var->d_x;
	var->d_x = var->d_x * cos(0.02) - var->d_y * sin(0.02);
	var->d_y = var->o_d_x * sin(0.02) + var->d_y * cos(0.02);
	var->o_p_x = var->pl_x;
	var->pl_x = var->pl_x * cos(0.02) - var->pl_y * sin(0.02);
	var->pl_y = var->o_p_x * sin(0.02) + var->pl_y * cos(0.02);
}

void	rotation_right(t_var *var)
{
	var->o_d_x = var->d_x;
	var->d_x = var->d_x * cos(-0.02) - var->d_y * sin(-0.02);
	var->d_y = var->o_d_x * sin(-0.02) + var->d_y * cos(-0.02);
	var->o_p_x = var->pl_x;
	var->pl_x = var->pl_x * cos(-0.02) - var->pl_y * sin(-0.02);
	var->pl_y = var->o_p_x * sin(-0.02) + var->pl_y * cos(-0.02);
}
