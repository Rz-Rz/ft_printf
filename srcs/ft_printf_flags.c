/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:16:03 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/22 17:18:04 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_print_zero(t_print *tab)
{
	tab->tl += ft_putchar('0');
	return (1);
}

int ft_print_spaces(t_print *tab)
{
	tab->tl += ft_putchar(' ');
	return (1);
}
