/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:45:17 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/05 21:43:47 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_dup_stack(t_list *stack)
{
	t_list	*head;
	t_list	*tmp_node;
	t_list	*result;
	int		*tmp_nbr;

	head = stack;
	result = NULL;
	while (head)
	{
		tmp_nbr = malloc(sizeof(int));
		if (!tmp_nbr)
			return (NULL);
		*tmp_nbr = *(int *)head->content;
		tmp_node = ft_lstnew(tmp_nbr);
		if (!tmp_node)
			return (NULL);
		ft_lstadd_back(&result, tmp_node);
		head = head->next;
	}
	return (result);
}

void	ft_add_lis(t_list **res, t_list *subsequence)
{
	t_list	*lis_container;

	lis_container = ft_lstnew(subsequence);
	if (!lis_container)
		return ;
	ft_lstadd_back(res, lis_container);
}

int	*ft_list_to_int(t_list *stack)
{
	int	*n_stack;
	int	size;
	int	i;

	size = ft_lstsize(stack);
	n_stack = malloc(sizeof(int) * (size + 1));
	if (!n_stack)
		return (NULL);
	n_stack[0] = size;
	i = 1;
	while (stack)
	{
		n_stack[i] = *(int *)stack->content;
		i++;
		stack = stack->next;
	}
	return (n_stack);
}

void	ft_push_subsequence(t_list **stack, int value)
{
	t_list	*tmp_list;
	int		*tmp_value;

	tmp_value = malloc(sizeof(int));
	if (!tmp_value)
		return ;
	*tmp_value = value;
	tmp_list = ft_lstnew(tmp_value);
	if (!tmp_list)
		return ;
	ft_lstadd_back(stack, tmp_list);
}

t_list	*ft_go_to_index(t_list *list, int index)
{
	int	i;

	i = 1;
	while (i < index)
	{
		list = list->next;
		i++;
	}
	return (list);
}
