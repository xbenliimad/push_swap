#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list *a;
	t_list *b;
	int *lis;
	int i;

	i = 1;
	a = NULL;
	b = NULL;
	parse_input(ac, av, &a);
	lis = ft_lis_finder(a);
	// while (i <= lis[0])
	// 	printf("lis -> %d\n", lis[i++]);
	ft_push_nonlis(&a, &b, lis);
	free(lis);
	ft_sort_stack(&a, &b);

	// while (a)
	// {
	// 	ft_printf("a : %d\n", *(int *)(a->content));
	// 	a = a->next;
	// }
	// while (b)
	// {
	// 	ft_printf("b : %d\n", *(int *)(b->content));
	// 	b = b->next;
	// }
	// system("leaks push_swap");
	return (0);
}