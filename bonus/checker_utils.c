#include "push_swap.h"

int	ft_is_sorted(t_list *stack)
{
	t_list	*v_stack;
	t_list	*head;

	if (!stack)
		ft_error();
	v_stack = ft_dup_stack(stack);
	head = v_stack;
	while (v_stack->next)
	{
		if (*(int *)v_stack->content > *(int *)v_stack->next->content)
		{
			ft_lstclear(&head, free);
			free(head);
			return 0;
		}
		v_stack = v_stack->next;
	}
	exit(1);
}