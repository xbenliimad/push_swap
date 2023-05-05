/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:58:07 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/05 23:35:20 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		result = (result * 10) + (str[i++] - 48);
	ft_check_valid_input(str, i, result * sign);
	return (result * sign);
}

void	ft_check_duplicate(t_list **stack, int content)
{
	t_list	*head;

	head = *stack;
	while (head)
	{
		if (*(int *)head->content == content)
			ft_error();
		head = head->next;
	}
}

static int	ft_handle_parsing(t_list **stack, char **split_numbers)
{
	int		i;
	int		*tmp_nbr;
	t_list	*tmp_node;

	i = 0;
	while (split_numbers[i])
	{
		tmp_nbr = malloc(sizeof(int));
		if (!tmp_nbr)
			return (0);
		*tmp_nbr = ft_custom_atoi(split_numbers[i]);
		tmp_node = ft_lstnew(tmp_nbr);
		if (!tmp_node)
			return (0);
		ft_check_duplicate(stack, *(int *)tmp_node->content);
		ft_lstadd_back(stack, tmp_node);
		i++;
	}
	return (1);
}

void	ft_parse_input(int ac, char **av, t_list **stack)
{
	char	**split_numbers;
	int		i;

	i = 0;
	while (++i < ac)
	{
		split_numbers = ft_split(av[i], ' ');
		if (!*split_numbers)
			ft_error();
		if (!ft_handle_parsing(stack, split_numbers))
			return ;
		ft_free_double_array(split_numbers);
	}
}
