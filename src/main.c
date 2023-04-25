#include "push_swap.h"

int main(int ac, char **av)
{
    t_list  *a;
    t_list  *b;
    int     *lis;
    int     i = 0;

    a = NULL;
    b = NULL;
    parse_input(ac, av, &a);
    lis = ft_lis_finder(a);
    
    system("leaks push_swap");
    return (0);
}