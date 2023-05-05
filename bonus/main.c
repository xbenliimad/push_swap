/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:01:30 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/05 22:01:31 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	*cmd;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		ft_parse_input(ac, av, &a);
		cmd = get_next_line(0);
		while (cmd)
		{
			ft_handle_instructions_bonus(&a, &b, cmd);
			free(cmd);
			cmd = get_next_line(0);
		}
		if (!b && ft_is_sorted(a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		ft_lstclear(&a, free);
	}
	return (0);
}
