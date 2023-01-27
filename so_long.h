/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:26:47 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/03 22:11:16 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct data
{
	char	**map;
	char	*character;
	char	*char_up;
	char	*char_down;
	char	*char_right;
	char	*char_left;
	int		collectable;
	int		exit;
	int		start;
	int		other;
	int		color;
	int		h;
	int		w;
	int		p_x;
	int		p_y;
	int		mvs;
	int		bonus;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	*num_of_mvs;
}	t_components;

void	read_map(char *path, t_components *comp);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(const char *str, int c);
size_t	get_len(char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *ptr);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
char	*ft_itoa(int n);
void	ft_free_all_mfs(char **str);
void	free_comp(t_components *comp);
int		check_map(t_components *comp);
int		put_map(t_components *comp);
int		check_key(int key, t_components *comp);
int		mlx_destroy(t_components *comp);
void	check_collectables(t_components *comp, int y, int x);
int		valid_path(char **map, int x, int y);
void	valid_colls(char **map, int x, int y, int *colls);
void	move_up(t_components *comp);
void	move_down(t_components *comp);
void	move_right(t_components *comp);
void	move_left(t_components *comp);
void	put_wall_tree(t_components *comp, int x, int y);
void	player_cords(t_components *comp, int i, int j);
void	putstrinwin(t_components *comp);
void	init_comp(t_components *comp);
int		is_player(int a);
int		is_colls(int a);

#endif