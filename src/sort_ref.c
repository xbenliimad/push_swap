#include "push_swap.h"

static void    ft_swap_values(int *first, int *second)
{
    int tmp;

    tmp = *first;
    *first = *second;
    *second = tmp;
}

static int *ft_list_to_array(t_list *stack)
{
    t_list  *tmp_stack;
    int stack_size;
    int *array;
    int i;

    tmp_stack = stack;
    stack_size = ft_lstsize(stack);
    array = malloc(sizeof(int) * stack_size);
    if (!array)
        return (NULL);
    i = 0;
    while (i < stack_size)
    {
        array[i++] = *(int *) tmp_stack->content;
        tmp_stack = tmp_stack->next;
    }
    return (array);
}

int *ft_bubble_sort(t_list *stack)
{
    int *sorted_array;
    int i;
    int j;

    i = 0;
    sorted_array = ft_list_to_array(stack);
    while (i < ft_lstsize(stack))
    {
        j = i + 1;
        while (j < ft_lstsize(stack))
        {
            if (sorted_array[i] > sorted_array[j])
                ft_swap_values(&sorted_array[i], &sorted_array[j]);
            j++;
        }
        i++;
    }
    return (sorted_array);
}