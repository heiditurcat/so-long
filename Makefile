NAME = so_long
SRCS =  ./sources/main.c				\
		./sources/map_creation.c 		\
		./sources/texture_vroum.c		\
		./sources/position.c 			\
		./sources/moving.c 				\
		./sources/end_game.c 			\
		./sources/parsing/backtracking.c 		\
		./sources/parsing/check_1.c		\
		./sources/parsing/check_2.c		\

OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
PRINTF = utils/printf/libftprintf.a
CC = cc 
FLAGS = -Wall -Wextra -Werror -g3

all: mlx $(NAME)

$(NAME): $(OBJS)
	@cd libft && make -s
	@cd utils/printf && make -s
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(PRINTF) -L./minilibx-linux  -L/usr/lib -Imlx_linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)
	@echo "so_long compiled !"

%.o: %.c
	@$(CC) $(FLAGS) -I/usr/include -I./minilibx-linux/ -O3 -c $< -o $@

mlx: 
	@cd minilibx-linux && make -s || (echo "minilibx compilation failed"; exit 1)
	@echo "MLX compiled !"

clean:
	@cd libft && make -s clean
	@rm -f $(OBJS)
	@echo "so_long's object files deleted !"

fclean: clean
	@cd libft && make -s fclean
	@cd utils/printf && make -s fclean
	@rm -f $(NAME)
	@echo "so_long deleted !"

re: fclean all

.PHONY: all clean fclean re
