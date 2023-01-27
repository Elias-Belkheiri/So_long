/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:06:58 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/03 12:29:48 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_components *comp)
{
	if (!comp->collectable && comp->map[comp->p_y][comp->p_x - 1] == 'E')
		mlx_destroy(comp);
	if (comp->map[comp->p_y][comp->p_x - 1] == 'E' && comp->collectable)
		return ;
	if (comp->map[comp->p_y][comp->p_x - 1] != '1')
	{
		comp->character = comp->char_left;
		check_collectables(comp, comp->p_y, comp->p_x - 1);
		comp->map[comp->p_y][comp->p_x] = '0';
		comp->map[comp->p_y][comp->p_x - 1] = 'P';
		comp->p_x--;
		comp->mvs++;
		if (!comp->bonus)
			putstrinwin(comp);
	}
}

void	move_right(t_components *comp)
{
	if (!comp->collectable && comp->map[comp->p_y][comp->p_x + 1] == 'E')
		mlx_destroy(comp);
	if (comp->map[comp->p_y][comp->p_x + 1] == 'E' && comp->collectable)
		return ;
	if (comp->map[comp->p_y][comp->p_x + 1] != '1')
	{
		comp->character = comp->char_right;
		check_collectables(comp, comp->p_y, comp->p_x + 1);
		comp->map[comp->p_y][comp->p_x] = '0';
		comp->map[comp->p_y][comp->p_x + 1] = 'P';
		comp->p_x++;
		comp->mvs++;
		if (!comp->bonus)
			putstrinwin(comp);
	}
}

void	move_up(t_components *comp)
{
	if (!comp->collectable && comp->map[comp->p_y + 1][comp->p_x] == 'E')
		mlx_destroy(comp);
	if (comp->map[comp->p_y + 1][comp->p_x] == 'E' && comp->collectable)
		return ;
	if (comp->map[comp->p_y + 1][comp->p_x] != '1')
	{
		comp->character = comp->char_up;
		check_collectables(comp, comp->p_y + 1, comp->p_x);
		comp->map[comp->p_y][comp->p_x] = '0';
		comp->map[comp->p_y + 1][comp->p_x] = 'P';
		comp->p_y++;
		comp->mvs++;
		if (!comp->bonus)
			putstrinwin(comp);
	}
}

void	move_down(t_components *comp)
{
	if (!comp->collectable && comp->map[comp->p_y - 1][comp->p_x] == 'E')
		mlx_destroy(comp);
	if (comp->map[comp->p_y - 1][comp->p_x] == 'E' && comp->collectable)
		return ;
	if (comp->map[comp->p_y - 1][comp->p_x] != '1')
	{
		comp->character = comp->char_down;
		check_collectables(comp, comp->p_y - 1, comp->p_x);
		comp->map[comp->p_y][comp->p_x] = '0';
		comp->map[comp->p_y - 1][comp->p_x] = 'P';
		comp->p_y--;
		comp->mvs++;
		if (!comp->bonus)
			putstrinwin(comp);
	}
}
