#include "push_swap.h"

int	ft_belongs_to_lis(int value, int *lis)
{
	int	i;

	i = 1;
	while (i <= lis[0])
	{
		if (value == lis[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_push_nonlis(t_list **a, t_list **b, int *lis)
{
	int i;
	int stack_size;
	int middle_lis;

	middle_lis = lis[lis[0] / 2];
	stack_size = ft_lstsize(*a);
	i = 0;
	while (i < stack_size - lis[0])
	{
		if (!ft_belongs_to_lis(*(int *)(*a)->content, lis))
		{
			ft_push(a, b, "pb");
			if (*(int *)(*b)->content < middle_lis)
				ft_rotate(b, "rb");
			i++;
		}
		else
			ft_rotate(a, "ra");
	}
}