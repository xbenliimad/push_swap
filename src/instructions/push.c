
#include "push_swap.h"

void	ft_push(t_list **src, t_list **dest)
{
	t_list *tmp;

	if (!src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}
