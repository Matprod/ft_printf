/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:50:11 by mvoisin           #+#    #+#             */
/*   Updated: 2023/12/06 18:16:55 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *s)
{	
	int	count;

	count = 0;
	while (*s++)
	{
		count++;
	}
	return (count);
}

void	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 +'0');
	}
	else
		ft_putchar(nb + '0');
}

int	nbr_len(int n)
{
	unsigned int	nb;
	unsigned int	len;

	len = 0;
	if (n < 0)
		nb = -n;
	if (n == 0)
		return (1);
	else
		nb = n;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}
/*int	main()
{
	//ft_putnbr(-10000);
	//printf("%d",nbr_len(0));
	//ft_putstr("salut");
	return (0);
}*/