/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:27:34 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/21 13:28:00 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d/cub3d.h"

int		find_dir_sp(t_map *map, char *line, int x)
{
	int i;

	i = len_1d(line);
	while (i--)
	{
		if (line[i] == 'N' || line[i] == 'E' || line[i] == 'S'
			|| line[i] == 'W')
		{
			map->orient = line[i];
			map->pos_y = (double)i;
			map->dir_count++;
		}
		else if (line[i] == '2')
		{
			map->pos[map->sp_count].x_sp = x;
			map->pos[map->sp_count].y_sp = i;
			map->sp_count++;
		}
	}
	return (map->dir_count > 1);
}

int		check_width_line(t_map *map, char *line, int x)
{
	int		i;
	char	**tab;

	if (!map->step && !check_two_str(line, "012 NESW"))
		return (1);
	tab = ft_split(line, ' ');
	i = -1;
	while (tab[++i])
	{
		if (tab[i][0] != '1' || tab[i][len_1d(tab[i]) - 1] != '1')
		{
			free_table(tab, check_len_tab(tab));
			return (1);
		}
	}
	free_table(tab, check_len_tab(tab));
	return (map->step == 1 ? 0 : find_dir_sp(map, line, x));
}
