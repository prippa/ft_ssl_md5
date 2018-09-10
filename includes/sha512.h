#ifndef SHA512_H
# define SHA512_H

# include "ssl.h"

# define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
# define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
# define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
# define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))

typedef struct 			s_sha512
{
	uint8_t				data[64];
	uint32_t			datalen;
	uint32_t			state[8];
	uint32_t			t[8];
	uint32_t			m[64];
	uint32_t			i;
	uint32_t			j;
}						t_sha512;

#endif
