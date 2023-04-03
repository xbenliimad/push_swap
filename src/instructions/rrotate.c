
#include "push_swap.h"

void	ft_rrotate(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}