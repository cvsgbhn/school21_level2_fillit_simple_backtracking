.PHONY: clean fclean re make all

NAME = fillit
SRCS = ./sources/main.c ./sources/fillit.c ./sources/tetro_structure_routine.c ./sources/basic_calculations.c
OBJS = ${SRCS:.c=.o}
HDR = ./includes/
FLAGS = -Wall -Wextra -Werror

LIBFT = libft/

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HDR) -L. libft/libft.a

clean:
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

