#include "sha512.h"

void		ssl_sha512_increment_bitlen(t_sha512 *sh, uint16_t size)
{
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
