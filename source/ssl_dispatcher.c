#include "ssl.h"

void		ssl_cmd_check(char **argv, t_mod mod)
{
	int i;

	i = -1;
	while (++i < SSL_CMD_SIZE)
		if (!ft_strcmp(argv[0], g_string_cmd[i]))
		{
			g_func_cmd[i]();
			break ;
		}
	if (i == SSL_CMD_SIZE)
	{
		if (mod == BASE_MOD)
			ssl_print_usage_exit(argv[0]);
		else if (mod == INTERACTIVE_MOD)
			ssl_print_error_message(argv[0]);
	}
}
