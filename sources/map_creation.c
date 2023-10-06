/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:18:06 by hturcat           #+#    #+#             */
/*   Updated: 2023/10/02 22:52:03 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	count_line(t_d *d)
{
	while (d->map[d->nbline])
		d->nbline++;
}

int	ft_check_empty(char *map_line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map_line);
	while (i < len)
	{
		if (map_line[i] == '\n' && map_line[i + 1] == '\n')
			return (ERROR_NEWLINE);
		i++;
	}
	return (SUCCESS);
}

int	ft_map_creation(t_d *d, char **argv)
{
	char	*map_line;
	char	*map_tmp_line;
	char	*line;
	int		fd;

	map_tmp_line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(d, ERROR_FD));
	line = get_next_line(fd);
	if (!line)
		return (ft_error(d, MAP_EMPTY));
	map_line = ft_strdup("");
	d->nbcol = ft_strlen(line) - 1;
	while (line)
	{
		map_tmp_line = map_line;
		map_line = ft_strjoin(map_tmp_line, line);
		free (line);
		line = get_next_line(fd);
	}
	ft_map_creation_suite(d, map_line, line, fd);
	return (SUCCESS);
}

int	ft_map_creation_suite(t_d *d, char *map_line, char *line, int fd)
{
	if (map_line[0] == '\n' || ft_check_empty(map_line) == ERROR_NEWLINE)
	{
		free(map_line);
		free(line);
		close (fd);
		return (ft_error(d, ERROR_NEWLINE));
	}
	d->map = ft_split(map_line, '\n');
	free(map_line);
	count_line(d);
	close (fd);
	return (0);
}
