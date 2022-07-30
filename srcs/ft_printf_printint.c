/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:23:53 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/30 13:40:16 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_integer(t_print *tab)
{
	int	len;
	int	nb;

	nb = va_arg(tab->args, int);
	len = ft_intlen(nb);
	ft_printint_checker(tab, &nb, &len);
	if ((tab->maxwidth > 0 && tab->maxwidth > len) || (tab->minwidth > 0
			&& tab->minwidth > len))
	{
		if (tab->dash == 1)
			ft_print_int_left(tab, nb, len);
		else
			ft_print_int_right(tab, nb, len);
	}
	else
	{
		ft_printflags(tab, nb);
		ft_putnbr(nb, tab);
	}
}

void	ft_putnbr(int nb, t_print *tab)
{
	if (nb < 0)
	{
		nb = -nb;
		if (!tab->already_neg)
			tab->tl += ft_putchar('-');
	}
	if (nb == -2147483648)
	{
		tab->tl += ft_putstr("2147483648");
		return ;
	}
	else if (tab->sign && !tab->is_neg)
		ft_print_plus(tab);
	if (tab->space_flag == 1 && !tab->is_neg && !tab->zero)
		ft_print_spaceflag(tab);
	if (tab->pnt && tab->minwidth == 0 && nb == 0)
		return ;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, tab);
		tab->tl += ft_putchar(nb % 10 + '0');
	}
	else
		tab->tl += ft_putchar(nb + '0');
}

int	ft_intlen(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		if (nb == -2147483648)
			return (10);
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

void	ft_print_int_right(t_print *tab, int nb, int len)
{
	if (tab->pnt && tab->minwidth > tab->maxwidth)
		ft_printint_flagsplusminwidth(tab, nb, len);
	else if (tab->pnt && tab->minwidth < tab->maxwidth)
	{
		if (tab->minwidth > len)
			ft_print_maxwidthmin(tab);
		else
			ft_print_maxwidth(tab, len, ' ');
		ft_printint_flagsplusminwidth(tab, nb, len);
	}
	else if (tab->pnt && tab->minwidth == tab->maxwidth)
		ft_printint_flagsplusminwidth(tab, nb, len);
	else if (tab->zero)
	{
		ft_printflags(tab, nb);
		ft_print_maxwidth(tab, len, '0');
	}
	else
		ft_print_maxwidth(tab, len, ' ');
	ft_putnbr(nb, tab);
}

void	ft_print_int_left(t_print *tab, int nb, int len)
{
	if (tab->minwidth > len)
	{
		ft_printflags(tab, nb);
		ft_print_minwidth(tab, len);
		ft_putnbr(nb, tab);
		ft_print_maxwidthmin(tab);
	}
	else
	{
		ft_putnbr(nb, tab);
		if (tab->pnt && tab->minwidth != 0)
		{
			if (tab->maxwidth > len)
				ft_print_maxwidth(tab, len, ' ');
		}
		else
			ft_print_maxwidth(tab, len, ' ');
	}
}
