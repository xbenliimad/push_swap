#include "push_swap.h"

static void	ft_handle_more_instructions_bonus(t_list **a, t_list **b, char *cmd)
{
	int	cmd_len;

	cmd_len = ft_strlen(cmd);
	if (cmd_len == 2 && !ft_strncmp(cmd, "rr", 2))
	{
		ft_rotate(a, NULL);
		ft_rotate(b, cmd);
	}
	else if (!ft_strncmp(cmd, "rra", 3))
		ft_rrotate(a, cmd);
	else if (!ft_strncmp(cmd, "rrb", 3))
		ft_rrotate(b, cmd);
	else if (!ft_strncmp(cmd, "rrr", 3))
	{
		ft_rrotate(a, NULL);
		ft_rrotate(b, cmd);
	}
	else
		ft_error();
}

void	ft_handle_instructions_bonus(t_list **a, t_list **b, char *cmd)
{
	if (!ft_strncmp(cmd, "sa", 2))
		ft_swap(a, cmd);
	else if (!ft_strncmp(cmd, "sb", 2))
		ft_swap(b, cmd);
	else if (!ft_strncmp(cmd, "ss", 2))
	{
		ft_swap(a, NULL);
		ft_swap(b, cmd);
	}
	else if (!ft_strncmp(cmd, "pa", 2))
		ft_push(b, a, cmd);
	else if (!ft_strncmp(cmd, "pb", 2))
		ft_push(a, b, cmd);
	else if (!ft_strncmp(cmd, "ra", 2))
		ft_rotate(a, cmd);
	else if (!ft_strncmp(cmd, "rb", 2))
		ft_rotate(b, cmd);
	else
		ft_handle_more_instructions_bonus(a, b, cmd);
}