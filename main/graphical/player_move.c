/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:36:37 by czang             #+#    #+#             */
/*   Updated: 2022/06/18 16:55:01 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	move_up(t_mlx_and_all_data *mlx_and_all)
{
	u_int16_t	x;
	u_int16_t	y;

	x = mlx_and_all->mlx->player.pos_x;
	y = mlx_and_all->mlx->player.pos_y - 1;
	if (mlx_and_all->all->map1[y][x] != '1')
	{
		mlx_and_all->i++;
		if (mlx_and_all->all->map1[y][x] == 'C')
		{
			mlx_and_all->mlx->coin.n_coin--;
			mlx_and_all->all->map1[y][x] = '0';
		}
		if (mlx_and_all->all->map1[y][x] == 'E' \
				&& mlx_and_all->mlx->coin.n_coin == 0)
			destroy_game(mlx_and_all);
		put_player(x, y, mlx_and_all->mlx);
		put_floor(x, y + 1, mlx_and_all->mlx);
		mlx_and_all->mlx->player.pos_y = y;
		if (mlx_and_all->all->map1[y + 1][x] == 'E')
			put_exit(x, y + 1, mlx_and_all->mlx);
		printf("%d\n", mlx_and_all->i);
	}
}

void	move_down(t_mlx_and_all_data *mlx_and_all)
{
	u_int16_t	x;
	u_int16_t	y;

	x = mlx_and_all->mlx->player.pos_x;
	y = mlx_and_all->mlx->player.pos_y + 1;
	if (mlx_and_all->all->map1[y][x] != '1')
	{
		mlx_and_all->i++;
		if (mlx_and_all->all->map1[y][x] == 'C')
		{
			mlx_and_all->mlx->coin.n_coin--;
			mlx_and_all->all->map1[y][x] = '0';
		}
		if (mlx_and_all->all->map1[y][x] == 'E' \
				&& mlx_and_all->mlx->coin.n_coin == 0)
			destroy_game(mlx_and_all);
		put_player(x, y, mlx_and_all->mlx);
		put_floor(x, y - 1, mlx_and_all->mlx);
		mlx_and_all->mlx->player.pos_y = y;
		if (mlx_and_all->all->map1[y - 1][x] == 'E')
			put_exit(x, y - 1, mlx_and_all->mlx);
		printf("%d\n", mlx_and_all->i);
	}
}

void	move_right(t_mlx_and_all_data *mlx_and_all)
{
	u_int16_t	x;
	u_int16_t	y;

	x = mlx_and_all->mlx->player.pos_x + 1;
	y = mlx_and_all->mlx->player.pos_y;
	if (mlx_and_all->all->map1[y][x] != '1')
	{
		mlx_and_all->i++;
		if (mlx_and_all->all->map1[y][x] == 'C')
		{
			mlx_and_all->mlx->coin.n_coin--;
			mlx_and_all->all->map1[y][x] = '0';
		}
		if (mlx_and_all->all->map1[y][x] == 'E' \
				&& mlx_and_all->mlx->coin.n_coin == 0)
			destroy_game(mlx_and_all);
		put_player(x, y, mlx_and_all->mlx);
		put_floor(x - 1, y, mlx_and_all->mlx);
		mlx_and_all->mlx->player.pos_x = x;
		if (mlx_and_all->all->map1[y][x - 1] == 'E')
			put_exit(x - 1, y, mlx_and_all->mlx);
		printf("%d\n", mlx_and_all->i);
	}
}

void	move_left(t_mlx_and_all_data *mlx_and_all)
{
	u_int16_t	x;
	u_int16_t	y;

	x = mlx_and_all->mlx->player.pos_x - 1;
	y = mlx_and_all->mlx->player.pos_y;
	if (mlx_and_all->all->map1[y][x] != '1')
	{
		mlx_and_all->i++;
		if (mlx_and_all->all->map1[y][x] == 'C')
		{
			mlx_and_all->mlx->coin.n_coin--;
			mlx_and_all->all->map1[y][x] = '0';
		}
		if (mlx_and_all->all->map1[y][x] == 'E' \
				&& mlx_and_all->mlx->coin.n_coin == 0)
			destroy_game(mlx_and_all);
		put_player(x, y, mlx_and_all->mlx);
		put_floor(x + 1, y, mlx_and_all->mlx);
		mlx_and_all->mlx->player.pos_x = x;
		if (mlx_and_all->all->map1[y][x + 1] == 'E')
			put_exit(x + 1, y, mlx_and_all->mlx);
		printf("%d\n", mlx_and_all->i);
	}
}

void	destroy_game(t_mlx_and_all_data *mlx_and_all)
{
	free_db_pointer((void **)mlx_and_all->all->map1);
	mlx_clear_window(mlx_and_all->mlx->mlx, mlx_and_all->mlx->mlx_win);
	mlx_destroy_window(mlx_and_all->mlx->mlx, mlx_and_all->mlx->mlx_win);
	exit(0);
}
