/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_put_player_exit_and_coin.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:00:57 by czang             #+#    #+#             */
/*   Updated: 2022/06/16 14:05:56 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	init_coin(t_all all, t_mlx_data *mlx)
{
	u_int16_t	i;
	u_int16_t	j;

	i = 0;
	j = 0;
	mlx->coin.n_coin = all.n_coin;
	while (all.map1[++i])
	{
		while (all.map1[i][++j])
			if (all.map1[i][j] == 'C')
				put_coin(j, i, mlx);
		j = 0;
	}
}

void	init_exit(t_all all, t_mlx_data *mlx)
{
	u_int16_t	i;
	u_int16_t	j;

	i = 0;
	j = 0;
	mlx->exit.door_open = false;
	while (all.map1[++i])
	{
		while (all.map1[i][++j])
			if (all.map1[i][j] == 'E')
				put_exit(j, i, mlx);
	j = 0;
	}
}

void	init_player(t_all all, t_mlx_data *mlx)
{
	u_int16_t	i;
	u_int16_t	j;

	i = 0;
	j = 0;
	while (all.map1[++i])
	{
		while (all.map1[i][++j])
		{
			if (all.map1[i][j] == 'P')
			{
				put_player(j, i, mlx);
				mlx->player.pos_x = j;
				mlx->player.pos_y = i;
				return ;
			}
		}
		j = 0;
	}
}
