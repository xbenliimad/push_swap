
#include "push_swap.h"

static int	ft_custom_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i++] - 48);
		if (result > LONG_MAX)
			return (-1);
		if (result < LONG_MIN)
			return (0);
	}
	ft_check_valid_input(str, i, result * sign);
	return (result * sign);
}

void	ft_check_duplicate(t_list **stack, long content)
{
	t_list	*head;

	head = *stack;
	if (content > INT_MAX || content < INT_MIN)
		ft_error();
	while (head)
	{
		if (*(int *)head->content == (int)content)
			ft_error();
		head = head->next;
	}
}

void	ft_check_sorted(t_list **stack)
{
	t_list	*v_stack;
	t_list	*head;

	if (!*stack)
		ft_error();
	v_stack = ft_dup_stack(*stack);
	head = v_stack;
	while (v_stack->next)
	{
		if (*(int *)v_stack->content > *(int *)v_stack->next->content)
		{
			ft_lstclear(&head, free);
			free(head);
			return ;
		}
		v_stack = v_stack->next;
	}
	exit(0);
}

static void	ft_handle_parsing(int ac, char **av, t_list **stack)
{
	t_list	*tmp_node;
	char	**split_numbers;
	int		*tmp_nbr;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		split_numbers = ft_split(av[i], ' ');
		j = 0;
		while (split_numbers[j])
		{
			tmp_nbr = malloc(sizeof(int));
			if (!tmp_nbr)
				return ;
			*tmp_nbr = ft_custom_atoi(split_numbers[j]);
			tmp_node = ft_lstnew(tmp_nbr);
			if (!tmp_node)
				return ;
			ft_check_duplicate(stack, *(int *)tmp_node->content);
			ft_lstadd_back(stack, tmp_node);
			j++;
		}
		ft_free_double_array(split_numbers);
	}
}

void	ft_parse_input(int ac, char **av, t_list **stack)
{
	if ((ft_strncmp(av[1], " ", 1) && !av[1][0]))
		ft_error();
	ft_handle_parsing(ac, av, stack);
	ft_check_sorted(stack);
}