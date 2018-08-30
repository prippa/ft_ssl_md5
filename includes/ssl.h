/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:47:22 by prippa            #+#    #+#             */
/*   Updated: 2018/08/27 14:48:42 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H
# define SSL_H

# include "libft.h"

# define SSL_CMD_SIZE 3

typedef enum			e_mod
{
	BASE_MOD,
	INTERACTIVE_MOD
}						t_mod;

void			ssl_print_error_message(const char *cmd);
void			ssl_print_usage_exit(const char *cmd);

void			ssl_md5(void);
void			ssl_sha256(void);
void			ssl_sha512(void);

void			ssl_interactive_read(void);
void			ssl_cmd_check(char **argv, t_mod mod);

static const char		*g_string_cmd[SSL_CMD_SIZE] =
{
	"md5",
	"sha256",
	"sha512"
};

typedef void (*t_func_cmd)(void);
static const t_func_cmd	g_func_cmd[SSL_CMD_SIZE] =
{
	ssl_md5,
	ssl_sha256,
	ssl_sha512
};

#endif
