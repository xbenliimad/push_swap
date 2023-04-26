#include "push_swap.h"

void	ft_clear(void *content)
{
	t_list *ptr;

	ptr = content;
	ft_lstclear(&ptr, free);
}
