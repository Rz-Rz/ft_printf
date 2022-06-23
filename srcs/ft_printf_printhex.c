/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printhex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:25:48 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/23 15:52:38 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_print_ptr(t_print *tab)
{
	unsigned long long ptr;

	ptr = va_arg(tab->args, unsigned long long);
	ft_putnbr_hex(ptr, "0123456789abcdef");

}

void ft_putnbr_hex(unsigned long long n, char *base)
{
	if (n >= 16)
		ft_putnbr_hex(n / 16, base);
	if (n % 16 < 10)
		ft_putchar(n % 16 + '0');
	else
		ft_putchar(n % 16 + 'a' - 10);
}
