/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 09:14:37 by prippa            #+#    #+#             */
/*   Updated: 2018/09/01 09:14:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		ssl_read(int fd)
{
	char	buf[SSL_BUF_SIZE + 1];
	int		i;

	if (!(g_ssl.s = ft_memalloc(1)))
		ssl_fatal_error("malloc failed");
	while ((i = read(fd, buf, SSL_BUF_SIZE)) > 0)
	{
		buf[i] = 0;
		if (!(g_ssl.s = ft_strjoin_free(&g_ssl.s, buf, g_ssl.size, i)))
			ssl_fatal_error("malloc failed");
		g_ssl.size += i;
	}
	if (i == -1)
		ssl_fatal_error("read failed");
	if (g_ssl.f[SSL_FLAG_P])
	{
		write(1, g_ssl.s, g_ssl.size);
		g_ssl.f[SSL_FLAG_P] = 0;
	}
}

void		ssl_read_from_file(const char *file_name)
{
	int fd;

	if ((fd = open(file_name, O_RDONLY)) == -1 || read(fd, NULL, 0) == -1)
		ssl_fatal_error("open failed");
	ft_strcpy(g_ssl.file_name, file_name);
	ssl_read(fd);
}
