/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_colls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:47:33 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/03 12:21:31 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_colls(int a)
{
	if (a == 'E')
		return (0);
	if (a == '0' || a == 'P')
		return (0);
	if (a != '1' && a != 'C')
		return (1);
	return (0);
}

void	visited_colls(char **map, int x, int y)
{
	if (map[x][y] == 'E')
		return ;
	if (map[x][y] == 'V')
		map[x][y] = '0';
	else if (map[x][y] == 'p')
		map[x][y] = 'P';
	else
		map[x][y] = 'C';
}

void	valid_colls(char **map, int x, int y, int *colls)
{
	if (map[x][y] == 'C' || map[x][y] == 'c')
		(*colls)++;
	visited_colls(map, x, y);
	if (check_colls(map[x][y + 1]))
		valid_colls(map, x, y + 1, colls);
	if (check_colls(map[x][y - 1]))
		valid_colls(map, x, y - 1, colls);
	if (check_colls(map[x + 1][y]))
		valid_colls(map, x + 1, y, colls);
	if (check_colls(map[x - 1][y]))
		valid_colls(map, x - 1, y, colls);
}
