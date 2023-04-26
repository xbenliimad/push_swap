#include "push_swap.h"

int ft_find_min(t_list *stack)
{
    int min;

    min = *(int *) stack->content;
    while (stack)
    {
        if (min > *(int *) stack->content)
            min = *(int *)stack->content;
        stack = stack->next;
    }
    return (min);
}

int ft_find_max(t_list *stack)
{
    int max;

    max = 0;
    while (stack)
    {
        if (max < *(int *) stack->content)
            max = *(int *)stack->content;
        stack = stack->next;
    }
    return (max);
}

int ft_calculate_moves(t_list **a, t_list **b)
{
    t_stack *a;
    t_stack *b;

    a->min = ft_find_min(a);
    a->max = ft_find_min(a);
    b->min = ft_find_min(b);
    b->max = ft_find_min(b);
}