/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:23:53 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/15 16:29:14 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

void ft_print_integer(t_print *tab)
{
	int len;
	int nb;

	nb = va_arg(tab->args, int);
	len = ft_intlen(nb);
}


int ft_putnbr(int len, int nb)
{
	int i;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	i = 0;
	while (i < len)
	{
		ft_putchar(nb % 10 + '0');
		nb = nb / 10;
		i++;
	}
	return (len);
}

int ft_intlen(int nb)
{
	int len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
