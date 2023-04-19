#include "push_swap.h"

int main(int ac, char **av)
{
    t_list  *a;
    t_list  *b;
    int  *sorted_ref;

    a = NULL;
    b = NULL;
    parse_input(ac, av, &a);
    sorted_ref = ft_bubble_sort(a);
    ft_handle_sorting(a, b, sorted_ref);
    // system("leaks push_swap");
    return (0);
}