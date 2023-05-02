
#include "push_swap.h"

static void	ft_check_valid_input(char *str, int i)
{
	if ((str[i] && !ft_isdigit(str[i])) || ((str[i - 1] == '-' || str[i - 1] == '+') && !str[i]))
	{
		ft_printf("Error\n");
		exit(0);
	}
}

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
	ft_check_valid_input(str, i);
	return (result * sign);
}


void	parse_input(int ac, char **av, t_list **stack)
{
	t_list *tmp_node;
	char **split_numbers;
	int *tmp_nbr;
	int i;
	int	j;

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
			ft_lstadd_back(stack, tmp_node);
			j++;
		}
		ft_free_double_array(split_numbers);
	}
}