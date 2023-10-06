/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:50:16 by hturcat           #+#    #+#             */
/*   Updated: 2023/10/03 14:06:59 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../utils/printf/ft_printf.h"

int	c(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	deal_key(int keysym, t_d *d)
{
	if (keysym == XK_Escape)
		ft_destroy(d);
	if (keysym == 'a' || keysym == XK_Left)
		ft_move(d, 0, -1);
	if (keysym == 'd' || keysym == XK_Right)
		ft_move(d, 0, 1);
	if (keysym == 'w' || keysym == XK_Up)
		ft_move(d, -1, 0);
	if (keysym == 's' || keysym == XK_Down)
		ft_move(d, 1, 0);
	return (0);
}

static void	end_destroy(t_d *d, int p_y, int p_x)
{	
	if (d->map[p_y][p_x] == 'E' && d->collec == d->count_c)
	{
		ft_putstr_fd("\n\n -- CONGRATULATION --\n       you won\n", 1);
		ft_destroy(d);
	}
	if (d->map[p_y][p_x] == 'X')
	{
		ft_putstr_fd("\n\nyou've crashed into an enemy\n     -- GAME OVER --\n", 1);
		ft_destroy(d);
	}
}

void	ft_move_suite(t_d *d, int j, int i)
{
	int	x;
	int	y;

	x = d->px * 64;
	y = d->py * 64;
	mlx_put_image_to_window(d->p, d->w, d->floor, x, y);
	d->py += j;
	d->px += i;
	x = d->px * 64;
	y = d->py * 64;
	if (i == 1 && j == 0)
		mlx_put_image_to_window(d->p, d->w, d->p_right, x, y);
	else if (i == -1 && j == 0)
		mlx_put_image_to_window(d->p, d->w, d->p_left, x, y);
	else if (j == -1 && i == 0)
		mlx_put_image_to_window(d->p, d->w, d->p_up, x, y);
	else if (j == 1 && i == 0)
		mlx_put_image_to_window(d->p, d->w, d->p_down, x, y);
}

int	ft_move(t_d *d, int j, int i)
{
	char	*nb_mouv;
	int		p_y;
	int		p_x;

	p_x = d->px + i;
	p_y = d->py + j;
	end_destroy(d, p_y, p_x);
	if (d->map[p_y][p_x] != '1' && d->map[p_y][p_x] != 'E')
	{
		if (d->map[p_y][p_x] == 'C')
		{
			d->collec += 1;
			d->map[p_y][p_x] = '0';
		}
		ft_move_suite(d, j, i);
		d->mouv += 1;
		ft_printf ("\rnb mouv : %i", d->mouv);
	}
	mlx_put_image_to_window(d->p, d->w, d->wa, 0, 0);
	nb_mouv = ft_itoa(d->mouv);
	mlx_string_put(d->p, d->w, 25, 30, c(255, 255, 255, 255), nb_mouv);
	free(nb_mouv);
	return (0);
}
