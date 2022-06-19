/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:25:05 by czang             #+#    #+#             */
/*   Updated: 2022/06/16 14:05:18 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	put_exit(u_int32_t x, u_int32_t y, t_mlx_data *mlx)
{
	x *= 64;
	y *= 64;
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->exit.sprite_exit, x, y);
}

void	put_player(u_int32_t x, u_int32_t y, t_mlx_data *mlx)
{
	x *= 64;
	y *= 64;
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->player.sprite_player, x, y);
}

void	put_coin(u_int32_t x, u_int32_t y, t_mlx_data *mlx)
{
	x *= 64;
	y *= 64;
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->coin.sprite_coin, x, y);
}

void	put_wall(u_int32_t x, u_int32_t y, t_mlx_data *mlx)
{
	x *= 64;
	y *= 64;
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->wall_sprite, x, y);
}

void	put_floor(u_int32_t x, u_int32_t y, t_mlx_data *mlx)
{
	x *= 64;
	y *= 64;
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->floor_sprite, x, y);
}
