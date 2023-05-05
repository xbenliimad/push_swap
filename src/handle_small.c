/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:47:05 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/05 21:47:19 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_handle_small(t_list **a, t_list **b)
{
	int	*arr;

	arr = ft_list_to_int(*a);
	if (arr[1] > arr[2] && arr[2] < arr[3] && arr[3] > arr[1])
		ft_handle_instructions(a, b, "sa");
	else if (arr[1] > arr[2] && arr[2] < arr[3] && arr[3] < arr[1])
		ft_handle_instructions(a, b, "ra");
	else if (arr[1] < arr[2] && arr[2] > arr[3] && arr[3] < arr[1])
		ft_handle_instructions(a, b, "rra");
	else if (arr[1] > arr[2] && arr[2] > arr[3] && arr[3] < arr[1])
	{
		ft_handle_instructions(a, b, "sa");
		ft_handle_instructions(a, b, "rra");
	}
	else if (arr[1] < arr[2] && arr[2] > arr[3] && arr[3] > arr[1])
	{
		ft_handle_instructions(a, b, "sa");
		ft_handle_instructions(a, b, "ra");
	}
	free(arr);
}
