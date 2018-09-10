/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_interactive_read.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:24:53 by prippa            #+#    #+#             */
/*   Updated: 2018/08/29 18:24:55 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static void	ssl_ir_action(const char *line)
{
	char **args;

	if (ft_strcmp(line, ""))
	{
		if (!(args = ft_strsplit(line, ' ')))
			ft_perror_exit(MALLOC_ERR);
		g_ssl.argv = args;
		ssl_parser(INTERACTIVE_MOD);
		ft_arrdel(&args);
		ssl_refresh();
	}
}

void		ssl_interactive_read(void)
{
	int		random_error;
	char	*line;

	ft_putstr(SSL_CURSOR);
	while ((random_error = get_next_line(0, &line)) == 1)
	{
		if (!ft_strcmp(line, EXIT_CMD))
		{
			ft_strdel(&line);
			return ;
		}
		ssl_ir_action(line);
		ft_strdel(&line);
		ft_putstr(SSL_CURSOR);
	}
	if (random_error == -1)
		ft_perror_exit(READ_ERR);
}
