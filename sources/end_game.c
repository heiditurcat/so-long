/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:27:41 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/29 18:48:59 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	**ft_free(t_d *d, char **strstr)
{
	int	i;

	i = 0;
	while (i < d->nbline)
	{
		free (strstr[i]);
		strstr[i] = NULL;
		i++;
	}
	free (strstr);
	return (NULL);
}

int	ft_destroy(t_d *d)
{
	ft_free(d, d->map);
	mlx_destroy_image(d->p, d->p_right);
	mlx_destroy_image(d->p, d->p_left);
	mlx_destroy_image(d->p, d->p_up);
	mlx_destroy_image(d->p, d->p_down);
	mlx_destroy_image(d->p, d->floor);
	mlx_destroy_image(d->p, d->exit);
	mlx_destroy_image(d->p, d->wa);
	mlx_destroy_image(d->p, d->collect);
	mlx_destroy_image(d->p, d->enemy);
	mlx_destroy_window(d->p, d->w);
	mlx_destroy_display(d->p);
	free(d->p);
	exit(0);
	return (0);
}

int	ft_destroy_not_all(t_d *d)
{
	if (d->map)
		ft_free(d, d->map);
	exit(0);
	return (0);
}
