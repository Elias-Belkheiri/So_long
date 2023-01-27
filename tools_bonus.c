/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:23:12 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/03 12:30:13 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	render_frames(t_components *comp)
{
	static int	i;
	static int	j;
	static int	l;

	if (j % 1 == 0)
	{
		if (i > 15)
			l = 1;
		else if (!i)
			l = 0;
		if (!l)
			i++;
		else
			i--;
	}
	j++;
	put_map_bonus(comp, i);
	return (1);
}

void	putstrinwin_bonnus(t_components *comp)
{
	char	*tmp;

	tmp = ft_strjoin(ft_itoa(comp->mvs), " MOVMENT\n");
	mlx_string_put(comp->mlx, comp->mlx_win, 10, 10, comp->color, tmp);
	free(tmp);
}

int	put_map_bonus(t_components *comp, int i)
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
				mlx_put(comp, x, y - i, "./imgs/coll.xpm");
			x += 55;
		}
		y += 55;
	}
	putstrinwin_bonnus(comp);
	return (1);
}
