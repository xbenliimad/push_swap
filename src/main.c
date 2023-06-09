/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:48:23 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/05 23:32:54 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		*lis;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		ft_parse_input(ac, av, &a);
		if (ft_lstsize(a) == 3)
			ft_handle_small(&a, &b);
		else
		{
			lis = ft_lis_finder(a);
			ft_push_nonlis(&a, &b, lis);
			free(lis);
			ft_sort_stack(&a, &b);
		}
		ft_lstclear(&a, free);
	}
	return (0);
}
