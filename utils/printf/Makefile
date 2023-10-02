CC = clang

SOURCES = ft_printf.c \
		ft_print_c.c \
		ft_print_s.c \
		ft_print_d_i.c \
		ft_print_u.c \
		ft_print_hexa.c \
		ft_print_p.c
		

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME}

${NAME}: ${OBJECTS}
		@ar rc ${NAME} ${OBJECTS}
		@ranlib ${NAME}
		
clean:
		@rm -f *.o

fclean: clean
		@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re