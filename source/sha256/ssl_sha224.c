#include "sha256.h"

void		ssl_sha224(void)
{
	t_sha256 sh;

	sh.state[0] = 0xc1059ed8;
	sh.state[1] = 0x367cd507;
	sh.state[2] = 0x3070dd17;
	sh.state[3] = 0xf70e5939;
	sh.state[4] = 0xffc00b31;
	sh.state[5] = 0x68581511;
	sh.state[6] = 0x64f98fa7;
	sh.state[7] = 0xbefa4fa4;
	sh.datalen = 0;
	ssl_sha256_run(&sh);
	ssl_sha256_finish(&sh);
	ssl_sha256_prepare_hash_string(&sh, 28);
}
