#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list *a;
	t_list *b;
	int *lis;

	a = NULL;
	b = NULL;
	parse_input(ac, av, &a);
	lis = ft_lis_finder(a);
	ft_push_nonlis(&a, &b, lis);
	free(lis);
	// system("leaks push_swap");
	return (0);
}