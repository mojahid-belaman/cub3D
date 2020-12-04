/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:42:19 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/16 13:42:21 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d/cub3d.h"

void	get_tex_no(char *path_tex, char *line, t_var *var)
{
	if (ft_strncmp(line, "NO ", 3))
		hundle_error(TEX_ERR, var);
	else if (var->map.north != NULL)
		hundle_error(MAP_ELM_REP, var);
	else
		var->map.north = path_tex;
}

void	get_tex_so(char *path_tex, char *line, t_var *var)
{
	if (strncmp(line, "SO ", 3))
		hundle_error(TEX_ERR, var);
	else if (var->map.south != NULL)
		hundle_error(MAP_ELM_REP, var);
	else
		var->map.south = path_tex;
}

void	get_tex_we(char *path_tex, char *line, t_var *var)
{
	if (strncmp(line, "WE ", 3))
		hundle_error(TEX_ERR, var);
	else if (var->map.west != NULL)
		hundle_error(MAP_ELM_REP, var);
	else
		var->map.west = path_tex;
}

void	get_tex_ea(char *path_tex, char *line, t_var *var)
{
	if (strncmp(line, "EA ", 3))
		hundle_error(TEX_ERR, var);
	else if (var->map.east != NULL)
		hundle_error(MAP_ELM_REP, var);
	else
		var->map.east = path_tex;
}

void	get_tex_sp(char *path_tex, char *line, t_var *var)
{
	if (ft_strncmp(line, "S ", 2))
		hundle_error(TEX_ERR, var);
	else if (var->map.sprite != NULL)
		hundle_error(MAP_ELM_REP, var);
	else
		var->map.sprite = path_tex;
}
