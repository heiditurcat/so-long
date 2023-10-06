/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:50:10 by hturcat           #+#    #+#             */
/*   Updated: 2023/10/03 12:51:57 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_isascii_2p_2e_c(int c)
{
	if (c == 'P')
		return (ERROR_TOO_MANY_P);
	else if (c == 'E')
		return (ERROR_TOO_MANY_E);
	else if (c == 'C')
		return (ERROR_C);
	else
		return (SUCCESS);
}

int	ft_check_collectible(t_d *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < d->nbline)
	{
		while (d->map[j] && d->map[j][i])
		{
			if (ft_isascii_2p_2e_c(d->map[j][i]) == ERROR_C)
			{
				d->count_c++;
				if (ft_backtracking(d, j, i) == PARSING_ERROR)
					return (PARSING_ERROR);
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (d->count_c >= 1)
		return (SUCCESS);
	else
		return (ERROR_NO_COLLECTIBLE);
}

int	ft_check_nb_player_exit(t_d *d)
{
	int	i;
	int	j;
	int	count_player;
	int	count_exit;

	i = 0;
	j = 0;
	count_player = 0;
	count_exit = 0;
	while (j < d->nbline)
	{
		while (d->map && d->map[j] && d->map[j][i])
		{
			if (ft_isascii_2p_2e_c(d->map[j][i]) == ERROR_TOO_MANY_P)
				count_player++;
			if (ft_isascii_2p_2e_c(d->map[j][i]) == ERROR_TOO_MANY_E)
				count_exit++;
			i++;
		}
		i = 0;
		j++;
	}
	if (count_player == 1 && count_exit == 1)
		return (SUCCESS);
	return (ERROR_TOO_MANY);
}

int	ft_check_name(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len > 4 && name[len - 5] != '/')
	{
		if (name[len - 4] == '.')
		{
			if (name[len - 3] == 'b')
			{
				if (name[len - 2] == 'e')
				{
					if (name[len - 1] == 'r')
						return (SUCCESS);
				}
			}
		}
	}
	return (ERROR_NAME);
}
