/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:06:40 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/03 11:57:43 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid(int a)
{
	if (a == 'p' || a == 'V')
		return (0);
	if (a != '1' && a != 'c')
		return (1);
	return (0);
}

void	visited(char **map, int x, int y)
{
	if (map[x][y] == '0')
		map[x][y] = 'V';
	else if (map[x][y] == 'P')
		map[x][y] = 'p';
	else
		map[x][y] = 'c';
}

int	valid_path(char **map, int x, int y)
{
	if (map[x][y] == 'E')
		return (1);
	visited(map, x, y);
	if (valid(map[x][y + 1]))
	{
		if (valid_path(map, x, y + 1))
			return (1);
	}
	if (valid(map[x][y - 1]))
	{
		if (valid_path(map, x, y - 1))
			return (1);
	}
	if (valid(map[x + 1][y]))
	{
		if (valid_path(map, x + 1, y))
			return (1);
	}
	if (valid(map[x - 1][y]))
	{
		if (valid_path(map, x - 1, y))
			return (1);
	}
	return (0);
}
