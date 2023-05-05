#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

#include "push_swap.h"

// Main instructions
void    ft_parse_input_bonus(int ac, char **av, t_list **stack);
void    ft_swap_bonus(t_list **stack, char *cmd);
void	ft_push_bonus(t_list **from, t_list **target, char *cmd);
void	ft_rotate_bonus(t_list **stack, char *cmd);
void	ft_rrotate_bonus(t_list **stack, char *cmd);

// Handle instructions
void	ft_handle_instructions_bonus(t_list **a, t_list **b, char *cmd);

// utils fro Checker
int	ft_is_sorted(t_list *stack);



# endif
