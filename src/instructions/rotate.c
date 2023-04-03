
#include "push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	last = ft_lstlast(*stack);
	last->next = tmp;
}