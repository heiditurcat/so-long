/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:46:36 by hturcat           #+#    #+#             */
/*   Updated: 2023/10/02 20:24:02 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include <mlx.h>

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> 
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

# define ERROR_NEWLINE -14
# define PARSING_ERROR -13
# define MAP_EMPTY -12
# define ERROR_TOO_BIG -11
# define ERROR_NAME -10
# define ERROR_NO_WALL -9
# define ERROR_C -8
# define ERROR_NO_COLLECTIBLE -7
# define ERROR_TOO_MANY -6
# define ERROR_TOO_MANY_E -5
# define ERROR_TOO_MANY_P -4
# define ERROR_WRONG_CHAR -3
# define ERROR_FD -2
# define ERROR_MALLOC -1
# define ERROR 0
# define SUCCESS 1
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

//STUCTURE

typedef struct s_d{
	char	**map;
	char	**cpy;
	int		nbline;
	int		nbcol;
	void	*p;
	void	*w;
	void	*p_up;
	void	*p_down;
	void	*p_right;
	void	*p_left;
	void	*exit;
	void	*wa;
	void	*collect;
	void	*floor;
	void	*enemy;
	int		px;
	int		py;
	int		exit_x;
	int		exit_y;
	int		count_c;
	int		collec;
	int		mouv;
	int		x;
	int		y;
}	t_d;

///////////////////////////////////////////
//										 //
//               SOURCES				 //
//									     //
///////////////////////////////////////////

// main.c
int		main(int argc, char **argv);
int		ft_error(t_d *d, int error_code);
void	ft_initialize_d(t_d *d);

// map_creation.c
int		ft_map_creation(t_d *d, char **argv);
int		ft_map_creation_suite(t_d *d, char *map_line, char *line, int fd);
int		ft_check_empty(char *map_line);

// texture.c
// int	map_texture(t_d *d);

// texture_vroum.c
void	map_texture_vroum(t_d *d);

// backtracking.c
int		ft_backtracking(t_d *d, int x, int y);
int		ft_recursive(t_d *d, int y, int x);

// position.c
void	ft_pos(t_d *d);

// moving.c
int		deal_key(int keysym, t_d *d);
int		ft_move(t_d *d, int j, int i);

// end_game.c
int		ft_destroy(t_d *d);
int		ft_destroy_not_all(t_d *d);
void	**ft_free(t_d *d, char **strstr);

///////// PARSING /////////

// check_1.c
int		ft_check(t_d *d);
int		ft_check_no_wall(t_d *d);
int		ft_check_no_intrude(t_d *d);
int		ft_isascii(int c);
//  check_2.c
int		ft_check_name(char *name);
int		ft_check_nb_player_exit(t_d *d);
int		ft_check_collectible(t_d *d);
int		ft_isascii_2p_2e_c(int c);

#endif
