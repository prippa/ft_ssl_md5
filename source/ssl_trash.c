/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_trash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 06:44:17 by prippa            #+#    #+#             */
/*   Updated: 2018/09/01 06:44:19 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

char		*ssl_error_str(const char *file_name)
{
	uint32_t len;

	len = (ft_strlen(SSL_CH) + ft_strlen(SEPARATE_CH) +
		ft_strlen(g_string_hash[g_ssl.type]) + ft_strlen(SEPARATE_CH) +
		ft_strlen(file_name));
	if (!(g_ssl.tmp = (char *)malloc(sizeof(char) * (len + 1))))
		ssl_fatal_error(MALLOC_ERR);
	ft_strcpy(g_ssl.tmp, SSL_CH);
	ft_strcat(g_ssl.tmp, SEPARATE_CH);
	ft_strcat(g_ssl.tmp, g_string_hash[g_ssl.type]);
	ft_strcat(g_ssl.tmp, SEPARATE_CH);
	ft_strcat(g_ssl.tmp, file_name);
	return (g_ssl.tmp);
}

void		ssl_refresh(void)
{
	ft_bzero(&g_ssl, sizeof(t_ssl));
}

void		ssl_del(void)
{
	ft_strdel(&g_ssl.s);
	ft_strdel((char **)&g_ssl.res_hash_str);
}

void		ssl_fatal_error(const char *message)
{
	ssl_del();
	ft_perror_exit(message);
}
