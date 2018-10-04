/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_sha256.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:09:28 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:09:30 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha256.h"

void		ssl_sha256(void)
{
	t_sha256 sh;

	sh.state[0] = 0x6a09e667;
	sh.state[1] = 0xbb67ae85;
	sh.state[2] = 0x3c6ef372;
	sh.state[3] = 0xa54ff53a;
	sh.state[4] = 0x510e527f;
	sh.state[5] = 0x9b05688c;
	sh.state[6] = 0x1f83d9ab;
	sh.state[7] = 0x5be0cd19;
	sh.datalen = 0;
	ssl_sha256_run(&sh);
	ssl_sha256_finish(&sh);
	ssl_sha256_prepare_hash_string(&sh, 32);
}
