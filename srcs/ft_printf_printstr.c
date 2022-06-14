/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:29:33 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/12 18:36:27 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


void ft_printstr(t_print *tab)
{
	int i;
	int len;
	char *str;

	str = va_arg(tab->args, char*);
	if (!str) 
		str = "(null)";
	len = ft_strlen(str);
	i = 0;
	if (tab->precision != -1 && tab->precision < len)
		len = tab->precision;
	if (tab->width > len)
		ft_print_width(tab, len);
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int ft_putchar(char c)
{
		write(1, &c, 1);
		return (1);
}

int ft_putstr(char *s)
{
		int i;

		i = 0;
		while (s[i])
				write(1, &s[i++], 1);
		return (i);
}

int ft_strlen(char *s)
{
		int i;

		i = 0;
		while (s[i])
				i++;
		return (i);
}
