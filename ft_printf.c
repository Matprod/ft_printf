/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:43:00 by mvoisin           #+#    #+#             */
/*   Updated: 2023/12/07 18:51:55 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list args, char c)
{
	int	print_len;

	print_len = 0;
	if (c == 'c')
		print_len += print_char(va_arg(args, int));
	else if (c == 's')
		print_len += print_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		print_len += print_nbr(va_arg(args, int));
	else if (c == 'u')
		print_len += print_unsigned_nbr(va_arg(args, unsigned int));
	else if (c == 'p')
		print_len += print_ptr(va_arg(args, unsigned long));
	else if (c == 'x')
		print_len += print_hex(va_arg(args, unsigned int));
	else if (c == 'X')
		print_len += print_hex_caps(va_arg(args, unsigned int));
	else if (c == '%')
		print_len += print_percent();
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += check_format(args, str[i + 1]);
			i++;
		}
		else
			print_len += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}

/* #include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("len = %d ", ft_printf(" %x ", 0));
	return (0);
} */