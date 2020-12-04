/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:09:03 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/23 09:09:15 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d/cub3d.h"

int		is_color(int color_code)
{
	return (color_code >= 0 && color_code <= 255);
}

int		is_rgb(char **tab)
{
	int		i;
	char	*str;

	if (!tab || check_len_tab(tab) != 3)
		return (0);
	i = -1;
	while (++i < 3)
	{
		str = ft_strtrim(tab[i], " ");
		if (!check_two_str(str, "0123456789"))
		{
			free(str);
			return (0);
		}
		if (!str || !*str)
		{
			free(str);
			return (0);
		}
		free(str);
	}
	return (1);
}

void	verify_color(t_rgb color, t_var *var, char c)
{
	if (!is_color(color.r) || !is_color(color.g) || !is_color(color.b))
		hundle_error(MIN_MAX_COLOR, var);
	if (c == 'F')
	{
		if (var->map.floor.r != -1 || var->map.floor.g != -1
			|| var->map.floor.b != -1)
			hundle_error(MAP_ELM_REP, var);
		var->map.floor = color;
	}
	else if (c == 'C')
	{
		if (var->map.ceilling.r != -1 || var->map.ceilling.g != -1
			|| var->map.ceilling.b != -1)
			hundle_error(MAP_ELM_REP, var);
		var->map.ceilling = color;
	}
}

void	number_semicolom(char *s, t_var *var)
{
	int		len;

	len = 0;
	if (s)
		while (*s)
			if (*s++ == ',')
				len++;
	if (len != 2)
		hundle_error(COLOR_ERR, var);
	else
		len = 0;
}

void	get_color(char *line, t_var *var)
{
	t_rgb	color;
	char	**tab;
	char	*s;

	s = line;
	number_semicolom(s, var);
	if (!ft_strncmp(line, "C", 1) || !ft_strncmp(line, "F", 1))
	{
		if (ft_strncmp(line, "C ", 2) && ft_strncmp(line, "F ", 2))
			hundle_error(ESP_ERR, var);
		else
		{
			tab = ft_split(line + 1, ',');
			if (!is_rgb(tab))
			{
				free_table(tab, check_len_tab(tab));
				hundle_error(CHIFRE_COLOR, var);
			}
			color.r = ft_atoi(tab[0]);
			color.g = ft_atoi(tab[1]);
			color.b = ft_atoi(tab[2]);
			free_table(tab, 3);
			verify_color(color, var, *line);
		}
	}
}
