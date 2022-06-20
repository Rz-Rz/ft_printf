/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:23:53 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/20 16:30:51 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

void ft_print_integer(t_print *tab)
{
	int len;
	int nb;

	nb = va_arg(tab->args, int);
	len = ft_intlen(nb);
	if (tab->zero && tab->dash)
		tab->zero = 0;
	if ((tab->maxwidth > 0 && tab->maxwidth > len) || (tab->minwidth > 0 && tab->minwidth > len))
	{
		if (tab->dash == 1)
			ft_print_int_left(tab, nb, len);
		else
			ft_print_int_right(tab, nb, len);
	}
	else
		ft_putnbr(nb, tab);
}

void ft_putnbr(int nb, t_print *tab)
{
	if (nb == -2147483648)
		tab->tl += ft_putstr("-2147483648");
	if (nb < 0)
	{
		nb = -nb;
		tab->tl += ft_putchar('-');
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10, tab);
		tab->tl += ft_putchar(nb % 10 + '0');
	}
	else 
		tab->tl += ft_putchar(nb + '0');
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

void ft_print_int_right(t_print *tab, int nb, int len)
{
	int i;

	i = 0;
	if (tab->pnt && tab->minwidth > tab->maxwidth)
		while (i < tab->minwidth - len)
		{
			tab->tl += ft_putchar('0');
			i++;
		}
	else if (tab->pnt && tab->minwidth < tab->maxwidth)
	{
		while (i < tab->maxwidth - tab->minwidth)
		{
			tab->tl += ft_putchar(' ');
			i++;
		}
		i = 0;
		while (i < tab->minwidth - len)
		{
			tab->tl += ft_putchar('0');
			i++;
		}

	}
	else if (tab->zero)
		while (i < tab->maxwidth - len)
		{
			tab->tl += ft_putchar('0');
			i++;
		}
	else
		while (i < tab->maxwidth - len)
		{
			tab->tl += ft_putchar(' ');
			i++;
		}
	ft_putnbr(nb, tab);
}

void ft_print_int_left(t_print *tab, int nb, int len)
{
	int i;

	i = 0;
	ft_putnbr(nb, tab);
	if (tab->zero || tab->pnt)
		while (i < tab->minwidth - len)
		{
			tab->tl += ft_putchar('0');
			i++;
		}
	else
		while (i < tab->maxwidth - len)
		{
			tab->tl += ft_putchar(' ');
			i++;
		}
}
