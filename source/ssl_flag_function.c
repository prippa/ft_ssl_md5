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
	ssl_read(0);
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
	// logic
	g_hash_func[g_ssl.type]();
	ssl_del();
	return (1);
}
