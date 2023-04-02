NAME= push_swap

SRC= ${wildcard ./src/*.c}  ${wildcard ./src/**/*.c}

OBJ=$(SRC:%.c=%.o)

INCLUDES= -I./includes -I./libft -I./get-next-line -I./ft_printf

FLAGS= -Wall -Wextra -Werror -fsanitize=address $(INCLUDES)

CC= cc

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@

./libft/libft.a : 
	make -C ./libft  bonus

./ft_printf/libftprintf.a :
	make -C ./ft_printf

./get-next-line/get_next_line.a :
	make -C ./get-next-line

all : $(NAME) 

$(NAME) : $(OBJ) ./libft/libft.a ./ft_printf/libftprintf.a ./get-next-line/get_next_line.a
	$(CC) $(FLAGS) $^ -o $@

clean :
	rm -f $(OBJ)
	make -C ./libft clean
	make -C ./ft_printf clean
	make -C ./get-next-line clean

fclean : clean
	rm -f $(NAME)
	make -C ./libft fclean
	make -C ./ft_printf fclean
	make -C ./get-next-line fclean

re : fclean all

.PHONY : all fclean clean re