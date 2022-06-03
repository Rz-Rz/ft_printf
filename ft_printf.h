/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:31:59 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/03 16:55:02 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_struct {
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
