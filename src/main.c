#include "push_swap.h"

int main(int ac, char **av)
{
    t_stacks    stacks;

    ft_bzero(&stacks, sizeof(t_stacks));
    parse_input(ac, av, &stacks);
    swap(&stacks.a);
    while(stacks.a)
    {
        printf("%d\n", *(int *) stacks.a->content);
        stacks.a = stacks.a->next; 
    }
    return (0);
}cd 