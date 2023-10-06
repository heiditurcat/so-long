/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:27:41 by hturcat           #+#    #+#             */
/*   Updated: 2023/10/03 15:09:09 by hturcat          ###   ########.fr       */
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
	if (d->p_right != NULL)
		mlx_destroy_image(d->p, d->p_right);
	if (d->p_left != NULL)
		mlx_destroy_image(d->p, d->p_left);
	if (d->p_up != NULL)
		mlx_destroy_image(d->p, d->p_up);
	if (d->p_down != NULL)
		mlx_destroy_image(d->p, d->p_down);
	if (d->floor != NULL)
		mlx_destroy_image(d->p, d->floor);
	if (d->exit != NULL)
		mlx_destroy_image(d->p, d->exit);
	if (d->wa != NULL)
		mlx_destroy_image(d->p, d->wa);
	if (d->collect != NULL)
		mlx_destroy_image(d->p, d->collect);
	if (d->enemy != NULL)
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
