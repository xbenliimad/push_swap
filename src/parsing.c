
#include "push_swap.h"

void    parse_input(int ac, char **av, t_list **stack)
{
    t_list      *tmp_node;
    int         *tmp_nbr;
    int         i;

    i = 0;
    while (++i < ac)
    {
        tmp_nbr = malloc(sizeof(int));
        if (!tmp_nbr)
            return ;
        *tmp_nbr = ft_atoi(av[i]);
        tmp_node = ft_lstnew(tmp_nbr);
        if (!tmp_node)
            return ;
        ft_lstadd_back(stack, tmp_node);
    }
}