NAME= push_swap

NAME_BONUS= checker

SRC= ./src/find_lis.c \
./src/find_lis_utils.c \
./src/handle_instructions.c \
./src/handle_small.c \
./src/handle_sorting.c \
./src/instructions.c \
./src/main.c \
./src/move_calculator.c \
./src/move_calculator_utils.c \
./src/parsing.c \
./src/utils.c

SRC_BONUS= ./bonus/checker_utils.c \
./bonus/handle_instructions.c \
./bonus/instructions.c \
./bonus/main.c \
./src/utils.c \
./src/parsing.c \
./src/find_lis_utils.c

OBJ=$(SRC:%.c=%.o)

OBJ_BONUS=$(SRC_BONUS:%.c=%.o);

INCLUDES= -I./includes -I./utils/libft -I./utils/get-next-line -I./utils/ft_printf

FLAGS= -Wall -Wextra -Werror $(INCLUDES) # -fsanitize=address

CC= cc

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@


all : $(NAME) 

bonus : $(NAME_BONUS)

$(NAME) : $(OBJ) ./utils/libft/libft.a ./utils/ft_printf/libftprintf.a ./utils/get-next-line/get_next_line.a
	$(CC) $(FLAGS) $^ -o $@

$(NAME_BONUS) : ./utils/libft/libft.a ./utils/ft_printf/libftprintf.a ./utils/get-next-line/get_next_line.a $(OBJ_BONUS)
	$(CC) $(FLAGS) $^ -o $@


./utils/libft/libft.a :
	make -C ./utils/libft  bonus


./utils/ft_printf/libftprintf.a :
	make -C ./utils/ft_printf

./utils/get-next-line/get_next_line.a :
	make -C ./utils/get-next-line


clean :
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	make -C ./utils/libft clean
	make -C ./utils/ft_printf clean
	make -C ./utils/get-next-line clean

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make -C ./utils/libft fclean
	make -C ./utils/ft_printf fclean
	make -C ./utils/get-next-line fclean

re : fclean all


.PHONY : all fclean clean re