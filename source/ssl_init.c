/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 08:49:29 by prippa            #+#    #+#             */
/*   Updated: 2018/09/01 08:49:30 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

struct s_ssl g_ssl;

void		ssl_init(char **argv)
{
	ft_bzero(&g_ssl, sizeof(t_ssl));
	g_ssl.argv = argv + 1;
	if (*g_ssl.argv)
		ft_str_to_upper(g_ssl.argv);
}
