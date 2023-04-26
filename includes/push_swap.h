
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../utils/libft/libft.h"
# include "../utils/ft_printf/ft_printf.h"
# include "../utils/get-next-line/get_next_line.h"

// Main instructions
void    parse_input(int ac, char **av, t_list **stack);
void    ft_swap(t_list **stack, char *cmd);
void	ft_push(t_list **from, t_list **target, char *cmd);
void	ft_rotate(t_list **stack, char *cmd);
void	ft_rrotate(t_list **stack, char *cmd);
void	ft_handle_sorting(t_list *a, t_list *b, int *sorted_ref);
int     *ft_lis_finder(t_list *stack);

void    ft_push_nonlis(t_list **a, t_list **b, int *lis);

// Longest Increasing Subsequence
t_list  *ft_dup_stack(t_list *stack);
void    ft_add_lis(t_list **res, t_list *subsequence);
int *ft_list_to_int(t_list *stack);
void    ft_push_subsequence(t_list **stack, int value);
t_list *ft_go_to_index(t_list *list, int index);

// clearing functions
void    ft_clear(void *content);

// struckt for min max of stack
typedef t_list s_stack {
    int *min;
    int *max;
} t_stack;

# endif
