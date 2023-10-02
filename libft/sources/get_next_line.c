/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:15:15 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/07 17:24:02 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_read_line(int fd, char *rest)
{
	int		bytes_read;
	char	*buf;

	bytes_read = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(buf);
		return (NULL);
	}
	while (!ft_strchr(rest, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		buf[bytes_read] = '\0';
		rest = ft_strjoin(rest, buf);
	}
	free (buf);
	return (rest);
}

char	*ft_get_line(int bytes_read, char *rest)
{
	char	*line;
	int		i;

	i = 0;
	if (!rest[i])
		return (NULL);
	line = (char *)malloc(sizeof(char) * (bytes_read + 2));
	if (!line)
	{
		free (line);
		return (NULL);
	}
	while (rest[i] != '\0' && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		line[i] = rest[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_rest(int bytes_read, char *rest)
{
	int		len;
	int		i;
	char	*new_line;

	i = 0;
	len = ft_strlen(rest);
	if (!rest[bytes_read])
	{
		free (rest);
		return (NULL);
	}
	new_line = (char *)malloc(sizeof(char) * (len - bytes_read + 1));
	if (!new_line)
		return (NULL);
	while (rest[bytes_read + 1])
	{
		new_line[i] = rest[bytes_read + 1];
		i++;
		bytes_read++;
	}
	new_line[i] = '\0';
	free (rest);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	int			bytes_read;

	bytes_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = ft_read_line(fd, rest);
	if (!rest)
		return (NULL);
	while (rest[bytes_read] && rest[bytes_read] != '\n')
		bytes_read++;
	line = ft_get_line(bytes_read, rest);
	rest = ft_get_rest(bytes_read, rest);
	return (line);
}
