/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:00:16 by ibenli            #+#    #+#             */
/*   Updated: 2023/05/05 22:01:07 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_handle_more_instructions_bonus(t_list **a, t_list **b, char *cmd)
{
	int	cmd_len;

	cmd_len = ft_strlen(cmd);
	if (cmd_len == 2 && !ft_strncmp(cmd, "rr\n", 3))
	{
		ft_rotate_bonus(a);
		ft_rotate_bonus(b);
	}
	else if (!ft_strncmp(cmd, "rra\n", 4))
		ft_rrotate_bonus(a);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		ft_rrotate_bonus(b);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
	{
		ft_rrotate_bonus(a);
		ft_rrotate_bonus(b);
	}
	else
		ft_error();
}

void	ft_handle_instructions_bonus(t_list **a, t_list **b, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
		ft_swap_bonus(a);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		ft_swap_bonus(b);
	else if (!ft_strncmp(cmd, "ss\n", 3))
	{
		ft_swap_bonus(a);
		ft_swap_bonus(b);
	}
	else if (!ft_strncmp(cmd, "pa\n", 3))
		ft_push_bonus(b, a);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		ft_push_bonus(a, b);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		ft_rotate_bonus(a);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		ft_rotate_bonus(b);
	else
		ft_handle_more_instructions_bonus(a, b, cmd);
}
