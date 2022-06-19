/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:25:48 by czang             #+#    #+#             */
/*   Updated: 2022/06/16 14:15:51 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static bool	parse_coins_and_exit(t_all *all)
{
	u_int16_t	c;
	u_int16_t	e;
	u_int16_t	i;
	u_int16_t	j;

	c = 0;
	e = 0;
	i = 0;
	j = 0;
	while (all->map1[++i])
	{
		while (all->map1[i][++j])
		{
			if (all->map1[i][j] == 'E')
				e++;
			if (all->map1[i][j] == 'C')
				c++;
		}
		j = 0;
	}
	if (e == 0 || c == 0)
		return (print_error(NULL, COIN_EXIT));
	all->n_coin = c;
	return (true);
}

static bool	parse_player(t_all *all)
{
	u_int16_t	p;
	u_int16_t	i;
	u_int16_t	j;

	p = 0;
	i = 0;
	j = 0;
	while (all->map1[++i])
	{
		while (all->map1[i][++j])
		{
			if (all->map1[i][j] == 'P')
				++p;
			if (all->map1[i][j] == 'P' && p > 1)
				all->map1[i][j] = '0';
		}
		j = 0;
	}
	if (p == 0)
		return (print_error(NULL, PLAYER));
	return (parse_coins_and_exit(all));
}

static bool	parse_inside_map(t_all *all)
{
	u_int16_t	i;
	u_int16_t	j;
	char		*str;
	char		*temp;

	str = "10EPC\n\0";
	temp = str;
	i = 0;
	j = 0;
	while (all->map1[++i])
	{
		while (all->map1[i][++j])
		{
			while (*str && all->map1[i][j] != *str)
				str++;
			if (*str == '\0')
				return (print_error(NULL, INSIDE_MAP));
			str = temp;
		}
		j = 0;
	}
	return (parse_player(all));
}

static bool	map_border(t_all *all)
{
	u_int16_t	y;
	u_int16_t	i;

	y = 0;
	i = -1;
	while (all->map1[0][y] != '\n' && all->map1[0][y])
		if (all->map1[0][y++] != '1')
			return (print_error(NULL, MAP_BORDER));
	--y;
	while (all->map1[++i])
		if (all->map1[i][0] != '1' || all->map1[i][y] != '1')
			return (print_error(NULL, MAP_BORDER));
	y = 0;
	--i;
	while (all->map1[i][y] != '\n' && all->map1[i][y])
		if (all->map1[i][y++] != '1')
			return (print_error(NULL, MAP_BORDER));
	return (parse_inside_map(all));
}

bool	parse_map(t_all *all)
{
	u_int8_t	i;
	u_int16_t	temp;

	i = 0;
	while (all->map1[i + 1])
	{
		temp = ft_strlen(all->map1[i]);
		if (temp != ft_strlen(all->map1[++i]))
			return (print_error(NULL, MAP_SQUARE));
	}
	++i;
	if (temp * 64 > MAX_SCREEN_L || i * 64 > MAX_SCREEN_H)
		return (print_error(NULL, MAP_TO_LARGE));
	return (map_border(all));
}
