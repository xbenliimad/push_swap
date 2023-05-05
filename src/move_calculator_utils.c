/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculator_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:49:07 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/05 21:50:35 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_info(t_list *a, t_stack_info *a_info)
{
	int	counter;

	counter = 0;
	a_info->len = ft_lstsize(a);
	a_info->min = *(int *)a->content;
	a_info->max = a_info->min;
	a_info->min_index = 0;
	while (a)
	{
		if (*(int *)a->content > a_info->max)
			a_info->max = *(int *)a->content;
		else if (*(int *)a->content < a_info->min)
		{
			a_info->min = *(int *)a->content;
			a_info->min_index = counter;
		}
		a = a->next;
		counter++;
	}
}

static int	ft_find_small_big(t_list *stack, int value)
{
	int	index;
	int	min[2];

	index = 0;
	min[1] = -1;
	while (stack)
	{
		if (value < *(int *)stack->content && min[1] == -1)
		{
			min[0] = *(int *)stack->content;
			min[1] = index;
		}
		else if (value < *(int *)stack->content
			&& *(int *)stack->content < min[0])
		{
			min[0] = *(int *)stack->content;
			min[1] = index;
		}
		stack = stack->next;
		index++;
	}
	return (min[1]);
}

static int	find_max(t_list *a, t_stack_info *a_info, int value, int *a_index)
{
	int	find_max;

	find_max = 0;
	if (value > a_info->max || value < a_info->min)
		find_max = 1;
	*a_index = 0;
	while (a)
	{
		if (find_max)
		{
			if (*(int *)a->content == a_info->max)
				break ;
		}
		else
		{
			*a_index = ft_find_small_big(a, value);
			break ;
		}
		a = a->next;
		(*a_index)++;
	}
	return (find_max);
}

int	ft_best_move_b(int b_size, int index)
{
	int	b_move;

	if (index <= b_size - index)
		b_move = index;
	else
		b_move = -(b_size - index);
	return (b_move);
}

int	ft_best_move_a(t_list *a, t_stack_info *a_info, int value)
{
	int	a_index;
	int	a_move;

	if (find_max(a, a_info, value, &a_index))
	{
		if (a_index + 1 <= (a_info->len - (a_index + 1)))
			a_move = a_index + 1;
		else
			a_move = -(a_info->len - (a_index + 1));
	}
	else
	{
		if (a_index <= a_info->len - a_index)
			a_move = a_index;
		else
			a_move = -(a_info->len - a_index);
	}
	return (a_move);
}
