/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:27:30 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/29 17:57:06 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_rec_cond(t_d *d, int y, int x)
{
	return (d->cpy[y][x] != '1'
		&& d->cpy[y][x] != 'E'
		&& d->cpy[y][x] != 'X');
}

int	ft_recursive(t_d *d, int y, int x)
{
	if (d->cpy[y][x] == 'P')
		return (SUCCESS);
	d->cpy[y][x] = '1';
	if (ft_rec_cond(d, y + 1, x))
	{
		if (ft_recursive(d, y + 1, x) == SUCCESS)
			return (SUCCESS);
	}
	if (ft_rec_cond(d, y - 1, x))
	{
		if (ft_recursive(d, y - 1, x) == SUCCESS)
			return (SUCCESS);
	}
	if (ft_rec_cond(d, y, x + 1))
	{
		if (ft_recursive(d, y, x + 1) == SUCCESS)
			return (SUCCESS);
	}
	if (ft_rec_cond(d, y, x - 1))
	{
		if (ft_recursive(d, y, x - 1) == SUCCESS)
			return (SUCCESS);
	}
	return (ERROR);
}

int	ft_backtracking(t_d *d, int y, int x)
{
	int	j;
	int	i;

	j = 0;
	d->cpy = ft_calloc(sizeof(char *), d->nbline);
	while (j < d->nbline)
	{
		i = 0;
		d->cpy[j] = ft_calloc(sizeof(char *), d->nbcol);
		while (i < d->nbcol)
		{
			d->cpy[j][i] = d->map[j][i];
			i++;
		}
		j++;
	}
	j = PARSING_ERROR;
	if (ft_recursive(d, y, x) == SUCCESS)
		j = SUCCESS;
	ft_free(d, d->cpy);
	return (j);
}
