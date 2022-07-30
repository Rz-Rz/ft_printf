/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:16:03 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/28 17:08:41 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_zero(t_print *tab)
{
	tab->tl += ft_putchar('0');
	return (1);
}

int	ft_print_spaces(t_print *tab)
{
	tab->tl += ft_putchar(' ');
	return (1);
}

int	ft_print_minus(t_print *tab)
{
	tab->tl += ft_putchar('-');
	tab->already_neg = 1;
	return (1);
}

int	ft_print_plus(t_print *tab)
{
	tab->tl += ft_putchar('+');
	tab->sign--;
	return (1);
}

int	ft_print_spaceflag(t_print *tab)
{
	tab->tl += ft_putchar(' ');
	tab->space_flag--;
	return (1);
}
