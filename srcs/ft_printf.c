/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:35:32 by kdhrif            #+#    #+#             */
/*   Updated: 2022/05/31 18:53:04 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_print *ft_initialise_tab(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->zero_pdg = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->tl = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->space_flag = 0;
	tab->hash = 0;
	return (tab);
}

int ft_printf(const char *format, ...)
{
	int i;
	int ret;
	t_print *tab;

	tab = malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	i = -1;
	ret = 0;
	while(format[++i])
	{
		if (format[i] == '%')
			i = ft_eval_format(tab, format, i + 1);
		else
		ret += write(1, &format[i], 1);
	}
	va_end(tab->args);
	ret += tab->tl;
	free(tab);
	return (ret);
}

int ft_eval_format(t_print *tab, const char *format, int i)
{
	while (!check_flags(format[i]))
	{
		if (format[i] == '.')
		{
			tab->pnt = 1;
			i++;
		}
		if (format[i] == '-')
		{
			tab->dash = 1;
			i++;
		}
		if (format[i] == '0')
		{
			tab->zero_pdg = 1;
			i++;
		}
		if (format[i] == ' ')
		{
			tab->space_flag = 1;
			i++;
		}
		if (format[i] == '+')
		{
			tab->sign = 1;
			i++;
		}
		if (format[i] == '#')
		{
			tab->hash = 1;
			i++;
		}
	}

	choose_conversion(tab, format, i);
}

void choose_conversion(t_print *tab, const char *format, int i)
{
	if (format[i] == 'c')
		ft_print_char(tab);
	if (format[i] == 'd' || format[i] == 'i')
		ft_print_integer(tab);
	if (format[i] == 'p')
		ft_print_ptr(tab);
	if (format[i] == 's')
		ft_print_str(tab);
	if (format[i] == 'u')
		ft_print_unsigned(tab);
	if (format[i] == 'x')
		ft_print_downhex(tab);
	if (format[i] == 'X')
		ft_print_upperhex(tab);
	if (format[i] == '%')
		ft_print_percent(tab);
}
