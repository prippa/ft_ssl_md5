#include "sha256.h"

void	ssl_sha256_prepare_hash_string(t_sha256 *sh, uint32_t size)
{
	if (!(g_ssl.res_hash_str = (uint8_t *)malloc(sizeof(uint8_t) * size)))
		ssl_fatal_error(MALLOC_ERR);
	sh->i = -1;
	sh->j = -1;
	while (++sh->j < (size / 4))
	{
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 24;
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 16;
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 8;
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j];
	}
	g_ssl.size = size;
}

void		ssl_sha256_finish(t_sha256 *sh)
{
	if (sh->datalen < 56)
	{
		sh->data[sh->datalen++] = 128;
		while (sh->datalen < 56)
			sh->data[sh->datalen++] = 0;
	}
	else
	{
		sh->data[sh->datalen++] = 128;
		while (sh->datalen < 64)
			sh->data[sh->datalen++] = 0;
		ssl_sha256_transform(sh);
		ft_bzero(sh->data, 56);
	}
	g_ssl.size *= 8;
	sh->i = 64;
	sh->j = -8;
	while (--sh->i > 55)
		sh->data[sh->i] = g_ssl.size >> (sh->j += 8);
	ssl_sha256_transform(sh);
}

static void	ssl_sha256_algo(t_sha256 *sh)
{
	sh->i = -1;
	while (++sh->i < 64)
	{
		sh->tmp1 = sh->t[7] + EP1(sh->t[4]) +
			CH(sh->t[4], sh->t[5], sh->t[6]) + t_k[sh->i] + sh->m[sh->i];
		sh->tmp2 = EP0(sh->t[0]) + MAJ(sh->t[0], sh->t[1], sh->t[2]);
		sh->t[7] = sh->t[6];
		sh->t[6] = sh->t[5];
		sh->t[5] = sh->t[4];
		sh->t[4] = sh->t[3] + sh->tmp1;
		sh->t[3] = sh->t[2];
		sh->t[2] = sh->t[1];
		sh->t[1] = sh->t[0];
		sh->t[0] = sh->tmp1 + sh->tmp2;
	}
}

void		ssl_sha256_transform(t_sha256 *sh)
{
	sh->i = -1;
	sh->j = 0;
	while (++sh->i < 16)
	{
		sh->m[sh->i] = (sh->data[sh->j] << 24) | (sh->data[sh->j + 1] << 16) |
			(sh->data[sh->j + 2] << 8) | (sh->data[sh->j + 3]);
		sh->j += 4;
	}
	while (sh->i < 64)
	{
		sh->m[sh->i] = SIG1(sh->m[sh->i - 2]) +
			sh->m[sh->i - 7] + SIG0(sh->m[sh->i - 15]) + sh->m[sh->i - 16];
		++sh->i;
	}
	ft_memcpy(sh->t, sh->state, 32);
	ssl_sha256_algo(sh);
	sh->state[0] += sh->t[0];
	sh->state[1] += sh->t[1];
	sh->state[2] += sh->t[2];
	sh->state[3] += sh->t[3];
	sh->state[4] += sh->t[4];
	sh->state[5] += sh->t[5];
	sh->state[6] += sh->t[6];
	sh->state[7] += sh->t[7];
}

void		ssl_sha256_run(t_sha256 *sh)
{
	uint32_t i;

	i = -1;
	while (++i < g_ssl.size)
	{
		sh->data[sh->datalen++] = g_ssl.s[i];
		if (sh->datalen == 64)
		{
			ssl_sha256_transform(sh);
			sh->datalen = 0;
		}
	}
}
