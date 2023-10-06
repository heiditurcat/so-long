/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:41:48 by hturcat           #+#    #+#             */
/*   Updated: 2023/10/03 13:51:03 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

///////good//////////////////////////////////////////////////////////////////

int	ft_isascii(int c)
{
	if (c == '0' || c == '1' || c == 'E' || c == 'P' || c == 'C' || c == 'X')
		return (SUCCESS);
	else
		return (ERROR_WRONG_CHAR);
}

int	ft_check_no_intrude(t_d *d)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < d->nbline)
	{
		while (d->map[j] && d->map[j][i])
		{
			if (d->map[j][i] && ft_isascii(d->map[j][i]) == ERROR_WRONG_CHAR)
				return (ERROR_WRONG_CHAR);
			i++;
		}
		i = 0;
		j++;
	}
	return (SUCCESS);
}

///////good//////////////////////////////////////////////////////////////////

int	ft_check_no_wall(t_d *d)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(d->map[0]);
	while (i < len)
	{
		if (d->map[0][i] != '1' \
		|| d->map[d->nbline - 1][i] != '1')
			return (ERROR_NO_WALL);
		i++;
	}
	while (j < d->nbline)
	{
		if (d->map[j][0] != '1' || d->map[j][len - 1] != '1')
			return (ERROR_NO_WALL);
		j++;
	}
	return (SUCCESS);
}

int	check_rectangle(t_d *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (d->map[y] && y < d->nbline)
	{
		if (ft_strlen(d->map[y]) != d->nbcol)
			return (ERROR_NO_WALL);
		y++;
	}
	return (SUCCESS);
}

///////good//////////////////////////////////////////////////////////////////

int	ft_check(t_d *d)
{
	int	result_collec;

	result_collec = 0;
	if (ft_check_no_intrude(d) == (ERROR_WRONG_CHAR))
		return (ft_error(d, ERROR_WRONG_CHAR));
	else if (ft_check_nb_player_exit(d) == (ERROR_TOO_MANY))
		return (ft_error(d, ERROR_TOO_MANY));
	else if (ft_check_no_wall(d) == ERROR_NO_WALL)
		return (ft_error(d, ERROR_NO_WALL));
	else if (check_rectangle(d) == ERROR_NO_WALL)
		return (ft_error(d, ERROR_NO_WALL));
	result_collec = ft_check_collectible(d);
	if (result_collec == (PARSING_ERROR))
		return (ft_error(d, PARSING_ERROR));
	else if (result_collec == (ERROR_NO_COLLECTIBLE))
		return (ft_error(d, ERROR_NO_COLLECTIBLE));
	else
		return (SUCCESS);
}
