/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:43:49 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/02 22:59:21 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
