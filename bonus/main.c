#include "checker_bonus.h"

int main(int ac, char **av)
{
    t_list *a;
	t_list *b;
    char *cmd;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		ft_parse_input(ac, av, &a);
		cmd = get_next_line(1);
        while (cmd)
        {
            ft_handle_instructions_bonus(&a, &b, cmd);
            cmd = get_next_line(1);
        }
        if (ft_is_sorted(a))
            ft_printf("OK\n");
        else
            ft_printf("KO\n");
		ft_lstclear(&a, free);
	}
    return (0);
}
