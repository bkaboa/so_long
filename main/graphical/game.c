/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:36:12 by czang             #+#    #+#             */
/*   Updated: 2022/06/16 14:07:30 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static int	which_code(int keycode, t_mlx_and_all_data *mlx_and_all)
{
	if (keycode == 13 || keycode == 126)
		move_up(mlx_and_all);
	if (keycode == 0 || keycode == 123)
		move_left(mlx_and_all);
	if (keycode == 1 || keycode == 125)
		move_down(mlx_and_all);
	if (keycode == 2 || keycode == 124)
		move_right(mlx_and_all);
	if (keycode == 53)
		destroy_game(mlx_and_all);
	return (keycode);
}

static int	exit_game(t_mlx_and_all_data *mlx_and_all)
{
	destroy_game(mlx_and_all);
	return (0);
}

void	game(t_mlx_data *mlx, t_all *all)
{
	t_mlx_and_all_data	mlx_and_all;

	mlx_and_all.i = 0;
	mlx_and_all.mlx = mlx;
	mlx_and_all.all = all;
	mlx_key_hook(mlx->mlx_win, which_code, &mlx_and_all);
	mlx_hook(mlx->mlx_win, 17, 1L << 0, &exit_game, &mlx_and_all);
	mlx_loop(mlx->mlx);
}
