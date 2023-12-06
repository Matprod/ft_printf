/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_output2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:33:13 by mvoisin           #+#    #+#             */
/*   Updated: 2023/12/06 18:14:30 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_unsigned_number(unsigned int n)
{
	if (n > 9)
	{
		put_unsigned_number(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n % 10 + '0');
}

void	putnbr_base(unsigned long n, char *base)
{
	unsigned long	len_base;

	len_base = ft_strlen(base);
	if (n >= len_base)
	{
		putnbr_base(n / len_base, base);
		n %= len_base;
	}
	ft_putchar(base[n % len_base]);

}

unsigned int	nbr_len_base(unsigned long n, char *base)
{
	unsigned int	len;
	unsigned int	len_base;

	len = 0;
	len_base = ft_strlen(base);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= len_base;
		len++;
	}
	return (len);
}

unsigned int	nbr_len_unsigned(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

int main()
{
	//put_unsigned_number(-250);
	//putnbr_base(1333,"doRmir");
	nbr_len_base(1333,"dormir");
	return(0);
}