#include "push_swap.h"

t_list  *ft_dup_stack(t_list *stack)
{
	t_list      *head;
	t_list      *tmp_node;
	t_list      *result;
	int         *tmp_nbr;

	head = stack;
	result = NULL;
	while (head)
	{
		tmp_nbr = malloc(sizeof(int));
		if (!tmp_nbr)
			return (NULL);
		*tmp_nbr = *(int *)head->content;
		tmp_node = ft_lstnew(tmp_nbr);
		if (!tmp_node)
			return (NULL);
		ft_lstadd_back(&result, tmp_node);
		head = head->next;
	}
	return (result);
}

void    ft_add_lis(t_list **res, t_list *subsequence)
{
	t_list  *lis_container;

	lis_container = ft_lstnew(subsequence);
	if(!lis_container)
		return ;
	ft_lstadd_back(res, lis_container);
}

void    ft_push_subsequence(t_list **stack, int value)
{
	t_list  *tmp_list;
	int     *tmp_value;

	tmp_value = malloc(sizeof(int));
	if (!tmp_value)
		return ; 
	*tmp_value = value;
	tmp_list = ft_lstnew(tmp_value);
	if(!tmp_list)
		return ;
	ft_lstadd_back(stack, tmp_list);
}

// void    debug(t_list *res)
// {
//     t_list *x ;
//     while (res)
//     {
//         x = res->content;
//         printf("new subsequence \n");
//         while(x)
//         {
//             printf("elements %d \n",*(int *) x->content);
//             x = x->next;
//         }
//         res = res->next;
//     }
// }

t_list *ft_go_to_index(t_list *list, int index)
{
	int i;

	i = 1;
	while(i < index)
	{
		list = list->next;
		i++;
	}
  
	return list;
}

void    handle_lis_middle_case(t_list *to_modify, t_list *prev, int value)
{
	while (prev)
	{
		*(int *)to_modify->content = *(int *)prev->content;
		to_modify = to_modify->next;
		prev = prev->next;
	}
	*(int *)to_modify->content = value;
}

void    ft_handle_lis(t_list **stack, int value)
{
	t_list *tmp_stack;
	t_list *duped;
	t_list *tmp_last;
	int stack_size;

	stack_size = ft_lstsize(*stack);
	while (stack_size > 0)
	{
		tmp_stack = *stack;
		tmp_stack = ft_go_to_index(tmp_stack, stack_size);
		tmp_last = ft_lstlast(tmp_stack->content);
		if (*(int *)tmp_last->content < value) 
		{
			if (stack_size == ft_lstsize(*stack) )
			{
				duped = ft_dup_stack(tmp_stack->content);
				ft_push_subsequence(&duped, value);
				ft_add_lis(stack, duped);
			}   
			else
			   handle_lis_middle_case(ft_go_to_index(*stack, stack_size + 1)->content, tmp_stack->content, value);
			break;
		}
		else if ((stack_size == 1 && *(int *)tmp_last->content > value))
		{
			*(int *)tmp_last->content = value;
			break;
		}
		stack_size--;
	}
}

int *ft_list_to_int(t_list *stack)
{
	int *n_stack;
	int size;
	int i;

	size = ft_lstsize(stack);
	n_stack = malloc(sizeof(int) * (size + 1));
	if (!n_stack)
		return (NULL);
	n_stack[0] = size;
	i = 1;
	while (stack)
	{
		n_stack[i] = *(int *) stack->content;
		i++;
		stack = stack->next;
	}
	return (n_stack);
}

void    ft_clear(void *content)
{
	t_list *ptr;

	ptr = content;
	ft_lstclear(&ptr, free);
}


int *ft_find_lis(t_list *stack)
{
	t_list *res;
	int     tmp;
	t_list  *new_lst;
	int     *lis;

	new_lst = NULL;
	ft_push_subsequence(&new_lst, *((int *)stack->content));
	if (!new_lst)
		return NULL;
	res = NULL;
	ft_add_lis(&res, new_lst);
	stack = stack->next;
	while (stack)
	{
		tmp = *(int *)stack->content;
		ft_handle_lis(&res, tmp);
		// debug(res);
		stack = stack->next;
	}
	lis = ft_list_to_int(ft_lstlast(res)->content);
	ft_lstclear(&res, ft_clear);
	return (lis);
}

int *ft_lis_finder(t_list *stack)
{
	t_list  *tmp_stack;
	int *lis[2];
	int	*tmp;
	int stack_size;
	int longest_len;

	stack_size = ft_lstsize(stack);
	tmp_stack = ft_dup_stack(stack);
	lis[0] = ft_find_lis(tmp_stack);
	longest_len = lis[0][0];
	ft_rotate(&tmp_stack, NULL);
	while (--stack_size)
	{
		lis[1] = ft_find_lis(tmp_stack);
		ft_rotate(&tmp_stack, NULL);
		if (lis[1][0] > lis[0][0])
		{
			tmp = lis[0];
			lis[0] = lis[1];
			lis[1] = tmp;
		}
		free(lis[1]);
	}
	ft_lstclear(&tmp_stack, free);
	return (lis[0]);
}