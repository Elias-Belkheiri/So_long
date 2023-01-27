/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:44:30 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/03 14:31:54 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_components	comp;

	if (argc < 2)
	{
		write(2, "NOT ENOUGH ARGS\n", 16);
		exit(1);
	}
	read_map(argv[1], &comp);
	init_comp(&comp);
	if (!check_map(&comp))
	{
		write(2, "MAP IS FUCKED UP\n", 17);
		free_comp(&comp);
		ft_free_all_mfs(comp.map);
		exit(1);
	}
	comp.bonus = 1;
	comp.mlx = mlx_init();
	if (!comp.mlx)
		exit(EXIT_FAILURE);
	comp.mlx_win = mlx_new_window(comp.mlx, comp.w * 55,
			comp.h * 55, "SO_LONG_BONUS");
	mlx_loop_hook(comp.mlx, render_frames, &comp);
	mlx_hook(comp.mlx_win, 2, 0, check_key, &comp);
	mlx_loop(comp.mlx);
}
