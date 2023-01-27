/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:16:57 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/03 13:44:57 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(char **map, t_components *comp)
{
	int	i;

	i = 0;
	while (map[comp->h])
		comp->h++;
	while (map[0][comp->w])
		comp->w++;
	while (map[0][i] && map[comp->h - 1][i])
	{
		if (map[0][i] != '1' || map[comp->h - 1][i++] != '1')
			return (0);
	}
	i = 0;
	while (i < comp->h)
	{
		if (map[i][0] != '1' || map[i++][comp->w - 1] != '1')
			return (0);
	}
	return (1);
}

int	smth(t_components *comp)
{
	if (comp->other)
	{
		write(2, "INVALID CHARACTER\n", 19);
		return (0);
	}
	if (!comp->collectable)
	{
		write(2, "NO COLLECTABLE\n", 15);
		return (0);
	}
	if (!comp->exit || comp->exit > 1)
	{
		write(2, "NO/MORE THAN ONE EXIT \n", 23);
		return (0);
	}
	if (!comp->start || comp->start > 1)
	{
		write(2, "NO/MORE THAN ONE START POSITION\n", 32);
		return (0);
	}
	return (1);
}

int	check_components(char **map, t_components *comp)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player_cords(comp, i, j);
			else if (map[i][j] == 'C')
				comp->collectable++;
			else if (map[i][j] == 'E')
				comp->exit++;
			else if (map[i][j] != '1' && map[i][j] != '0')
				comp->other++;
			j++;
		}
		i++;
	}
	return (smth(comp));
}

int	map_is_rectangular(t_components *comp)
{
	int	i;

	i = 0;
	while (comp->map[i])
	{
		if ((int)ft_strlen(comp->map[i++]) != comp->w)
		{
			write(2, "map is not rectangular\n", 23);
			return (0);
		}
	}
	return (1);
}

int	check_map(t_components *comp)
{
	int	colls;

	colls = 0;
	if (!check_walls(comp->map, comp))
	{
		write(2, "INVALID\n", 8);
		return (0);
	}
	if (!check_components(comp->map, comp))
		return (0);
	if (!map_is_rectangular(comp))
		return (0);
	if (!valid_path(comp->map, comp->p_y, comp->p_x))
	{
		write(2, "INVALID PATH\n", 13);
		return (0);
	}
	valid_colls(comp->map, comp->p_y, comp->p_x, &colls);
	if (colls != comp->collectable)
	{
		write(2, "UNREACHABLE COLLECTABLES\n", 25);
		return (0);
	}
	return (1);
}
