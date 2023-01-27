NAME		=	so_long

NAME_BONUS	=	so_long_bonus

SRCS		= 	so_long.c dfs_colls.c tools.c movments.c get_next_line.c get_next_line_utils.c ft_split.c libft.c check_map.c put_map.c dfs.c check_cords.c read_map.c

SRCS_BONUS	= 	so_long_bonus.c tools_bonus.c dfs_colls.c tools.c movments.c get_next_line.c get_next_line_utils.c ft_split.c libft.c check_map.c put_map.c dfs.c check_cords.c read_map.c

CC			= 	cc

CFLAGS		=	-Wall -Wextra -Werror

all				: ${NAME}

bonus			: ${NAME_BONUS}

$(NAME)			: ${SRCS}
				${CC}  ${CFLAGS} ${SRCS} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

$(NAME_BONUS)	: ${SRCS_BONUS}
				${CC}  ${CFLAGS} ${SRCS_BONUS} -lmlx -framework OpenGL -framework AppKit -o ${NAME_BONUS}

clean			:
				rm -f $(NAME)

fclean			: clean
				rm -f ${NAME_BONUS} 

re 				: fclean all 

bonus 			: all