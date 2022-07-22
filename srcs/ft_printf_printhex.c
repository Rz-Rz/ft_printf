/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printhex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:10:15 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/22 13:01:17 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_print_hex(t_print *tab)
{
	unsigned int nb;
	int len;

	nb = va_arg(tab->args, unsigned int);
	len = ft_hexlen(nb);
	if (tab->maxwidth > len || tab->minwidth > len)
	{
		if (tab->dash)
			ft_print_hex_left(tab, len, nb);
		else
			ft_print_hex_right(tab, len, nb);
	}
	else 
	{
		if (tab->hash && tab->upper && nb != 0)
			tab->tl += ft_putstr("0X");
		else if (tab->hash && !tab->upper && nb != 0)
			tab->tl += ft_putstr("0x");
		ft_putnbr_hex(nb, tab);
		tab->tl += len;
	}
	
}

void ft_print_hex_right(t_print *tab, int len, unsigned long long nb)
{
	int i;
	int hash = 0;

	i = 0;
	if (tab->hash)
		hash = 2;
	if (tab->minwidth > len && tab->pnt)
		while (i < tab->minwidth - (len + hash))
			i += ft_print_zero(tab);
	else if (tab->zero) {
		while (i < tab->maxwidth - (len + hash))
			i += ft_print_zero(tab);
	}
	else {
		while (i < tab->maxwidth - (len + hash))
			i += ft_print_spaces(tab);
	}
	if (tab->maxwidth > len && tab->maxwidth > tab->minwidth)

	if (hash || tab->is_ptr)
	{
		if (tab->upper && tab->hash && nb != 0)
			tab->tl += ft_putstr("0X");
		else if (nb != 0 && tab->hash)
			tab->tl += ft_putstr("0x");
	}
	ft_putnbr_hex(nb, tab);
	tab->tl += len;
}

void ft_print_hex_left(t_print *tab, int len, unsigned long long nb)
{
	int i;
	int hash;

	hash = 0;
	i = 0;
	if (tab->hash || tab->is_ptr)
	{
		hash = 2;
		if (tab->upper)
			tab->tl += ft_putstr("0X");
		else
			tab->tl += ft_putstr("0x");
	}
	ft_putnbr_hex(nb, tab);
	tab->tl += len;
	while (i < tab->maxwidth - (len + hash))
		i += ft_print_spaces(tab);
}
