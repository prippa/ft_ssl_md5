#include "md5.h"

static void	ssl_md5_round_1(t_md5 *md)
{
	FF(md->t[0], md->t[1], md->t[2], md->t[3], md->m[0], 7, 0xd76aa478);
	FF(md->t[3], md->t[0], md->t[1], md->t[2], md->m[1], 12, 0xe8c7b756);
	FF(md->t[2], md->t[3], md->t[0], md->t[1], md->m[2], 17, 0x242070db);
	FF(md->t[1], md->t[2], md->t[3], md->t[0], md->m[3], 22, 0xc1bdceee);
	FF(md->t[0], md->t[1], md->t[2], md->t[3], md->m[4], 7, 0xf57c0faf);
	FF(md->t[3], md->t[0], md->t[1], md->t[2], md->m[5], 12, 0x4787c62a);
	FF(md->t[2], md->t[3], md->t[0], md->t[1], md->m[6], 17, 0xa8304613);
	FF(md->t[1], md->t[2], md->t[3], md->t[0], md->m[7], 22, 0xfd469501);
	FF(md->t[0], md->t[1], md->t[2], md->t[3], md->m[8], 7, 0x698098d8);
	FF(md->t[3], md->t[0], md->t[1], md->t[2], md->m[9], 12, 0x8b44f7af);
	FF(md->t[2], md->t[3], md->t[0], md->t[1], md->m[10], 17, 0xffff5bb1);
	FF(md->t[1], md->t[2], md->t[3], md->t[0], md->m[11], 22, 0x895cd7be);
	FF(md->t[0], md->t[1], md->t[2], md->t[3], md->m[12], 7, 0x6b901122);
	FF(md->t[3], md->t[0], md->t[1], md->t[2], md->m[13], 12, 0xfd987193);
	FF(md->t[2], md->t[3], md->t[0], md->t[1], md->m[14], 17, 0xa679438e);
	FF(md->t[1], md->t[2], md->t[3], md->t[0], md->m[15], 22, 0x49b40821);
}

static void	ssl_md5_round_2(t_md5 *md)
{
	GG(md->t[0], md->t[1], md->t[2], md->t[3], md->m[1], 5, 0xf61e2562);
	GG(md->t[3], md->t[0], md->t[1], md->t[2], md->m[6], 9, 0xc040b340);
	GG(md->t[2], md->t[3], md->t[0], md->t[1], md->m[11], 14, 0x265e5a51);
	GG(md->t[1], md->t[2], md->t[3], md->t[0], md->m[0], 20, 0xe9b6c7aa);
	GG(md->t[0], md->t[1], md->t[2], md->t[3], md->m[5],  5, 0xd62f105d);
	GG(md->t[3], md->t[0], md->t[1], md->t[2], md->m[10], 9, 0x02441453);
	GG(md->t[2], md->t[3], md->t[0], md->t[1], md->m[15], 14, 0xd8a1e681);
	GG(md->t[1], md->t[2], md->t[3], md->t[0], md->m[4], 20, 0xe7d3fbc8);
	GG(md->t[0], md->t[1], md->t[2], md->t[3], md->m[9], 5, 0x21e1cde6);
	GG(md->t[3], md->t[0], md->t[1], md->t[2], md->m[14], 9, 0xc33707d6);
	GG(md->t[2], md->t[3], md->t[0], md->t[1], md->m[3], 14, 0xf4d50d87);
	GG(md->t[1], md->t[2], md->t[3], md->t[0], md->m[8], 20, 0x455a14ed);
	GG(md->t[0], md->t[1], md->t[2], md->t[3], md->m[13], 5, 0xa9e3e905);
	GG(md->t[3], md->t[0], md->t[1], md->t[2], md->m[2], 9, 0xfcefa3f8);
	GG(md->t[2], md->t[3], md->t[0], md->t[1], md->m[7], 14, 0x676f02d9);
	GG(md->t[1], md->t[2], md->t[3], md->t[0], md->m[12], 20, 0x8d2a4c8a);
}

