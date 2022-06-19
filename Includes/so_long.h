/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:01:11 by czang             #+#    #+#             */
/*   Updated: 2022/06/19 19:54:59 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../utils/gnl/get_next_line.h"
# include <fcntl.h>

# define MAX_SCREEN_H 1310
# define MAX_SCREEN_L 2560

# define ARG_ERROR		"need 1 file\n"
# define FILE_ERROR		" : no such file or permission denied\n"
# define NAME_ERROR		" : not a .ber file\n"
# define READ_ERROR		" : read_error\n"
# define MAP_ERROR_1	"all the card border doesn't carefuly closed\n"
# define MAP_ERROR_2	"2 maps in 1 file\n"
# define ENTITY_ERROR	" in file\n"
# define MAP_SQUARE		"map need to be a square\n"
# define MAP_TO_LARGE	"map too large\n"
# define MAP_BORDER		"border map need to be a wall '1'\n"
# define INSIDE_MAP		"char map need to be '10PCE'\n"
# define PLAYER			"map need at least one player\n"
# define COIN_EXIT		"map need at least one coin and one exit\n"
# define MAP_TO_SMALL	"map doesn't exist or are too small\n"
# define MALLOC_ERROR	"malloc error\n"
# define ERROR_TEXTURE	" : texture in main/sprite doesn't exist\n"

typedef char*	t_string;

typedef struct s_bulle
{
	void					*sprite_player;
	int						pos_x;
	int						pos_y;
}	t_bulle;

typedef struct s_coin
{
	void					*sprite_coin;
	u_int16_t				n_coin;
}	t_coin;

typedef struct s_exit
{
	void					*sprite_exit;
	bool					door_open;
	bool					open_close;
}	t_exit;

typedef struct s_mlx_data
{
	void					*mlx;
	void					*mlx_win;
	t_bulle					player;
	t_coin					coin;
	t_exit					exit;
	void					*wall_sprite;
	void					*floor_sprite;
}	t_mlx_data;

typedef struct s_screen_data
{
	int						screen_lenght;
	int						screen_height;
}	t_screen_data;

typedef struct s_all
{
	int						argc;
	char					**argv;
	char					**map1;
	u_int16_t				n_coin;
}	t_all;

typedef struct s_mlx_and_all_data
{
	t_mlx_data	*mlx;
	t_all		*all;
	int			i;
}	t_mlx_and_all_data;

/*
 *
 ******************************	parsing					***
 */
bool		parse_map(t_all *all);

/*
 *
 ******************************	graphical		***
 */
void		new_window(t_all *all);
void		init_screen(t_mlx_data *mlx, t_screen_data *screen, t_all all);
void		draw_map(t_mlx_data *mlx, t_all all);
void		init_sprite(t_mlx_data *mlx);
bool		print_error(t_string str1, t_string str2);

/*
 *
 ******************************	parsing					***
 */
bool		parsing_all(t_all *all);

/*
 *
 ******************************	utils					***
 */
u_int32_t	ft_strlen(t_string str);
u_int32_t	ft_strlen_db_char(char **str);
void		free_db_pointer(void **ptr);
bool		ft_strcmp(t_string str1, t_string str2);

/*
 *
 ******************************	graphical/put_sprite.c	***
 */
void		put_exit(u_int32_t x, u_int32_t y, t_mlx_data *mlx);
void		put_player(u_int32_t x, u_int32_t y, t_mlx_data *mlx);
void		put_coin(u_int32_t x, u_int32_t y, t_mlx_data *mlx);
void		put_wall(u_int32_t x, u_int32_t y, t_mlx_data *mlx);
void		put_floor(u_int32_t x, u_int32_t y, t_mlx_data *mlx);

/*
 *
 ******************************	graphical/ini_and_put...***
 */
void		init_coin(t_all all, t_mlx_data *mlx);
void		init_exit(t_all all, t_mlx_data *mlx);
void		init_player(t_all all, t_mlx_data *mlx);
void		game(t_mlx_data *mlx, t_all *all);

/*
 *
 ******************************	graphical/player_move...	***
 */
void		move_up(t_mlx_and_all_data *mlx_and_all);
void		move_down(t_mlx_and_all_data *mlx_and_all);
void		move_left(t_mlx_and_all_data *mlx_and_all);
void		move_right(t_mlx_and_all_data *mlx_and_all);
void		destroy_game(t_mlx_and_all_data *mlx_and_all);

#endif
