/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:27:05 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/21 13:27:24 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d/cub3d.h"

int		reverse_map(t_map *map)
{
	int		i;
	int		j;
	char	buff[map->y][map->x];

	i = -1;
	while (++i < map->y)
	{
		ft_memset(buff[i], ' ', map->x);
		buff[i][map->x] = 0;
	}
	j = -1;
	while (++j < map->y)
	{
		i = -1;
		while (++i < map->x)
			if (j < len_1d(map->map[i]))
				buff[j][i] = map->map[i][j];
	}
	j = -1;
	map->step = 1;
	while (++j < map->y)
		if (check_width_line(map, buff[j], 0))
			return (1);
	return (0);
}

int		check_extension(char *file_name, char *extension)
{
	int lf;
	int le;

	lf = len_1d(file_name);
	le = len_1d(extension);
	while (le--)
		if (file_name[--lf] != extension[le])
			return (0);
	return (1);
}

void	exist_line_parsing(t_var *var)
{
	int i;

	i = 1;
	if (var->map.resol_w == -1 || var->map.resol_h == -1)
		i = 0;
	if (var->map.ceilling.r == -1 || var->map.ceilling.g == -1
		|| var->map.ceilling.b == -1)
		i = 0;
	if (var->map.floor.r == -1 || var->map.floor.g == -1
		|| var->map.floor.b == -1)
		i = 0;
	if (!var->map.east || !var->map.west || !var->map.north || !var->map.south)
		i = 0;
	if (!var->map.sprite || !var->map.map)
		i = 0;
	if (i == 0)
		hundle_error(LINE_NOTEXIST, var);
}

void	check_map_2d(char *file, t_var *var)
{
	int		r;
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		hundle_error(FILE_ERROR, var);
	if ((check_extension(file, ".cub")) == 0)
		hundle_error(EXTENSION_ERROR, var);
	r = 1;
	line = NULL;
	while (r > 0)
	{
		if ((r = get_next_line(fd, &line)) == -1)
		{
			free(line);
			hundle_error(GNL_ERROR, var);
		}
		if (hundle_line(fd, line, var) == 1)
			break ;
		free(line);
	}
	exist_line_parsing(var);
	close(fd);
}
