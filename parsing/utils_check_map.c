/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <mbelaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:09:39 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/24 10:43:27 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d/cub3d.h"

int		check_len_tab(char **tab)
{
	int len;

	len = 0;
	if (tab)
		while (tab[len])
			++len;
	return (len);
}

int		check_two_str(char *rsl, char *src)
{
	int	i;
	int	j;
	int	digit;

	if (!rsl)
		return (0);
	j = -1;
	while (rsl[++j])
	{
		digit = 0;
		i = -1;
		while (src[++i])
			if (rsl[j] == src[i])
				digit = 1;
		if (!digit)
			return (0);
	}
	return (1);
}

int		len_1d(char *s)
{
	int l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

int		max_len_1d(char **tab)
{
	int len;
	int i;
	int max;

	i = -1;
	max = 0;
	while (tab[++i])
		if (max < (len = len_1d(tab[i])))
			max = len;
	return (max);
}

int		verify_eof(int fd, char *line, t_var *var)
{
	int r;

	r = 1;
	while (r > 0)
	{
		if ((r = get_next_line(fd, &line)) == -1)
		{
			free(line);
			hundle_error(GNL_ERROR, var);
		}
		if (*line && line)
		{
			close(fd);
			free(line);
			hundle_error(MAP_ERROR, var);
		}
		free(line);
	}
	if (r != 0)
		return (1);
	else
		return (0);
}
