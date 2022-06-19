/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:16:53 by czang             #+#    #+#             */
/*   Updated: 2022/06/19 19:54:57 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static bool	get_line(int16_t *n_line, t_string file)
{
	int16_t		read_out;
	int32_t		fd;
	char		chr[1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error(file, FILE_ERROR));
	*n_line = 0;
	read_out = 1;
	while (read_out != 0)
	{
		read_out = read(fd, chr, 1);
		if (read_out == -1)
		{
			close(fd);
			return ((int)print_error(file, READ_ERROR));
		}
		if (chr[0] == '\n')
			++(*n_line);
	}
	close(fd);
	--(*n_line);
	return (true);
}

static bool	get_file(t_all *all, u_int16_t n_line)
{
	u_int16_t	i;
	int32_t		fd;

	i = 0;
	fd = open(all->argv[1], O_RDONLY);
	if (fd == -1)
		return (print_error(NULL, FILE_ERROR));
	while (i < n_line)
		all->map1[i++] = get_next_line(fd);
	close(fd);
	return (true);
}

static bool	ber_file(t_string str)
{
	if (ft_strlen(str) < 4)
		return (false);
	while (*str)
		str++;
	str -= 4;
	if (ft_strcmp(str, ".ber") == false)
		return (false);
	return (true);
}

bool	parsing_all(t_all *all)
{
	int				read_r;
	int16_t			n_line;

	read_r = 1;
	if (all->argc != 1)
		return (print_error(NULL, ARG_ERROR));
	if (ber_file(all->argv[1]) == false)
		return (print_error(all->argv[1], NAME_ERROR));
	if (get_line(&n_line, all->argv[1]) == false)
		return (false);
	if (n_line <= 2)
		return (print_error(NULL, MAP_TO_SMALL));
	all->map1 = (char **) malloc(sizeof(char *) * (n_line + 1));
	if (!all->map1)
		return (print_error(NULL, MALLOC_ERROR));
	all->map1[n_line] = NULL;
	if (get_file(all, n_line) == false)
		return (false);
	return (parse_map(all));
}
