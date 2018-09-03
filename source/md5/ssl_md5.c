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
	int		word;

	len = MD5_TAIL_LEN(g_ssl.size);
	if (!(g_ssl.tail = ft_memalloc(len)))
		ssl_fatal_error("malloc failed");
	*g_ssl.tail = 0x80;
	word = g_ssl.size >> 32;
	g_ssl.tail[--len] = BITS_LR_MOVE(word, 24, 24);
	g_ssl.tail[--len] = BITS_LR_MOVE(word, 16, 24);
	g_ssl.tail[--len] = BITS_LR_MOVE(word, 8, 24);
	g_ssl.tail[--len] = word >> 24;
	word = BITS_LR_MOVE(g_ssl.size, 32, 32);
	g_ssl.tail[--len] = BITS_LR_MOVE(word, 24, 24);
	g_ssl.tail[--len] = BITS_LR_MOVE(word, 16, 24);
	g_ssl.tail[--len] = BITS_LR_MOVE(word, 8, 24);
	g_ssl.tail[--len] = word >> 24;
}

void		ssl_md5(void)
{
	// TESTTS
	// ft_putstr("******************************************************\n");
 	// ft_printf("md5 zaglushka\nstream - [%s]\nsize - (%d)\nsizelen - (%d)\nMod - (%d)\n",
	// g_ssl.s, g_ssl.size, ft_strlen(g_ssl.s), g_ssl.curent);
	// if (g_ssl.curent == FILE_MOD)
	// 	ft_printf("File name - [%s]\n", g_ssl.file_name);
	// u_int8_t *ptr = (u_int8_t *)g_ssl.tail;
	// size_t i = -1;
	// while (++i < g_ssl.tail_len)
	// 	ft_printf("%.2x ", ptr[i], i);
	// ft_putstr("******************************************************\n");
	ssl_md5_flow_alignment();
}
