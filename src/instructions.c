#include "push_swap.h"

void	ft_push(t_list **src, t_list **dest, char *cmd)
{
	t_list *tmp;

	if (!src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	if(cmd)
		ft_printf("%s\n", cmd);
}

void	ft_rotate(t_list **stack, char *cmd)
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
	if(cmd)
		ft_printf("%s\n", cmd);
}

void	ft_rrotate(t_list **stack, char *cmd)
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
	if(cmd)
		ft_printf("%s\n", cmd);
}

void    ft_swap(t_list **stack, char *cmd)
{
    t_list *second_node;
    t_list *first_node;

    first_node = *stack;
    if (!first_node->next)
        return ;
    second_node = first_node->next;
    first_node->next = second_node->next;
    second_node->next = first_node;
    (*stack) = second_node;
	if(cmd)
		ft_printf("%s\n", cmd);
}
