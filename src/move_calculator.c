#include "push_swap.h"

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
