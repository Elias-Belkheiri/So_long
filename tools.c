/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:29:12 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/03 22:10:49 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_cords(t_components *comp, int i, int j)
{
	comp->start++;
	comp->p_y = i;
	comp->p_x = j;
}

void	putstrinwin(t_components *comp)
{
	char	*tmp;

	tmp = ft_strjoin(ft_itoa(comp->mvs), " MOVMENT\n");
	write(1, tmp, ft_strlen(tmp));
	free(tmp);
}

void	free_comp(t_components *comp)
{
	free(comp->char_up);
	free(comp->char_down);
	free(comp->char_right);
	free(comp->char_left);
	return ;
}

int	mlx_destroy(t_components *comp)
{
	mlx_destroy_window(comp->mlx, comp->mlx_win);
	free_comp(comp);
	ft_free_all_mfs(comp->map);
	if (!comp->collectable)
		write(1, "YOU WIN!\n", 9);
	else
		write(1, "YOU LOST ):\n", 12);
	exit (0);
	return (1);
}

void	init_comp(t_components *comp)
{
	comp->char_down = ft_strdup("./imgs/char_up.xpm");
	comp->char_up = ft_strdup("./imgs/char.xpm");
	comp->char_right = ft_strdup("./imgs/char_right.xpm");
	comp->char_left = ft_strdup("./imgs/char_left.xpm");
	comp->color = 0x00FFCA00;
	comp->character = comp->char_up;
	comp->collectable = 0;
	comp->exit = 0;
	comp->other = 0;
	comp->start = 0;
	comp->h = 0;
	comp->w = 0;
	comp->mvs = 0;
	comp->bonus = 0;
	comp->num_of_mvs = NULL;
}
