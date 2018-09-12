/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 08:19:42 by prippa            #+#    #+#             */
/*   Updated: 2018/09/01 08:19:43 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static void	ssl_validate_file(void)
{
	int fd;

	if (!g_ssl.f[SSL_FLAG_P] && !g_ssl.f[SSL_FLAG_S]
		&& !g_ssl.argv[g_ssl.i])
		ssl_read_from_stdin();
	else
	{
		while (g_ssl.argv[g_ssl.i])
		{
			if ((fd = open(g_ssl.argv[g_ssl.i], O_RDONLY)) == -1
				|| read(fd, NULL, 0) == -1)
			{
				perror(ssl_error_str(g_ssl.argv[g_ssl.i]));
				free(g_ssl.tmp);
				g_ssl.err_flag = 1;
			}
			else
				ssl_read_from_file(fd, g_ssl.argv[g_ssl.i]);
			++g_ssl.i;
		}
	}
}

static int	ssl_check_flags(const char *f)
{
	int i;

	while (*f)
	{
		i = -1;
		while (++i < SSL_FLAG_SIZE)
			if (g_hash_flags[i] == *f)
			{
				if (*f == 's')
				{
					g_ssl.tmp = (char *)f;
					if (!(g_hash_flags_func[i]()))
						return (1);
					return (0);
				}
				g_hash_flags_func[i]();
				break ;
			}
		if (i == SSL_FLAG_SIZE)
			return (1);
		++f;
	}
	return (0);
}

static int	ssl_parse_flags(void)
{
	while (g_ssl.argv[g_ssl.i] && *g_ssl.argv[g_ssl.i] == '-')
	{
		if (!*(g_ssl.argv[g_ssl.i] + 1))
			return (1);
		if ((ssl_check_flags(g_ssl.argv[g_ssl.i] + 1)))
			return (1);
		++g_ssl.i;
	}
	return (0);
}

static int	ssl_check_cmd(void)
{
	int		i;
	char	*cmd;

	if (!(cmd = ft_strdup(*g_ssl.argv)))
		ssl_fatal_error(MALLOC_ERR);
	ft_str_to_lower(&cmd);
	i = -1;
	while (++i < SSL_CMD_SIZE)
		if (!ft_strcmp(cmd, g_string_hash[i]))
		{
			g_ssl.type = i;
			++g_ssl.i;
			free(cmd);
			return (1);
		}
	free(cmd);
	return (0);
}

void		ssl_parser(t_mod mod)
{
	if (ssl_check_cmd())
	{
		if (ssl_parse_flags())
		{
			ssl_print_hash_flags_usage(g_ssl.argv[g_ssl.i]);
			g_ssl.err_flag = 1;
		}
		else
			ssl_validate_file();
		if (g_ssl.err_flag && mod == INTERACTIVE_MOD)
			ft_printf("error in %s\n", g_string_hash[g_ssl.type]);
	}
	else
	{
		if (mod == BASE_MOD)
			ssl_print_usage_exit(*g_ssl.argv);
		else if (mod == INTERACTIVE_MOD)
			ssl_print_error_message(*g_ssl.argv);
	}
}
