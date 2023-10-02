/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:29:48 by hturcat           #+#    #+#             */
/*   Updated: 2023/10/02 20:56:27 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_pos(t_d *d)
{
	int	i;
	int	j;

	j = 0;
	while (j < d->nbline)
	{
		i = 0;
		while (d->map[j] && d->map[j][i])
		{
			if (ft_isascii_2p_2e_c(d->map[j][i]) == ERROR_TOO_MANY_P)
			{
				d->px = i;
				d->py = j;
			}
			else if (ft_isascii_2p_2e_c(d->map[j][i]) == ERROR_TOO_MANY_E)
			{
				d->exit_x = i;
				d->exit_y = j;
			}
			i++;
		}
		j++;
	}
}
