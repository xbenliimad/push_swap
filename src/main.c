#include "push_swap.h"

int main(int ac, char **av)
{
    t_stacks    stacks;
    int     i;

    ft_bzero(&stacks, sizeof(t_stacks));
    parse_input(ac, av, &stacks);
    ft_rotate(&stacks.a);
    ft_printf("Stack a:\n");
    i = 0;
    while(stacks.a)
    {
        printf("%d\n", *(int *) stacks.a->content);
        stacks.a = stacks.a->next; 
    }
    // system("leaks push_swap");
    return (0);
}