/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:31:59 by kdhrif            #+#    #+#             */
/*   Updated: 2022/05/31 17:11:03 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct s_print
{
	va_list args;
	int width;
	int precision;
	int zero_pdg;
	int pnt;
	int dash;
	int tl;
	int sign;
	int is_zero;
	int perc;
	int space_flag;
	int hash;
	
} t_print;



int ft_printf(const char *format, ...);

int ft_eval_format(t_print *tab, const char *format, int i);

void choose_conversion(t_print *tab, const char *format, int i);

int check_flags(char c);
