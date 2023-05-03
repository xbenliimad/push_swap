/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:43:49 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/03 19:16:05 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	printf("Error\n");
	exit(0);
}

void	ft_clear(void *content)
{
	t_list	*ptr;

	ptr = content;
	ft_lstclear(&ptr, free);
}

int	ft_abs(int value)
{
	if (value == -2147483648)
		return (2147483647);
	if (value >= 0)
		return (value);
	return (-(value));
}

void	ft_free_double_array(char **ptr)
{
	int	i;
	
	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void	ft_check_valid_input(char *str, int index)
{
	int i;

	i = index;
	if ((str[i] && !ft_isdigit(str[i])) || (((str[i - 1] == '-' || str[i - 1] == '+') && !str[i])))
		ft_error();
}
