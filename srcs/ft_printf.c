/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:19:03 by kdhrif            #+#    #+#             */
/*   Updated: 2022/08/02 13:05:03 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

t_print	*ft_initialise_tab(t_print *tab, int tl_reset)
{
	tab->maxwidth = 0;
	tab->minwidth = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->already_neg = 0;
	tab->is_ptr = 0;
	if (tl_reset)
		tab->tl = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->space_flag = 0;
	tab->hash = 0;
	tab->is_neg = 0;
	tab->upper = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	long	ret;
	t_print	*tab;

	tab = malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab, 1);
	va_start(tab->args, format);
	i = -1;
	ret = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_eval_format(tab, format, i + 1);
		else
			ret += write(1, &format[i], 1);
	}
	va_end(tab->args);
	ret += tab->tl;
	if (ret > 2147483647 || ret < -2147483648)
		return (-1);
	free(tab);
	return (ret);
}

int	ft_eval_format(t_print *tab, const char *format, int i)
{
	char	nb[12];

	ft_bzero(nb, 11);
	while (!check_flags(format[i]))
	{
		i = ft_printf_checkflags(tab, i, format);
		if (ft_isnum(format[i]))
		{
			if (format[i] == '0' && ft_checkflags_zero(format, i) && i++)
				tab->zero = 1;
			if (!tab->pnt)
				i = ft_printf_checkflagint2(tab, i, nb, format);
			if (format[i] == '.' || tab->pnt)
				i = ft_printf_checkflagint(tab, i, nb, format);
		}
	}
	choose_conversion(tab, format, i);
	return (i);
}

void	choose_conversion(t_print *tab, const char *format, int i)
{
	if (format[i] == 'c')
		ft_print_char(tab);
	if (format[i] == 'd' || format[i] == 'i')
		ft_print_integer(tab);
	if (format[i] == 'p')
		ft_print_ptr(tab);
	if (format[i] == 's')
		ft_printstr(tab);
	if (format[i] == 'u')
		ft_print_uint(tab);
	if (format[i] == 'x')
		ft_print_hex(tab);
	if (format[i] == 'X')
	{
		tab->upper = 1;
		ft_print_hex(tab);
	}
	if (format[i] == '%')
		ft_print_percent(tab);
	ft_initialise_tab(tab, 0);
}

/* #include <stdio.h> */

/* int main() */
/* { */
/* 	int res = 0; */
/* 	int res2 = 0; */
/* 	char* str = NULL; */
/* 	res = ft_printf(" %.1s %.2s %.3s %.4s ", " - ", "", "4", ""); */
/* 	ft_printf("\n"); */
/* 	res2 = printf(" %.1s %.2s %.3s %.4s ", " - ", "", "4", ""); */
/* 	printf("\n"); */
/* 	printf("res = %d, res2 = %d", res, res2); */
/* 	return (0); */
/* } */
