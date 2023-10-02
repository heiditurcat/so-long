/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_vroum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:37:17 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/29 17:46:09 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_img(t_d *d)
{
	int	width;

	d->p_up = mlx_xpm_file_to_image(d->p, \
	"./assets/player_up.xpm", &width, &width);
	d->p_down = mlx_xpm_file_to_image(d->p, \
	"./assets/player_down.xpm", &width, &width);
	d->p_right = mlx_xpm_file_to_image(d->p, \
	"./assets/player_right.xpm", &width, &width);
	d->p_left = mlx_xpm_file_to_image(d->p, \
	"./assets/player_left.xpm", &width, &width);
	d->exit = mlx_xpm_file_to_image(d->p, \
	"./assets/exit.xpm", &width, &width);
	d->wa = mlx_xpm_file_to_image(d->p, \
	"./assets/wall.xpm", &width, &width);
	d->collect = mlx_xpm_file_to_image(d->p, \
	"./assets/collectible.xpm", &width, &width);
	d->floor = mlx_xpm_file_to_image(d->p, \
	"./assets/floor.xpm", &width, &width);
	d->enemy = mlx_xpm_file_to_image(d->p, \
	"./assets/enemy.xpm", &width, &width);
}

void	map_texture_vroum(t_d *d)
{
	int	j;
	int	i;

	j = -1;
	init_img(d);
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
