/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:21:31 by hturcat           #+#    #+#             */
/*   Updated: 2023/10/02 20:56:14 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_initialize_d(t_d *d)
{
	d->map = NULL;
	d->cpy = NULL;
	d->nbline = 0;
	d->nbcol = 0;
	d->count_c = 0;
	d->collec = 0;
	d->px = 0;
	d->py = 0;
	d->exit_x = 0;
	d->exit_y = 0;
	d->mouv = 0;
}

int	ft_error(t_d *d, int error_code)
{
	if (error_code == ERROR_FD)
		ft_putstr_fd("error: FD, didn't correctly open\n", 2);
	else if (error_code == ERROR_MALLOC)
		ft_putstr_fd("error: malloc didn't work\n", 2);
	else if (error_code == ERROR_WRONG_CHAR)
		ft_putstr_fd("error: wrong char in the map\n", 2);
	else if (error_code == ERROR_TOO_MANY)
		ft_putstr_fd("error: incorrect number of player or exit\n", 2);
	else if (error_code == ERROR_NO_COLLECTIBLE)
		ft_putstr_fd("error : no collectible\n", 2);
	else if (error_code == ERROR_NO_WALL)
		ft_putstr_fd("error: incorrect formate\n", 2);
	else if (error_code == ERROR_TOO_BIG)
		ft_putstr_fd("error: map is too big\n", 2);
	else if (error_code == MAP_EMPTY)
		ft_putstr_fd("error: empty map\n", 2);
	else if (error_code == ERROR_NEWLINE)
		ft_putstr_fd("error: empty map or too many line breaks\n", 2);
	else if (error_code == PARSING_ERROR)
		ft_putstr_fd("parsing error\n", 2);
	ft_destroy_not_all(d);
	return (ERROR);
}

int	main_suite(t_d d)
{
	d.p = mlx_init();
	if (!d.p)
		return (ft_destroy(&d));
	d.w = mlx_new_window(d.p, d.nbcol * 64, d.nbline * 64, "vroum");
	if (!d.w)
		return (ft_destroy(&d));
	map_texture_vroum(&d);
	mlx_key_hook(d.w, deal_key, &d);
	mlx_hook(d.w, DestroyNotify, StructureNotifyMask, &ft_destroy, &d);
	mlx_loop(d.p);
	return (0);
}

int	main(int argc, char **argv)
{
	t_d	d;

	if (argc != 2 || ft_check_name(argv[1]) == ERROR_NAME)
	{
		write (2, "Enter 2 args or check the '.ber'\n", 33);
		return (ERROR);
	}
	ft_initialize_d(&d);
	if (ft_map_creation(&d, argv) == ERROR)
		return (ERROR);
	if (d.nbcol * 64 > 1984 || d.nbline * 64 > 960)
		return (ft_error(&d, ERROR_TOO_BIG));
	if (ft_check(&d) == ERROR)
		return (ERROR);
	ft_pos(&d);
	if (ft_backtracking(&d, d.exit_y, d.exit_x) == PARSING_ERROR)
		return (ft_error(&d, PARSING_ERROR));
	main_suite(d);
	return (0);
}
