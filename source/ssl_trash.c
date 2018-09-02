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

void		ssl_refresh(void)
{
	ft_bzero(&g_ssl, sizeof(t_ssl));
}

void		ssl_del(void)
{
	ft_strdel(&g_ssl.s);
}

void		ssl_fatal_error(const char *message)
{
	ssl_del();
	ft_perror_exit(message);
}
