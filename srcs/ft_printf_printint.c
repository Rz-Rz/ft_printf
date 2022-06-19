/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:23:53 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/15 21:33:24 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

void ft_print_integer(t_print *tab)
{
	int len;
	int nb;

	nb = va_arg(tab->args, int);
	len = ft_intlen(nb);
	if (tab->maxwidth > 0 && tab->maxwidth > len)
	{
		if (tab->dash == 1)
			ft_print_int_left(tab, nb, len);
		else
			ft_print_int_right(tab, nb, len);
	}
	else
		ft_putnbr(nb);
}


int ft_putnbr(int nb)
{
	int i;
	int len;

	len = 0;
	if (nb == 0 && ++len)
		ft_putchar('0');
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		len++;
	}
	i = 0;
	while (nb)
	{
		ft_putchar(nb % 10 + '0');
		nb = nb / 10;
		i++ && ++len;
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

void ft_print_int_right(t_print *tab, int nb, int len)
{
	int i;

	i = 0;
	if (tab->zero_flag == 1 && !tab->pnt)
		while (i < tab->maxwidth - len)
		{
			tab->tl = ft_putchar('0');
			i++;
		}
	else
		while (i < tab->maxwidth - len)
		{
			tab->tl = ft_putchar(' ');
			i++;
		}
	tab->tl += ft_putnbr(nb);
}

void ft_print_int_left(t_print *tab, int nb, int len)
{
	int i;

	i = 0;
	tab->tl += ft_putnbr(nb);
	if (tab->zero_flag == 1 && !tab->pnt)
		while (i < tab->maxwidth - len)
		{
			tab->tl = ft_putchar('0');
			i++;
		}
	else
		while (i < tab->maxwidth - len)
		{
			tab->tl = ft_putchar(' ');
			i++;
		}
}
