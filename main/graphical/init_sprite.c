/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:01:24 by czang             #+#    #+#             */
/*   Updated: 2022/06/18 16:50:26 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	init_sprite(t_mlx_data *mlx)
{
	int		img_l[1];
	int		img_h[1];

	mlx->wall_sprite = mlx_xpm_file_to_image(mlx->mlx, \
			"main/sprite/wall.xpm", img_h, img_l);
	mlx->floor_sprite = mlx_xpm_file_to_image(mlx->mlx, \
			"main/sprite/floor.xpm", img_h, img_l);
	mlx->coin.sprite_coin = mlx_xpm_file_to_image(mlx->mlx, \
			"main/sprite/coin.xpm", img_h, img_l);
	mlx->player.sprite_player = mlx_xpm_file_to_image(mlx->mlx, \
			"main/sprite/player.xpm", img_h, img_l);
	mlx->exit.sprite_exit = mlx_xpm_file_to_image(mlx->mlx, \
			"main/sprite/door.xpm", img_h, img_l);
}
