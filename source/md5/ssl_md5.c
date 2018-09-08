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

static void	ssl_md5_transform(t_md5 *md)
{
	md->i = -1;
	md->j = 0;
	while (++md->i < 16)
	{
		md->m[md->i] = (md->data[md->j]) +
					(md->data[md->j + 1] << 8) +
					(md->data[md->j + 2] << 16) +
					(md->data[md->j + 3] << 24);
		md->j += 4;
	}
	ft_memcpy(md->t, md->state, 16);
	ssl_md5_start_raunds(md);
	md->state[0] += md->t[0];
	md->state[1] += md->t[1];
	md->state[2] += md->t[2];
	md->state[3] += md->t[3];
}

static void	ssl_md5_run(t_md5 *md)
{
	uint32_t i;

	i = -1;
	while (++i < g_ssl.size)
	{
		md->data[md->datalen++] = g_ssl.s[i];
		if (md->datalen == 64)
		{
			ssl_md5_transform(md);
			DBL_INT_ADD(md->bits[0], md->bits[1], 512);
			md->datalen = 0;
		}
	}
}

static void	ssl_md5_prepare_hash_string(t_md5 *md)
{
	if (!(g_ssl.res_hash_str = (uint8_t *)malloc(sizeof(uint8_t) * 16)))
		ssl_fatal_error("malloc failed");
	md->i = -1;
	md->j = 0;
	while (md->j < 4)
	{
		g_ssl.res_hash_str[++md->i] = md->state[md->j];
		g_ssl.res_hash_str[++md->i] = md->state[md->j] >> 8;
		g_ssl.res_hash_str[++md->i] = md->state[md->j] >> 16;
		g_ssl.res_hash_str[++md->i] = md->state[md->j] >> 24;
		++md->j;
	}
	g_ssl.size = 16;
}

static void	ssl_md5_finish(t_md5 *md)
{
	DBL_INT_ADD(md->bits[0], md->bits[1], 8 * md->datalen);
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
	md->data[56] = md->bits[0];
	md->data[57] = md->bits[0] >> 8;
	md->data[58] = md->bits[0] >> 16;
	md->data[59] = md->bits[0] >> 24;
	md->data[60] = md->bits[1];
	md->data[61] = md->bits[1] >> 8;
	md->data[62] = md->bits[1] >> 16;
	md->data[63] = md->bits[1] >> 24;
	ssl_md5_transform(md);
}

void		ssl_md5(void)
{
	t_md5 md;

	md.state[0] = 0x67452301;
	md.state[1] = 0xEFCDAB89;
	md.state[2] = 0x98BADCFE;
	md.state[3] = 0x10325476;
	md.bits[0] = 0;
	md.bits[1] = 0;
	md.datalen = 0;
	ssl_md5_run(&md);
	ssl_md5_finish(&md);
	ssl_md5_prepare_hash_string(&md);
}
