/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:03:25 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/03 12:29:58 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_collectables(t_components *comp, int y, int x)
{
	if (comp->map[y][x] == 'c' || comp->map[y][x] == 'C')
		comp->collectable--;
}

void	mlx_put(t_components *comp, int x, int y, char *src)
{
	int	w;
	int	h;

	comp->mlx_img = mlx_xpm_file_to_image(comp->mlx, src, &w, &h);
	mlx_put_image_to_window(comp->mlx, comp->mlx_win, comp->mlx_img, x, y);
	mlx_destroy_image(comp->mlx, comp->mlx_img);
}

int	check_key(int key, t_components *comp)
{
	if (key == 53)
		mlx_destroy(comp);
	else if (key == 2 || key == 124)
		move_right(comp);
	else if (key == 0 || key == 123)
		move_left(comp);
	else if (key == 13 || key == 126)
		move_down(comp);
	else if (key == 1 || key == 125)
		move_up(comp);
	return (1);
}

void	put_wall_tree(t_components *comp, int x, int y)
{
	if (y / 55 != 0 && y / 55 != (comp->h - 1)
		&& x / 55 != 0 && x / 55 != (comp->w - 1))
	{
		mlx_put(comp, x, y, "./imgs/text3.xpm");
		mlx_put(comp, x, y, "./imgs/tree3.xpm");
	}
	else
		mlx_put(comp, x, y, "./imgs/text4.xpm");
}

int	put_map(t_components *comp)
{
	int	x;
	int	y;

	y = 0;
	while ((y / 55) < comp->h)
	{
		x = 0;
		while ((x / 55) < comp->w)
		{
			if (comp->map[y / 55][x / 55] == '1')
				put_wall_tree(comp, x, y);
			else
				mlx_put(comp, x, y, "./imgs/text3.xpm");
			if (comp->map[y / 55][x / 55] == 'E')
				mlx_put(comp, x, y, "./imgs/door.xpm");
			if (is_player(comp->map[y / 55][x / 55]))
				mlx_put(comp, x, y, comp->character);
			if (is_colls(comp->map[y / 55][x / 55]))
				mlx_put(comp, x, y, "./imgs/coll.xpm");
			x += 55;
		}
		y += 55;
	}
	return (1);
}
