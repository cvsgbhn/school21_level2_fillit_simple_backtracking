.PHONY: clean fclean re make all

FILENAMES = fillit.c
FILENAMES +=  basic_calculations.c
FILENAMES += dlx_algorithm.c dlx_structures_routine.c
FILENAMES += preparing_routine.c
NAME = fillit

SRCS	=$(addprefix sources/, $(FILENAMES))
OBJS	=$(addprefix build/, $(FILENAMES:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -I includes/
LFLAGS	= -L ./libft/

all: $(NAME)

$(NAME):$(OBJS) | lib
	@$(CC) $(CFLAGS) -o $(NAME) $(LFLAGS) $(OBJS) -lft

build/%.o: sources/%.c | build
	@$(CC) $(CFLAGS) -o $@ -c $^

re: fclean all

lib:
	@make -C ./libft
	@make clean -C ./libft

clean:
	@rm -rf build/

fclean: clean
	@make fclean -C ./Libft
	@rm -f $(NAME)

build:
	@mkdir build/