/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:46:39 by mbelaman          #+#    #+#             */
/*   Updated: 2019/12/25 18:03:40 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d/cub3d.h"

int	read_line(char **str, char **line, char *tmp, int i)
{
	if (*str)
	{
		while ((*str)[i] && (*str)[i] != '\n')
			i++;
		if ((*str)[0] != '\0' || (*str)[i] == '\n')
		{
			tmp = *line;
			*line = ft_substr(*str, 0, i);
			free(tmp);
			tmp = *str;
			if ((*str)[i] != '\0')
				*str = ft_strdup(*str + i + 1);
			else
			{
				free(tmp);
				return (0);
			}
			free(tmp);
			return (1);
		}
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*str;
	char		*tmp;
	int			r;

	if (BUFFER_SIZE == 0)
		return (0);
	if (fd < 0 || BUFFER_SIZE < 0 || fd > 10240)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		tmp = str;
		str = ft_strjoin(str, buff);
		free(tmp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buff);
	if (r < 0)
		return (-1);
	*line = ft_strdup("");
	return (read_line(&str, line, tmp, 0));
}
