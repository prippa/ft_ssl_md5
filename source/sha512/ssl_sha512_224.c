#include "sha512.h"

static void	ssl_sha512_224_prepare_hash_string(t_sha512 *sh)
{
	if (!(g_ssl.res_hash_str = (uint8_t *)malloc(sizeof(uint8_t) * 28)))
		ssl_fatal_error(MALLOC_ERR);
	sh->i = -1;
	sh->j = -1;
	while (++sh->j < 4)
	{
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 56;
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 48;
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 40;
		g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 32;
		if (sh->j < 3)
		{
			g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 24;
			g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 16;
			g_ssl.res_hash_str[++sh->i] = sh->state[sh->j] >> 8;
			g_ssl.res_hash_str[++sh->i] = sh->state[sh->j];
		}
	}
	g_ssl.size = 28;
}

void		ssl_sha512_224(void)
{
	t_sha512 sh;

	sh.state[0] = 0x8C3D37C819544DA2;
	sh.state[1] = 0x73E1996689DCD4D6;
	sh.state[2] = 0x1DFAB7AE32FF9C82;
	sh.state[3] = 0x679DD514582F9FCF;
	sh.state[4] = 0x0F6D2B697BD44DA8;
	sh.state[5] = 0x77E36F7304C48942;
	sh.state[6] = 0x3F9D85A86A1D36C8;
	sh.state[7] = 0x1112E6AD91D692A1;
	sh.datalen = 0;
	sh.bitlen[0] = 0;
	sh.bitlen[1] = 0;
	sh.biti = 0;
	ssl_sha512_run(&sh);
	ssl_sha512_finish(&sh);
	ssl_sha512_224_prepare_hash_string(&sh);
}
