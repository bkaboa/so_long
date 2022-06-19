/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen_and_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:11:34 by czang             #+#    #+#             */
/*   Updated: 2022/06/16 14:05:42 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	draw_map(t_mlx_data *mlx, t_all all)
{
	u_int16_t	i;
	u_int16_t	j;

	i = -1;
	j = -1;
	while (all.map1[++j])
	{
		while (all.map1[j][++i] != '\n')
		{
			if (all.map1[j][i] == '1')
				put_wall(i, j, mlx);
			else
				put_floor(i, j, mlx);
		}
		i = -1;
	}
	init_coin(all, mlx);
	init_player(all, mlx);
	init_exit(all, mlx);
}

void	init_screen(t_mlx_data *mlx, t_screen_data *screen, t_all all)
{
	screen->screen_lenght = (ft_strlen(all.map1[0]) - 1) * 64;
	screen->screen_height = ft_strlen_db_char(all.map1) * 64;
	mlx->mlx_win = mlx_new_window(mlx->mlx, screen->screen_lenght, \
			screen->screen_height, "so_long");
}
