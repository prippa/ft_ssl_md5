/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_md5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 06:42:29 by prippa            #+#    #+#             */
/*   Updated: 2018/09/01 06:42:31 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

static void	ssl_md5_flow_alignment(void)
{
	int		len;
	char	*tail;

	len = MD5_TAIL(g_ssl.size);
	
}

void		ssl_md5(void)
{
	// TESTTS
	ft_putstr("******************************************************\n");
 	ft_printf("md5 zaglushka\nstream - [%s]\nsize - (%d)\nsizelen - (%d)\nMod - (%d)\n",
	g_ssl.s, g_ssl.size, ft_strlen(g_ssl.s), g_ssl.curent);
	if (g_ssl.curent == FILE_MOD)
		ft_printf("File name - [%s]\n", g_ssl.file_name);
	ft_putstr("******************************************************\n");
	////////////
	ssl_md5_flow_alignment();
}
