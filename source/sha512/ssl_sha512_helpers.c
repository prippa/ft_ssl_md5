#include "sha512.h"

void		ssl_sha512_increment_bitlen(t_sha512 *sh, uint16_t size)
{
	if (size < 1)
		return ;
	if (sh->bitlen[sh->biti] + size > sh->bitlen[sh->biti])
		sh->bitlen[sh->biti] += size;
	else
	{
		sh->bitlen[sh->biti] += size;
		size = sh->bitlen[sh->biti] + 1;
		sh->bitlen[sh->biti] -= sh->bitlen[sh->biti] - 1;
		if (++sh->biti > 1)
		{
			sh->bitlen[0] = size;
			sh->bitlen[1] = 0;
			sh->biti = 0;
		}
		else
			sh->bitlen[sh->biti] += size;
	}
}

void		ssl_sha512_prepare_hash_string(t_sha512 *sh, uint16_t size)
{
	if (!(g_ssl.res_hash_str = (uint8_t *)malloc(sizeof(uint8_t) * size)))
		ssl_fatal_error(MALLOC_ERR);
	sh->i = -1;
	sh->j = -1;
	while (++sh->j < (size / 8))
	{
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 56;
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 48;
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 40;
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 32;
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 24;
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 16;
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 8;
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j];
	}
	g_ssl.size = size;
}
