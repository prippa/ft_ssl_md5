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

# define MD5_TAIL(x) (((x) % 64) < 56 ?\
(64 - ((x) % 64)) : (64 + (64 - ((x) % 64))))

#endif
