/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:02:56 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/05 22:02:57 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../utils/ft_printf/ft_printf.h"
# include "../utils/get-next-line/get_next_line.h"
# include "../utils/libft/libft.h"

// struckt for min max of stack
typedef struct s_stack_info
{
	int	min;
	int	max;
	int	len;
	int	min_index;
}		t_stack_info;

// Main instructions
void	ft_parse_input(int ac, char **av, t_list **stack);
void	ft_swap(t_list **stack, char *cmd);
void	ft_push(t_list **src, t_list **dest, char *cmd);
void	ft_rotate(t_list **stack, char *cmd);
void	ft_rrotate(t_list **stack, char *cmd);
int		*ft_lis_finder(t_list *stack);
void	ft_handle_small(t_list **a, t_list **b);
void	ft_push_nonlis(t_list **a, t_list **b, int *lis);

// Longest Increasing Subsequence
t_list	*ft_dup_stack(t_list *stack);
void	ft_add_lis(t_list **res, t_list *subsequence);
int		*ft_list_to_int(t_list *stack);
void	ft_push_subsequence(t_list **stack, int value);
t_list	*ft_go_to_index(t_list *list, int index);

// Handling sorting
void	ft_handle_instructions(t_list **a, t_list **b, char *cmd);
void	ft_sort_stack(t_list **a, t_list **b);
void	ft_handle_sorting(t_list **a, t_list **b, int best_move[2]);
void	ft_handle_final_rotations(t_list **a, t_list **b,
			t_stack_info *stack_info);

// Move calculator
int		ft_best_move_a(t_list *a, t_stack_info *a_info, int value);
int		ft_best_move_b(int b_size, int index);
void	ft_get_info(t_list *a, t_stack_info *a_info);
void	ft_move_calculator(t_list **a, t_list **b, t_stack_info *a_info,
			int best_move[2]);

// Utils
int		ft_abs(int value);
void	ft_clear(void *content);
void	ft_free_double_array(char **ptr);
void	ft_error(void);
void	ft_check_valid_input(char *str, int index, long result);

#endif
