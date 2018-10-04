/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_sha512_256.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:12:13 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:12:14 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha512.h"

void		ssl_sha512_256(void)
{
	t_sha512 sh;

	sh.state[0] = 0x22312194FC2BF72C;
	sh.state[1] = 0x9F555FA3C84C64C2;
	sh.state[2] = 0x2393B86B6F53B151;
	sh.state[3] = 0x963877195940EABD;
	sh.state[4] = 0x96283EE2A88EFFE3;
	sh.state[5] = 0xBE5E1E2553863992;
	sh.state[6] = 0x2B0199FC2C85B8AA;
	sh.state[7] = 0x0EB72DDC81C52CA2;
	sh.datalen = 0;
	sh.bitlen[0] = 0;
	sh.bitlen[1] = 0;
	sh.biti = 0;
	ssl_sha512_run(&sh);
	ssl_sha512_finish(&sh);
	ssl_sha512_prepare_hash_string(&sh, 32);
}
