#include "ssl.h"

static void	ssl_print_commands(void)
{
	ft_putstr("\nStandard commands:\n");
	ft_putstr("\nMessage Digest commands:\n");
	ft_putstr("md5\nsha256\nsha512\n");
	ft_putstr("\nCipher commands:\n\n");
}

void		ssl_print_error_message(const char *cmd)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", cmd);
	ssl_print_commands();
}

void		ssl_print_usage_exit(const char *cmd)
{
	ft_putstr("usage: ft_ssl command [command opts] [command args]\n");
	ssl_print_error_message(cmd);
	exit (-1);
}
