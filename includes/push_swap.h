
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_stacks {
    t_list *a;
    t_list *b;
    int *v_stack;
}   t_stacks;

void    parse_input(int ac, char **av, t_stacks *stacks);
void    swap(t_list **stack);

# endif
