#include "push_swap.h"

void	ft_get_info(t_list *a, t_stack_info *a_info)
{

	int counter;

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

int	ft_best_move_b(int b_size, int index)
{
	int	b_move;

	if (index <= b_size - index)
		b_move = index;
	else
		b_move = -(b_size - index);
	return (b_move);
}

int	ft_find_small_big(t_list *stack, int value)
{
	int	index;
	int	min[2];

	index = 0;
	min[1] = -1;
	while (stack)
	{
		if (value < *(int *) stack->content &&  min[1] == -1)
		{
			min[0] = *(int *) stack->content;
			min[1] = index;
		}
		else if (value < *(int *) stack->content && *(int *) stack->content < min[0])
		{
			min[0] = *(int *) stack->content;
			min[1] = index;
		}
		stack = stack->next;
		index++;
	}
	return min[1];
}

int ft_best_move_a(t_list *a, t_stack_info *a_info,int value)
{
    int     a_index;
    int     a_move;
	int 	find_max;

	find_max = 0;
	if (value > a_info->max || value < a_info->min)
		find_max = 1;
	a_index = 0;
	while (a)
    {
		if (find_max)
		{
			if (*(int *)a->content == a_info->max)
				break ;	
		}
		else
		{
			a_index = ft_find_small_big(a, value);
			break;
		}
		a = a->next;
		a_index++;
    }
	if (find_max)
	{
		if (a_index + 1 <= (a_info->len - (a_index + 1)))
			a_move = a_index + 1;
		else
			a_move = - (a_info->len - (a_index + 1));
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

int	ft_abs(int value)
{
	if (value == -2147483648)
		return (2147483647);
	if (value >= 0)
		return (value);
	return (-(value));
}

void	ft_move_calculator(t_list **a, t_list **b, t_stack_info *a_info, int best_move[2])
{
	int		b_index;
	int		b_len;
	int		tmp_move[2];
	t_list	*head;

	b_index = 1;
	b_len = ft_lstsize(*b);
	head = (*b)->next;
	best_move[0] = ft_best_move_a(*a, a_info, *(int *)(*b)->content);
	best_move[1] = 0;
	while (head)
	{
		tmp_move[0] = ft_best_move_a(*a, a_info, *(int *)head->content);
		tmp_move[1] = ft_best_move_b(b_len, b_index);
		if ((ft_abs(best_move[0]) + ft_abs(best_move[1])) > (ft_abs(tmp_move[0]) + ft_abs(tmp_move[1])))
		{
			best_move[0] = tmp_move[0];
			best_move[1] = tmp_move[1];
		}	
		head = head->next;
		b_index++;
	}
}

void	ft_handle_stack_a(t_list **a, t_list **b, int *best_move)
{
	while (*best_move > 0)
	{
		ft_handle_instructions(a, b, "ra");
		(*best_move)--;
	}
	while (*best_move < 0)
	{
		ft_handle_instructions(a, b, "rra");
		(*best_move)++;
	}
}

void	ft_handle_stack_b(t_list **a, t_list **b, int *best_move)
{
	while (*best_move > 0)
	{
		ft_handle_instructions(a, b, "rb");
		(*best_move)--;
	}
	while (*best_move < 0)
	{
		ft_handle_instructions(a, b, "rrb");
		(*best_move)++;
	}
}

void	ft_handle_sorting(t_list **a, t_list **b, int best_move[2])
{
	while (best_move[0] > 0 && best_move[1] > 0)
	{
		ft_handle_instructions(a, b, "rr");
		best_move[0]--;
		best_move[1]--;
	}
	while (best_move[0] < 0 && best_move[1] < 0)
	{
		ft_handle_instructions(a, b, "rrr");
		best_move[0]++;
		best_move[1]++;
	}
	ft_handle_stack_a(a, b, &best_move[0]);
	ft_handle_stack_b(a, b, &best_move[1]);
	ft_handle_instructions(a, b, "pa");
}

void	ft_print_stack(t_list *a, char *stack_name)
{
	while (a)
	{
		ft_printf("%s : %d\n",stack_name ,*(int *)(a->content));
		a = a->next;
	}
}

void	ft_handle_final_rotations(t_list **a, t_list **b, t_stack_info *stack_info)
{
	int	counter;

	if (stack_info->len - stack_info->min_index < stack_info->min_index)
		counter = - (stack_info->len - stack_info->min_index);
	else
		counter = stack_info->min_index;
	while(counter > 0)
	{
		ft_handle_instructions(a, b, "ra");
		counter--;
	}
	while(counter < 0)
	{
		ft_handle_instructions(a, b, "rra");
		counter++;
	}
}

void	ft_sort_stack(t_list **a, t_list **b)
{
	t_stack_info a_info;
	int			best_move[2];

	ft_get_info(*a, &a_info);
	while (*b)
	{
		ft_move_calculator(a, b, &a_info, best_move);
		ft_handle_sorting(a, b, best_move);
		ft_get_info(*a, &a_info);
	}
	ft_handle_final_rotations(a, b, &a_info);
}