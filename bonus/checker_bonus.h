/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:02:07 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/05 22:02:08 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

// Main instructions
void	ft_parse_input_bonus(int ac, char **av, t_list **stack);
void	ft_swap_bonus(t_list **stack);
void	ft_push_bonus(t_list **src, t_list **dest);
void	ft_rotate_bonus(t_list **stack);
void	ft_rrotate_bonus(t_list **stack);

// Handle instructions
void	ft_handle_instructions_bonus(t_list **a, t_list **b, char *cmd);

// utils fro Checker
int		ft_is_sorted(t_list *stack);

#endif
