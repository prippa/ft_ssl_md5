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

void	ssl_interactive_read(void)
{
	int		random_error;
	char	*line;
	char	**args;

	ft_putstr("ft_ssl> ");
	while ((random_error = get_next_line(0, &line)) == 1)
	{
		if (!ft_strcmp(line, "exit"))
		{
			ft_strdel(&line);
			break ;
		}
		if (ft_strcmp(line, ""))
		{
			if (!(args = ft_strsplit(line, ' ')))
				ft_perror_exit("malloc failed");
			ssl_cmd_check(args, INTERACTIVE_MOD);
			ft_arrdel(&args);
		}
		ft_strdel(&line);
		ft_putstr("ft_ssl> ");
	}
	if (random_error == -1)
		ft_perror_exit("get_next_line failed");
}
