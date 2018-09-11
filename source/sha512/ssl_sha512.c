#include "sha512.h"

void		ssl_sha512(void)
{
	t_sha512 sh;

	sh.state[0] = 0x6a09e667f3bcc908;
	sh.state[1] = 0xbb67ae8584caa73b;
	sh.state[2] = 0x3c6ef372fe94f82b;
	sh.state[3] = 0xa54ff53a5f1d36f1;
	sh.state[4] = 0x510e527fade682d1;
	sh.state[5] = 0x9b05688c2b3e6c1f;
	sh.state[6] = 0x1f83d9abfb41bd6b;
	sh.state[7] = 0x5be0cd19137e2179;
	sh.datalen = 0;
	sh.bitlen[0] = 0;
	sh.bitlen[1] = 0;
	sh.biti = 0;
	ssl_sha512_run(&sh);
	ssl_sha512_finish(&sh);
	ssl_sha512_prepare_hash_string(&sh, 64);
}
