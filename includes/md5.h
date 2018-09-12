/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:18:18 by prippa            #+#    #+#             */
/*   Updated: 2018/08/29 18:19:31 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include "ssl.h"

# define F(x,y,z) (((x) & (y)) | ((~x) & (z)))
# define G(x,y,z) (((x) & (z)) | ((y) & (~z)))
# define H(x,y,z) ((x) ^ (y) ^ (z))
# define I(x,y,z) ((y) ^ ((x) | (~z)))

# define FF(a,b,c,d,m,s,t) { a += F(b,c,d) + m + t; a = b + ROTLEFT32(a,s); }
# define GG(a,b,c,d,m,s,t) { a += G(b,c,d) + m + t; a = b + ROTLEFT32(a,s); }
# define HH(a,b,c,d,m,s,t) { a += H(b,c,d) + m + t; a = b + ROTLEFT32(a,s); }
# define II(a,b,c,d,m,s,t) { a += I(b,c,d) + m + t; a = b + ROTLEFT32(a,s); }

typedef struct 			s_md5
{
	uint8_t				data[64];
	uint32_t			datalen;
	uint32_t			state[4];
	uint32_t			t[4];
	uint32_t			m[16];
	uint32_t			*words;
	uint32_t			i;
	uint32_t			j;
}						t_md5;

void					ssl_md5_start_raunds(t_md5 *md);

#endif