static void	ssl_md5_round_3(t_md5 *md)
{
	HH(md->t[0], md->t[1], md->t[2], md->t[3], md->m[5], 4, 0xfffa3942);
	HH(md->t[3], md->t[0], md->t[1], md->t[2], md->m[8], 11, 0x8771f681);
	HH(md->t[2], md->t[3], md->t[0], md->t[1], md->m[11], 16, 0x6d9d6122);
	HH(md->t[1], md->t[2], md->t[3], md->t[0], md->m[14], 23, 0xfde5380c);
	HH(md->t[0], md->t[1], md->t[2], md->t[3], md->m[1], 4, 0xa4beea44);
	HH(md->t[3], md->t[0], md->t[1], md->t[2], md->m[4], 11, 0x4bdecfa9);
	HH(md->t[2], md->t[3], md->t[0], md->t[1], md->m[7], 16, 0xf6bb4b60);
	HH(md->t[1], md->t[2], md->t[3], md->t[0], md->m[10], 23, 0xbebfbc70);
	HH(md->t[0], md->t[1], md->t[2], md->t[3], md->m[13], 4, 0x289b7ec6);
	HH(md->t[3], md->t[0], md->t[1], md->t[2], md->m[0], 11, 0xeaa127fa);
	HH(md->t[2], md->t[3], md->t[0], md->t[1], md->m[3], 16, 0xd4ef3085);
	HH(md->t[1], md->t[2], md->t[3], md->t[0], md->m[6], 23, 0x04881d05);
	HH(md->t[0], md->t[1], md->t[2], md->t[3], md->m[9], 4, 0xd9d4d039);
	HH(md->t[3], md->t[0], md->t[1], md->t[2], md->m[12], 11, 0xe6db99e5);
	HH(md->t[2], md->t[3], md->t[0], md->t[1], md->m[15], 16, 0x1fa27cf8);
	HH(md->t[1], md->t[2], md->t[3], md->t[0], md->m[2], 23, 0xc4ac5665);
}

static void	ssl_md5_round_4(t_md5 *md)
{
	II(md->t[0], md->t[1], md->t[2], md->t[3], md->m[0], 6, 0xf4292244);
	II(md->t[3], md->t[0], md->t[1], md->t[2], md->m[7], 10, 0x432aff97);
	II(md->t[2], md->t[3], md->t[0], md->t[1], md->m[14], 15, 0xab9423a7);
	II(md->t[1], md->t[2], md->t[3], md->t[0], md->m[5], 21, 0xfc93a039);
	II(md->t[0], md->t[1], md->t[2], md->t[3], md->m[12], 6, 0x655b59c3);
	II(md->t[3], md->t[0], md->t[1], md->t[2], md->m[3], 10, 0x8f0ccc92);
	II(md->t[2], md->t[3], md->t[0], md->t[1], md->m[10], 15, 0xffeff47d);
	II(md->t[1], md->t[2], md->t[3], md->t[0], md->m[1], 21, 0x85845dd1);
	II(md->t[0], md->t[1], md->t[2], md->t[3], md->m[8], 6, 0x6fa87e4f);
	II(md->t[3], md->t[0], md->t[1], md->t[2], md->m[15], 10, 0xfe2ce6e0);
	II(md->t[2], md->t[3], md->t[0], md->t[1], md->m[6], 15, 0xa3014314);
	II(md->t[1], md->t[2], md->t[3], md->t[0], md->m[13], 21, 0x4e0811a1);
	II(md->t[0], md->t[1], md->t[2], md->t[3], md->m[4], 6, 0xf7537e82);
	II(md->t[3], md->t[0], md->t[1], md->t[2], md->m[11], 10, 0xbd3af235);
	II(md->t[2], md->t[3], md->t[0], md->t[1], md->m[2], 15, 0x2ad7d2bb);
	II(md->t[1], md->t[2], md->t[3], md->t[0], md->m[9], 21, 0xeb86d391);
}

void		ssl_md5_start_raunds(t_md5 *md)
{
	ssl_md5_round_1(md);
	ssl_md5_round_2(md);
	ssl_md5_round_3(md);
	ssl_md5_round_4(md);
}
