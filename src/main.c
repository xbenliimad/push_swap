#include "push_swap.h"

int main(int ac, char **av)
{
    t_list  *a;
    t_list  *b;

    a = NULL;
    b = NULL;
    parse_input(ac, av, &a);
    ft_lis_finder(a);
    // system("leaks push_swap");
    return (0);
}