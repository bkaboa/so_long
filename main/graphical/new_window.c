/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:42:17 by czang             #+#    #+#             */
/*   Updated: 2022/06/18 17:03:48 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

static bool	texture_parsing(t_mlx_data *mlx)
{
	if ((int32_t)mlx->wall_sprite == 0)
		return (print_error("wall.xpm", ERROR_TEXTURE));
	if ((int32_t)mlx->floor_sprite == 0)
		return (print_error("floor.xpm", ERROR_TEXTURE));
	if ((int32_t)mlx->coin.sprite_coin == 0)
		return (print_error("coin.xpm", ERROR_TEXTURE));
	if ((int32_t)mlx->player.sprite_player == 0)
		return (print_error("player.xpm", ERROR_TEXTURE));
	if ((int32_t)mlx->exit.sprite_exit == 0)
		return (print_error("door.xpm", ERROR_TEXTURE));
	return (true);
}

static void	destroy_mlx_and_all(t_all *all, t_mlx_data *mlx)
{
	free_db_pointer((void **)all->map1);
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

void	new_window(t_all *all)
{
	t_mlx_data		mlx;
	t_screen_data	screen;

	mlx.mlx = mlx_init();
	init_screen(&mlx, &screen, *all);
	init_sprite(&mlx);
	if (texture_parsing(&mlx) == false)
		return (destroy_mlx_and_all(all, &mlx));
	draw_map(&mlx, *all);
	game(&mlx, all);
}
