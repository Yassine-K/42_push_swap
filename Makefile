SRC =	final.c moves.c	nodes.c	ft_sort.c	file.c helpers.c	getNext/get_next_line.c	getNext/get_next_line_utils.c 

NAME = push_swap

INC = Libft/libft.a

all: ${NAME}

${NAME}: ${SRC}
	@make bonus -C ./Libft
	@cc -Wall -Wextra -Werror $^ ${INC} -o $@ -D M=1

clean:
	@make clean -C ./Libft

fclean: clean
	@make fclean -C ./Libft
	@rm -f ${NAME} checker

bonus: ${SRC}
	@make bonus -C ./Libft
	@cc -Wall -Wextra -Werror $^ ${INC} -o checker -D M=0

re: fclean all

.PHONY: all clean fclean bonus re