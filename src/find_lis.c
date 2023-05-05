/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:46:36 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/05 21:46:11 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_lis_middle_case(t_list *to_modify, t_list *prev, int value)
{
	while (prev)
	{
		*(int *)to_modify->content = *(int *)prev->content;
		to_modify = to_modify->next;
		prev = prev->next;
	}
	*(int *)to_modify->content = value;
}

void	handle_middle_max_case(t_list **stack, t_list *tmp_stack,
		int stack_info[2], int value)
{
	t_list	*duped;

	if (stack_info[0] == stack_info[1])
	{
		duped = ft_dup_stack(tmp_stack->content);
		ft_push_subsequence(&duped, value);
		ft_add_lis(stack, duped);
	}
	else
		handle_lis_middle_case(ft_go_to_index(*stack, stack_info[0]
				+ 1)->content, tmp_stack->content, value);
}

void	ft_handle_lis(t_list **stack, int value)
{
	t_list	*tmp_stack;
	int		stack_info[2];
	t_list	*tmp_last;

	stack_info[0] = ft_lstsize(*stack);
	stack_info[1] = stack_info[0];
	while (stack_info[0] > 0)
	{
		tmp_stack = *stack;
		tmp_stack = ft_go_to_index(tmp_stack, stack_info[0]);
		tmp_last = ft_lstlast(tmp_stack->content);
		if (*(int *)tmp_last->content < value)
		{
			handle_middle_max_case(stack, tmp_stack, stack_info, value);
			break ;
		}
		else if ((stack_info[0] == 1 && *(int *)tmp_last->content > value))
		{
			*(int *)tmp_last->content = value;
			break ;
		}
		stack_info[0]--;
	}
}

int	*ft_find_lis(t_list *stack)
{
	t_list	*res;
	int		tmp;
	t_list	*new_lst;
	int		*lis;

	new_lst = NULL;
	ft_push_subsequence(&new_lst, *((int *)stack->content));
	if (!new_lst)
		return (NULL);
	res = NULL;
	ft_add_lis(&res, new_lst);
	stack = stack->next;
	while (stack)
	{
		tmp = *(int *)stack->content;
		ft_handle_lis(&res, tmp);
		stack = stack->next;
	}
	lis = ft_list_to_int(ft_lstlast(res)->content);
	ft_lstclear(&res, ft_clear);
	return (lis);
}

int	*ft_lis_finder(t_list *stack)
{
	t_list	*tmp_stack;
	int		*lis[2];
	int		*tmp;
	int		stack_size;

	stack_size = ft_lstsize(stack);
	tmp_stack = ft_dup_stack(stack);
	lis[0] = ft_find_lis(tmp_stack);
	ft_rotate(&tmp_stack, NULL);
	while (--stack_size)
	{
		lis[1] = ft_find_lis(tmp_stack);
		ft_rotate(&tmp_stack, NULL);
		if (lis[1][0] > lis[0][0])
		{
			tmp = lis[0];
			lis[0] = lis[1];
			lis[1] = tmp;
		}
		free(lis[1]);
	}
	ft_lstclear(&tmp_stack, free);
	return (lis[0]);
}
