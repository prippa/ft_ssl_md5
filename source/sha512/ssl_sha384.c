/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_sha384.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:09:35 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:09:36 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha512.h"

void		ssl_sha384(void)
{
	t_sha512 sh;

	sh.state[0] = 0xcbbb9d5dc1059ed8;
	sh.state[1] = 0x629a292a367cd507;
	sh.state[2] = 0x9159015a3070dd17;
	sh.state[3] = 0x152fecd8f70e5939;
	sh.state[4] = 0x67332667ffc00b31;
	sh.state[5] = 0x8eb44a8768581511;
	sh.state[6] = 0xdb0c2e0d64f98fa7;
	sh.state[7] = 0x47b5481dbefa4fa4;
	sh.datalen = 0;
	sh.bitlen[0] = 0;
	sh.bitlen[1] = 0;
	sh.biti = 0;
	ssl_sha512_run(&sh);
	ssl_sha512_finish(&sh);
	ssl_sha512_prepare_hash_string(&sh, 48);
}
