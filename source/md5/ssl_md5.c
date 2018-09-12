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

static void	ssl_md5_prepare_hash_string(t_md5 *md)
{
	if (!(g_ssl.res_hash_str = (uint8_t *)malloc(sizeof(uint8_t) * 16)))
		ssl_fatal_error(MALLOC_ERR);
	md->i = -1;
	md->j = -1;
	while (++md->j < 4)
	{
		g_ssl.res_hash_str[++md->i] = md->state[md->j];
		g_ssl.res_hash_str[++md->i] = md->state[md->j] >> 8;
		g_ssl.res_hash_str[++md->i] = md->state[md->j] >> 16;
		g_ssl.res_hash_str[++md->i] = md->state[md->j] >> 24;
	}
	g_ssl.size = 16;
}

static void	ssl_md5_transform(t_md5 *md)
{
	md->words = (uint32_t *)md->data;
	md->i = -1;
	while (++md->i < 16)
		md->m[md->i] = md->words[md->i];
	ft_memcpy(md->t, md->state, 16);
	ssl_md5_start_raunds(md);
	md->i = -1;
	while (++md->i < 4)
		md->state[md->i] += md->t[md->i];
}

static void	ssl_md5_finish(t_md5 *md)
{
	if (md->datalen < 56)
	{
		md->data[md->datalen++] = 128;
		while (md->datalen < 56)
			md->data[md->datalen++] = 0;
	}
	else
	{
		md->data[md->datalen++] = 128;
		while (md->datalen < 64)
			md->data[md->datalen++] = 0;
		ssl_md5_transform(md);
		ft_bzero(md->data, 56);
	}
	g_ssl.size *= 8;
	md->i = 55;
	md->j = -8;
	while (++md->i < 64)
		md->data[md->i] = g_ssl.size >> (md->j += 8);
	ssl_md5_transform(md);
}

static void	ssl_md5_run(t_md5 *md)
{
	size_t i;

	i = -1;
	while (++i < g_ssl.size)
	{
		md->data[md->datalen++] = g_ssl.s[i];
		if (md->datalen == 64)
		{
			ssl_md5_transform(md);
			md->datalen = 0;
		}
	}
}

void		ssl_md5(void)
{
	t_md5 md;

	md.state[0] = 0x67452301;
	md.state[1] = 0xEFCDAB89;
	md.state[2] = 0x98BADCFE;
	md.state[3] = 0x10325476;
	md.datalen = 0;
	ssl_md5_run(&md);
	ssl_md5_finish(&md);
	ssl_md5_prepare_hash_string(&md);
}
