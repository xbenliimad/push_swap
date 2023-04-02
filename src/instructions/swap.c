#include "push_swap.h"

void    swap(t_list **stack)
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
}