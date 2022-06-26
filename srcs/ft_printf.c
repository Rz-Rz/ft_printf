/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:19:03 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/26 18:50:42 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"

t_print *ft_initialise_tab(t_print *tab)
{
		tab->maxwidth = 0;
		tab->minwidth = 0;
		tab->precision = 0;
		tab->zero = 0;
		tab->pnt = 0;
		tab->sign = 0;
		tab->tl = 0;
		tab->is_zero = 0;
		tab->dash = 0;
		tab->space_flag = 0;
		tab->hash = 0;
		tab->is_neg = 0;
		tab->upper = 0;
		return (tab);
}

int ft_printf(const char *format, ...)
{
		int i;
		long ret;
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
		if (ret > 2147483647 || ret < -2147483648)
				return (-1);
		free(tab);
		return (ret);
}

int ft_eval_format(t_print *tab, const char *format, int i)
{
		char nb[12];
		int j;

		ft_bzero(nb, 11);
		j = 0;
		while (!check_flags(format[i]))
		{
			if (format[i] == '.' && i++)
				tab->pnt = 1;
			if (ft_isnum(format[i]))
			{
				if (format[i] == '0' && format[i - 1] == '%' && i++)
					tab->zero = 1;
				if (!tab->pnt)
				{
					while(ft_isnum(format[i]))
					{
						nb[j] = format[i];
						i++ && j++;
					}
					tab->maxwidth = ft_atoi(nb);
				}
				if (format[i] == '.' || tab->pnt)
				{
					j = 0;
					ft_bzero(nb, 11);
					while(ft_isnum(format[i]))
					{
						/* while (format[i] == '0') */
						/* 	i++; */
						/* if (!ft_isnum(format[i])) */
						/* 	break; */
						nb[j] = format[i];
						i++ && j++;
					}
					tab->minwidth = ft_atoi(nb);
				}
			}
			if (format[i] == '-')
			{
				tab->dash = 1;
				i++;
			}
			if (format[i] == '0')
			{
				tab->zero = 1;
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
		return (i);
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
			ft_printstr(tab);
		if (format[i] == 'u')
			ft_print_uint(tab);
		if (format[i] == 'x')
			ft_print_downhex(tab);
		if (format[i] == 'X')
			ft_print_upperhex(tab);
		if (format[i] == '%')
			ft_print_percent(tab);
}

#include <stdio.h>

int main()
{
		int res = 0;
		int res2 = 0;
		unsigned int a = 0;
		/* char *str = "Hello World!"; */
		/* printf("x%5dx", 10); */
		/* printf("\n"); */
		/* printf("x%5dx", 123456789); */
		/* printf("\n"); */
		/* printf("x%-5dxc", 10); */
		/* printf("\n"); */
		/* printf("x%-5dx", 123456789); */
		/* printf("\n"); */
		/* printf("%d", 123456789); */
		/* printf("\n"); */
		/* printf("%d", 10); */
		/* printf("%10s", "Hello"); */
		res = ft_printf("%x\n", a);
		res2 = printf("%x\n", a);

		printf("res = %d, res2 = %d", res, res2);
		return (0);
}
