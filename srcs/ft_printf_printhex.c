/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printhex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:25:48 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/24 13:13:52 by kdhrif           ###   ########.fr       */
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
	}
}

void ft_putnbr_hex(unsigned long long n, t_print *tab)
{
	if (n >= 16)
		ft_putnbr_hex(n / 16, tab);
	if (n % 16 < 10)
		tab->tl += ft_putchar(n % 16 + '0');
	else
		tab->tl += ft_putchar(n % 16 + 'a' - 10);
}

int ft_hexlen(unsigned long long n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void ft_print_hex_left(t_print *tab, int len, int ptr)
{
	int i;

	i = 0;
	tab->tl += ft_putstr("0x");
	ft_putnbr_hex(ptr, tab);
	while (i < tab->maxwidth - len)
		i += ft_print_spaces(tab);
}

void ft_print_hex_right(t_print *tab, int len, int ptr)
{
	int i;

	i = 0;
	while (i < tab->maxwidth - len)
		i += ft_print_spaces(tab);
	tab->tl += ft_putstr("0x");
	ft_putnbr_hex(ptr, tab);
}
