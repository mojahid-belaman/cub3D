/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_line_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:34:31 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/21 13:34:42 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_line_height(t_var *var)
{
	var->l_h = (int)(var->map.resol_h / var->p_w_d);
	var->ds = -var->l_h / 2 + var->map.resol_h / 2;
	if (var->ds < 0)
		var->ds = 0;
	var->de = var->l_h / 2 + var->map.resol_h / 2;
	if (var->de >= var->map.resol_h)
		var->de = var->map.resol_h - 1;
}
