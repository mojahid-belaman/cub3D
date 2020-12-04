/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_error_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <mbelaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:29:31 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/23 12:25:02 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d/cub3d.h"

void	check_free(int err, t_var *var)
{
	if (err == END_GAME)
		free(var->img);
	free_table(var->map.map, var->map.x);
	free(var->map.north);
	free(var->map.south);
	free(var->map.west);
	free(var->map.east);
	free(var->map.sprite);
	free(var->sprit.z_buffer);
}

void	continue_hundle_err(int err)
{
	if (err == COLOR_ERR)
		ft_putstr_fd("Check format the color(r,g,b) !\n", 1);
	else if (err == ESP_ERR)
		ft_putstr_fd("Check espace between element and information !\n", 1);
	else if (err == CHIFRE_COLOR)
		ft_putstr_fd("Check format the color RGB(0,0,0) is number !\n", 1);
	else if (err == MIN_MAX_COLOR)
		ft_putstr_fd("Number the color RGB between 0 and 255 !\n", 1);
	else if (err == LINE_NOTEXIST)
		ft_putstr_fd("Check line R NO SO WE EA MAP is exist !\n", 1);
	else if (err == ARG_ERR)
		ft_putstr_fd("Invalid Argument !\n", 1);
	exit(err);
}

void	hundle_error(int err, t_var *var)
{
	check_free(err, var);
	err ? ft_putstr_fd("Error\n", 1) : 0;
	if (err == FILE_ERROR)
		ft_putstr_fd("File not found !\n", 1);
	else if (err == EXTENSION_ERROR)
		ft_putstr_fd("File extention is not '.cub' !\n", 1);
	else if (err == MAP_ERROR)
		ft_putstr_fd("MAP File content error !\n", 1);
	else if (err == GNL_ERROR)
		ft_putstr_fd("Reading files Error !\n", 1);
	else if (err == MAP_ELM_REP)
		ft_putstr_fd("MAP Element was repeated !\n", 1);
	else if (err == RSL_ERR)
		ft_putstr_fd("Check line resolution !\n", 1);
	else if (err == TEX_ERR)
		ft_putstr_fd("Check path textures !\n", 1);
	else if (err == BMP_FILE_ERR)
		ft_putstr_fd("Could not save image!\n", 1);
	continue_hundle_err(err);
}

char	**free_table(char **tab, int size)
{
	if (!tab)
		return (NULL);
	while (size--)
		free(tab[size]);
	free(tab);
	return (NULL);
}
