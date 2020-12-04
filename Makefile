NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

SRC = cub3d.c \
	  libft/ft_atoi.c \
	  libft/ft_putstr_fd.c \
	  libft/ft_strlen.c \
	  libft/ft_memset.c \
	  libft/ft_strchr.c \
	  libft/ft_split.c \
	  libft/ft_strdup.c \
	  libft/ft_strjoin.c \
	  libft/ft_strncmp.c \
	  libft/ft_strtrim.c \
	  libft/ft_substr.c \
	  libft/ft_memcpy.c \
	  libft/ft_calloc.c \
	  parsing/check_width_line.c \
	  parsing/ft_initiale.c \
	  parsing/get_color.c \
	  parsing/get_next_line.c \
	  parsing/get_resolution.c \
	  parsing/get_texture.c \
	  parsing/hundle_error_free.c \
	  parsing/check_map_2d.c \
	  parsing/utils_check_map.c \
	  parsing/hundle_lines.c \
	  cub_3d/direction_ray.c \
	  cub_3d/draw_texture.c \
	  cub_3d/floor_ceilling.c \
	  cub_3d/specifie_side.c \
	  cub_3d/wall_is_hit.c \
	  cub_3d/wall_line_height.c \
	  cub_3d/sprite.c \
	  cub_3d/move.c \
	  cub_3d/rotation.c \
	  cub_3d/hundle_key.c \
	  cub_3d/init_player.c \
	  cub_3d/save_bmp.c

OBJ = ${SRC:.c=.o}

all:$(LIBFT) $(NAME) 

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all