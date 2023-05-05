/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:47:33 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/05 21:51:53 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_belongs_to_lis(int value, int *lis)
{
	int	i;

	i = 1;
	while (i <= lis[0])
	{
		if (value == lis[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_push_nonlis(t_list **a, t_list **b, int *lis)
{
	int	i;
	int	stack_size;
	int	middle_lis;

	middle_lis = lis[lis[0] / 2];
	stack_size = ft_lstsize(*a);
	i = 0;
	while (i < stack_size - lis[0])
	{
		if (!ft_belongs_to_lis(*(int *)(*a)->content, lis))
		{
			ft_push(a, b, "pb");
			if (*(int *)(*b)->content < middle_lis)
				ft_rotate(b, "rb");
			i++;
		}
		else
			ft_rotate(a, "ra");
	}
}

void	ft_sort_stack(t_list **a, t_list **b)
{
	t_stack_info	a_info;
	int				best_move[2];

	ft_get_info(*a, &a_info);
	while (*b)
	{
		ft_move_calculator(a, b, &a_info, best_move);
		ft_handle_sorting(a, b, best_move);
		ft_get_info(*a, &a_info);
	}
	ft_handle_final_rotations(a, b, &a_info);
}
