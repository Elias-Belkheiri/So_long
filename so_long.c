/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:03:17 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/12 15:20:36 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_components	comp;

	if (argc < 2)
	{
		write(2, "NOT ENOUGH ARGS\n", 16);
		exit(EXIT_FAILURE);
	}
	read_map(argv[1], &comp);
	init_comp(&comp);
	if (!check_map(&comp))
	{
		write(2, "MAP IS FUCKED UP\n", 17);
		free_comp(&comp);
		ft_free_all_mfs(comp.map);
		exit(EXIT_FAILURE);
	}
	comp.mlx = mlx_init();
	if (!comp.mlx)
		exit(EXIT_FAILURE);
	comp.mlx_win = mlx_new_window(comp.mlx, comp.w * 55,
			comp.h * 55, "SO_LONG");
	mlx_loop_hook(comp.mlx, put_map, &comp);
	mlx_hook(comp.mlx_win, 2, 0, check_key, &comp);
	mlx_hook(comp.mlx_win, 17, 0, mlx_destroy, &comp);
	mlx_loop(comp.mlx);
}
