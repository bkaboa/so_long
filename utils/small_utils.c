/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:03:44 by czang             #+#    #+#             */
/*   Updated: 2022/06/16 14:04:42 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

u_int32_t	ft_strlen(t_string str)
{
	t_string	tmp;

	if (!str)
		return (0);
	tmp = str;
	while (*str)
		str++;
	return (str - tmp);
}

u_int32_t	ft_strlen_db_char(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	ft_strcmp(t_string str1, t_string str2)
{
	while (*str1 && *str2)
	{
		if (*str1 - *str2 != 0)
			return (false);
		str1++;
		str2++;
	}
	return (true);
}

void	free_db_pointer(void **ptr)
{
	u_int16_t	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}
