/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_flag_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 10:01:22 by prippa            #+#    #+#             */
/*   Updated: 2018/09/01 10:01:23 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

int		ssl_flag_p(void)
{
	g_ssl.f[SSL_FLAG_P] = 1;
	g_ssl.curent = P_MOD;
	ssl_read(0, SSL_BUF_SIZE);
	write(1, g_ssl.s, g_ssl.size);
	g_hash_func[g_ssl.type]();
	ssl_del();
	return (1);
}

int		ssl_flag_q(void)
{
	g_ssl.f[SSL_FLAG_Q] = 1;
	return (1);
}

int		ssl_flag_r(void)
{
	g_ssl.f[SSL_FLAG_R] = 1;
	return (1);
}

int		ssl_flag_s(void)
{
	g_ssl.f[SSL_FLAG_S] = 1;
	g_ssl.curent = S_MOD;
	if (!*(g_ssl.tmp + 1) && !g_ssl.argv[g_ssl.i + 1])
		return (0);
	if (!*++g_ssl.tmp)
		g_ssl.tmp = g_ssl.argv[++g_ssl.i];
	if (!(g_ssl.s = ft_strdup(g_ssl.tmp)))
		ssl_fatal_error("malloc failed");
	g_ssl.size = ft_strlen(g_ssl.s);
	g_hash_func[g_ssl.type]();
	ssl_del();
	return (1);
}
