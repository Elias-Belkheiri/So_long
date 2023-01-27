/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:35:56 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/12 15:20:18 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *path, t_components *comp)
{
	int		fd;
	char	*str;
	char	*tmp;

	fd = open(path, O_RDONLY);
	str = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		printf("%s", tmp);
		if (!tmp)
			break ;
		if (ft_strlen(tmp) == 1 && *tmp == '\n')
		{
			write(2, "INVALID MAP\n", 12);
			exit(EXIT_FAILURE);
		}
		str = ft_strjoin(str, tmp);
		free(tmp);
	}
	close(fd);
	comp->map = ft_split(str, '\n');
	free(str);
}
