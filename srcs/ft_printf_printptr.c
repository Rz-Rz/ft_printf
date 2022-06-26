/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:25:48 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/26 18:43:52 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_print_ptr(t_print *tab)
{
	unsigned long long ptr;
	int len;

	len = 0;
	ptr = va_arg(tab->args, unsigned long long);
	len = ft_hexlen(ptr);
	if (tab->maxwidth > len)
	{
		if (tab->dash)
			ft_print_hex_left(tab, len, ptr);
		else
			ft_print_hex_right(tab, len, ptr);
	}
	else 
	{
		tab->tl += ft_putstr("0x");
		ft_putnbr_hex(ptr, tab);
		tab->tl += len;
	}
}

void ft_putnbr_hex(unsigned long long n, t_print *tab)
{
	if (n >= 16)
	{
		ft_putnbr_hex(n / 16, tab);
		ft_putnbr_hex(n % 16, tab);
	}
	else if (!tab->upper)
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_putchar(n + 'a' - 10);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_putchar(n + 'A' - 10);
	}
}

int ft_hexlen(unsigned long long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void ft_print_hex_left(t_print *tab, int len, unsigned long long ptr)
{
	int i;

	tab->tl += ft_putstr("0x");
	ft_putnbr_hex(ptr, tab);
	tab->tl += len;
	i = 0;
	while (i < tab->maxwidth - (len + 2))
		i += ft_print_spaces(tab);
}

void ft_print_hex_right(t_print *tab, int len, unsigned long long ptr)
{
	int i;

	i = 0;
	while (i < tab->maxwidth - (len + 2))
		i += ft_print_spaces(tab);
	tab->tl += ft_putstr("0x");
	ft_putnbr_hex(ptr, tab);
	tab->tl += len;
}
