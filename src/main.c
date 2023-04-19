#include "push_swap.h"

int main(int ac, char **av)
{
    t_list  *a;
    t_list  *b;
    int  *sorted;
    int     i;

    a = NULL;
    parse_input(ac, av, &a);
    sorted = ft_bubble_sort(a);
    ft_handle_sorting(a, b, sorted);
    // system("leaks push_swap");
    return (0);
}