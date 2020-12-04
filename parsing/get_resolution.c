/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:28:11 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/21 13:28:28 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d/cub3d.h"

void	get_resolution(char *line, t_var *var)
{
	char	**rsl;
	char	*s;

	s = "0123456789";
	if (var->map.resol_w != -1 || var->map.resol_h != -1)
		hundle_error(MAP_ELM_REP, var);
	if (ft_strncmp(line, "R ", 2))
		hundle_error(RSL_ERR, var);
	rsl = ft_split(line + 1, ' ');
	if (!rsl || check_len_tab(rsl) != 2 || !check_two_str(rsl[0], s)
		|| !check_two_str(rsl[1], s))
	{
		free_table(rsl, check_len_tab(rsl));
		hundle_error(RSL_ERR, var);
	}
	var->map.resol_w = ft_atoi(rsl[0]);
	var->map.resol_h = ft_atoi(rsl[1]);
	free_table(rsl, 2);
	var->map.resol_w = (var->map.resol_w > 2560) ? 2560 : var->map.resol_w;
	var->map.resol_h = (var->map.resol_h > 1440) ? 1440 : var->map.resol_h;
}
