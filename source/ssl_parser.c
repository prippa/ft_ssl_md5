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

}

static int	ssl_check_flags(const char *f)
{
	int			i;

	while (*f)
	{
		i = -1;
		while (++i < SSL_FLAG_SIZE)
			if (g_hash_flags[i] == *f)
			{
				g_ssl.tmp = f;
				if (!(g_hash_flags_func[i]()))
					return (1);
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
		if ((ssl_check_flags(g_ssl.argv[g_ssl.i] + 1)))
			return (1);
		++g_ssl.i;
	}
	return (0);
}

static int	ssl_check_cmd(void)
{
	int i;

	i = -1;
	while (++i < SSL_CMD_SIZE)
		if (!ft_strcmp(*g_ssl.argv, g_string_hash[i]))
		{
			g_ssl.type = i;
			++g_ssl.i;
			return (1);
		}
	return (0);
}

void		ssl_parser(t_mod mod)
{
	if (ssl_check_cmd())
	{
		if (ssl_parse_flags())
		{
			ssl_print_hash_flags_usage(g_ssl.argv[g_ssl.i]);
			return ;
		}
		ssl_validate_file();
		if (!g_ssl.f[SSL_FLAG_P] && !g_ssl.f[SSL_FLAG_S] && !g_ssl.f_f)
		{
			ssl_read(0);
			g_hash_func[g_ssl.type]();
		}
	}
	else
	{
		if (mod == BASE_MOD)
			ssl_print_usage_exit(*g_ssl.argv);
		else if (mod == INTERACTIVE_MOD)
			ssl_print_error_message(*g_ssl.argv);
	}
}
