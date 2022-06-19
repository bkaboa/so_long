/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:02:01 by czang             #+#    #+#             */
/*   Updated: 2022/06/15 23:06:26 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

bool	print_error(t_string str1, t_string str2)
{
	write(2, "Error\n", 6);
	write(2, str1, ft_strlen(str1));
	write(2, str2, ft_strlen(str2));
	return (false);
}
