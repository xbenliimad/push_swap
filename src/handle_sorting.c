#include "push_swap.h"

int ft_check_upperchunk(int *stack, int needle, int size)
{
    int i;

    i = 0;
    while (i < size / 2)
    {
        if (stack[i] == needle)
            return (1);
        i++;
    }
    return (0);
}

void    ft_handle_sorting(t_list *a, t_list *b, int *sorted_ref)
{
    t_list  *head_a;

    b = NULL;
    sorted_ref = NULL;
    head_a = a;
    while (head_a)
    {
        // if (sorted_ref[0] <= *(int *)head_a->content && sorted_ref[ft_lstsize(a) - 1] > *(int *)head_a->content)
        // {
        //     ft_push(&a, &b, "pb");
        //     if (!ft_check_upperchunk(sorted_ref, *(int *)b->content, ft_lstsize(a) - 1))
        //         ft_rotate(&b, "rb");
        // }
        // else
        //     ft_rotate(&a, "ra");
        printf("Content : %d\n", *(int *)head_a->content);
        head_a = head_a->next;
    }
}