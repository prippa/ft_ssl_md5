#include "sha512.h"

void		ssl_sha512_finish(t_sha512 *sh)
{
	ssl_sha512_increment_bitlen(sh, sh->datalen * 8);
	if (sh->datalen < 112)
	{
		sh->data[sh->datalen++] = 128;
		while (sh->datalen < 112)
			sh->data[sh->datalen++] = 0;
	}
	else
	{
		sh->data[sh->datalen++] = 128;
		while (sh->datalen < 128)
			sh->data[sh->datalen++] = 0;
		ssl_sha512_transform(sh);
		ft_bzero(sh->data, 112);
	}
	sh->i = 128;
	sh->j = -8;
	while (--sh->i > 119)
		sh->data[sh->i] = sh->bitlen[0] >> (sh->j += 8);
	sh->j = -8;
	while (sh->i > 111)
		sh->data[sh->i--] = sh->bitlen[1] >> (sh->j += 8);
	ssl_sha512_transform(sh);
}

void		 ssl_sha512_algo(t_sha512 *sh)
{
	sh->i = -1;
	while (++sh->i < 80)
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

void		ssl_sha512_transform(t_sha512 *sh)
{
	sh->words = (uint64_t *)sh->data;
	sh->i = -1;
	while (++sh->i < 16)
		sh->m[sh->i] = __builtin_bswap64(sh->words[sh->i]);
	while (sh->i < 80)
	{
		sh->m[sh->i] = SIG1(sh->m[sh->i - 2]) +
			sh->m[sh->i - 7] + SIG0(sh->m[sh->i - 15]) + sh->m[sh->i - 16];
		++sh->i;
	}
	ft_memcpy(sh->t, sh->state, 64);
	ssl_sha512_algo(sh);
	sh->i = -1;
	while (++sh->i < 8)
		sh->state[sh->i] += sh->t[sh->i];
}

void		ssl_sha512_run(t_sha512 *sh)
{
	size_t i;

	i = -1;
	while (++i < g_ssl.size)
	{
		sh->data[sh->datalen++] = g_ssl.s[i];
		if (sh->datalen == 128)
		{
			ssl_sha512_transform(sh);
			ssl_sha512_increment_bitlen(sh, 1024);
			sh->datalen = 0;
		}
	}
}
