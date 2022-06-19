/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:13:03 by czang             #+#    #+#             */
/*   Updated: 2022/06/18 16:55:42 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	main(int argc, char **argv)
{
	t_all		all;

	argv[argc] = NULL;
	all.argc = argc - 1;
	all.argv = argv;
	all.map1 = NULL;
	if (parsing_all(&all) == false)
	{
		if (all.map1)
			free_db_pointer((void **)all.map1);
		return (1);
	}
	new_window(&all);
}
