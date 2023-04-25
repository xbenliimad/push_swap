
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
int		*ft_bubble_sort(t_list *stack);
void	ft_handle_sorting(t_list *a, t_list *b, int *sorted_ref);
int *ft_lis_finder(t_list *stack);

# endif
