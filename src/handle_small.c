#include "push_swap.h"

void    ft_handle_small(t_list **a, t_list **b)
{
    int     *arr;
    
    arr = ft_list_to_int(*a);
    if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[1])
        ft_handle_instructions(a, b, "sa");
    else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
        ft_handle_instructions(a, b, "ra");
    else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
        ft_handle_instructions(a, b, "rra");
    else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
    {
        ft_handle_instructions(a, b, "sa");
        ft_handle_instructions(a, b, "rra");
    }
    else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
    {
        ft_handle_instructions(a, b, "sa");
        ft_handle_instructions(a, b, "ra");
    }
    free(arr);
}