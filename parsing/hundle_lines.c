/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <mbelaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:29:53 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/24 10:44:12 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d/cub3d.h"

int		check_map(t_map *map)
{
	int i;

	if (!(map->map = ft_split(map->tmp_map, '\v')))
	{
		free(map->tmp_map);
		return (1);
	}
	free(map->tmp_map);
	if ((map->x = check_len_tab(map->map)) < 3 ||
		(map->y = max_len_1d(map->map)) < 3 ||
		!check_two_str(map->map[0], "1 ") ||
		!check_two_str(map->map[map->x - 1], "1 "))
		return (1);
	i = 0;
	map->step = 0;
	while (++i < map->x - 1)
		if (check_width_line(map, map->map[i], i))
			return (1);
		else if (map->dir_count == 1 && !map->pos_x)
			map->pos_x = (double)i;
	if (reverse_map(map))
		return (1);
	return (map->dir_count != 1);
}

void	verify_map(int fd, char *line, t_map *map, t_var *var)
{
	char	*tmp;
	int		r;

	r = 1;
	map->tmp_map = line;
	while (r == 1)
	{
		if ((r = get_next_line(fd, &line)) == -1)
		{
			free(line);
			hundle_error(GNL_ERROR, var);
		}
		if (line && (!*line || check_two_str(line, " "))
			&& verify_eof(fd, line, var))
			break ;
		tmp = ft_strjoin(var->map.tmp_map, "\v");
		free(map->tmp_map);
		var->map.tmp_map = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	if (check_map(map))
		hundle_error(MAP_ERROR, var);
}

void	handle_sp(char *line, t_var *var)
{
	char *tmp;

	tmp = ft_strtrim(line, " ");
	if (tmp && *tmp != '1')
	{
		free(line);
		free(tmp);
		hundle_error(MAP_ERROR, var);
	}
	free(tmp);
}

void	get_texutre(char *line, t_var *var)
{
	char	*path_tex;

	if (!(path_tex = ft_strtrim(line + 2, " ")))
		hundle_error(EXEC_ERR, var);
	if (open(path_tex, O_RDONLY) == -1)
	{
		free(path_tex);
		hundle_error(TEX_ERR, var);
	}
	if (!ft_strncmp(line, "NO", 2))
		get_tex_no(path_tex, line, var);
	else if (!ft_strncmp(line, "SO", 2))
		get_tex_so(path_tex, line, var);
	else if (!ft_strncmp(line, "WE", 2))
		get_tex_we(path_tex, line, var);
	else if (!ft_strncmp(line, "EA", 2))
		get_tex_ea(path_tex, line, var);
	else if (*line == 'S')
		get_tex_sp(path_tex, line, var);
}

int		hundle_line(int fd, char *line, t_var *var)
{
	if (*line == 'R')
		get_resolution(line, var);
	else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)
			|| !ft_strncmp(line, "S", 1))
		get_texutre(line, var);
	else if (*line == 'F' || *line == 'C')
		get_color(line, var);
	else if (*line == '1' || *line == ' ')
	{
		handle_sp(line, var);
		verify_map(fd, line, &(var->map), var);
		return (1);
	}
	else if (!*line)
		return (0);
	else
	{
		free(line);
		hundle_error(MAP_ERROR, var);
	}
	return (0);
}
