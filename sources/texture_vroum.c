/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_vroum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:37:17 by hturcat           #+#    #+#             */
/*   Updated: 2023/10/03 13:58:52 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_validity(t_d *d)
{
	if (d->p_up == NULL)
		return (0);
	else if (d->p_down == NULL)
		return (0);
	else if (d->p_right == NULL)
		return (0);
	else if (d->p_left == NULL)
		return (0);
	else if (d->exit == NULL)
		return (0);
	else if (d->wa == NULL)
		return (0);
	else if (d->collect == NULL)
		return (0);
	else if (d->floor == NULL)
		return (0);
	else if (d->enemy == NULL)
		return (0);
	return (1);
}

void	destroy_ptr(t_d *d)
{
	if (check_validity(d) == 0)
	{
		ft_putstr_fd("Error:\nFile not found\n", 2);
		ft_destroy(d);
	}
}

void	map_texture_vroum(t_d *d)
{
	int	j;
	int	i;

	j = -1;
	destroy_ptr(d);
	while (++j < d->nbline)
	{
		i = -1;
		while (++i < d->nbcol)
		{
			if (d->map[j][i] == 'P')
				mlx_put_image_to_window(d->p, d->w, d->p_right, i * 64, j * 64);
			else if (d->map[j][i] == 'E')
				mlx_put_image_to_window(d->p, d->w, d->exit, i * 64, j * 64);
			else if (d->map[j][i] == 'C')
				mlx_put_image_to_window(d->p, d->w, d->collect, i * 64, j * 64);
			else if (d->map[j][i] == '1')
				mlx_put_image_to_window(d->p, d->w, d->wa, i * 64, j * 64);
			else if (d->map[j][i] == '0')
				mlx_put_image_to_window(d->p, d->w, d->floor, i * 64, j * 64);
			else if (d->map[j][i] == 'X')
				mlx_put_image_to_window(d->p, d->w, d->enemy, i * 64, j * 64);
		}
	}
}
