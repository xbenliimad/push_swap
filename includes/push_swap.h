
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../utils/libft/libft.h"
# include "../utils/ft_printf/ft_printf.h"
# include "../utils/get-next-line/get_next_line.h"

typedef struct s_stacks {
    t_list *a;
    t_list *b;
    int *v_stack;
}   t_stacks;

// Main instructions
void    parse_input(int ac, char **av, t_stacks *stacks);
void    ft_swap(t_list **stack);
void	ft_push(t_list **from, t_list **target);
void	ft_rotate(t_list **stack);
void	ft_rrotate(t_list **stack);

# endif
