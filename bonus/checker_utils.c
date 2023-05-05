/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:59:45 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/05 22:00:04 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_is_sorted(t_list *stack)
{
	t_list	*head;

	if (!stack)
		ft_error();
	head = stack;
	while (head->next)
	{
		if (*(int *)head->content > *(int *)head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}
