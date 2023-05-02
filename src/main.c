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
	if (ac >= 2)
	{
		parse_input(ac, av, &a);
		lis = ft_lis_finder(a);
		ft_push_nonlis(&a, &b, lis);
		free(lis);
		ft_sort_stack(&a, &b);
		while (a)
		{
			ft_printf("a : %d\n", *(int *) a->content);
			a = a->next;
		}
		ft_lstclear(&a, free);
	}
	// system("leaks push_swap");
	return (0);
}