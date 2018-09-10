#include "ssl.h"

static void	ssl_print_hash_str(void)
{
	uint32_t i;

	i = -1;
	while (++i < g_ssl.size)
		ft_printf("%.2x", g_ssl.res_hash_str[i]);
}

static void	ssl_print_hash_p(void)
{
	ssl_print_hash_str();
	ft_putchar('\n');
}

static void	ssl_print_hash_s(void)
{
	if (g_ssl.f[SSL_FLAG_R])
	{
		ssl_print_hash_str();
		ft_printf(" \"%s\"\n", g_ssl.s);
	}
	else
	{
		ft_printf("%^s (\"%s\") = ", g_string_hash[g_ssl.type], g_ssl.s);
		ssl_print_hash_str();
		ft_putchar('\n');
	}
}

static void	ssl_print_hash_file(void)
{
	if (g_ssl.f[SSL_FLAG_R])
	{
		ssl_print_hash_str();
		ft_printf(" %s\n", g_ssl.file_name);
	}
	else
	{
		ft_printf("%^s (%s) = ", g_string_hash[g_ssl.type], g_ssl.file_name);
		ssl_print_hash_str();
		ft_putchar('\n');
	}
}

void		ssl_print_hash(void)
{
	if (g_ssl.f[SSL_FLAG_Q] || !g_ssl.curent)
	{
		ssl_print_hash_str();
		ft_putchar('\n');
	}
	else
	{
		if (g_ssl.curent == P_MOD)
			ssl_print_hash_p();
		else if (g_ssl.curent == S_MOD)
			ssl_print_hash_s();
		else if (g_ssl.curent == FILE_MOD)
			ssl_print_hash_file();
	}
}
