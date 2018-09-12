/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_print_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 06:44:01 by prippa            #+#    #+#             */
/*   Updated: 2018/09/01 06:44:03 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		ssl_print_hash_flags_usage(const char *cmd)
{
	ft_dprintf(2, "unknown option '%s'\n", cmd);
	ft_putstr("options are\n");
	ft_putstr("-p\t\techo STDIN to STDOUT and append the checksum to STDOUT\n");
	ft_putstr("-q\t\tquiet mode\n");
	ft_putstr("-r\t\treverse the format of the output\n");
	ft_putstr("[-s string]\tprint the sum of the given string\n");
}

static void	ssl_print_commands(void)
{
	ft_putstr("\nStandard commands:\n");
	ft_putstr("\nMessage Digest commands:\n");
	ft_putstr("md5\nsha256\nsha512\n");
	ft_putstr("\nCipher commands:\n\n");
}

void		ssl_print_error_message(const char *cmd)
{
	ft_dprintf(2, "ft_ssl: Error: '%s' is an invalid command.\n", cmd);
	ssl_print_commands();
}

void		ssl_print_usage_exit(const char *cmd)
{
	ft_putstr("usage: ft_ssl command [command opts] [command args]\n");
	ssl_print_error_message(cmd);
	exit (-1);
}
