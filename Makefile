# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 11:11:35 by kdhrif            #+#    #+#              #
#    Updated: 2022/07/30 14:10:08 by kdhrif           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF = libftprintf.a
HEADERS = ft_printf.h
CC = gcc -Wall -Wextra -Werror
SRCS = srcs/ft_conversion.c srcs/ft_printf.c srcs/ft_printf_flags.c \
       srcs/ft_printf_percent.c srcs/ft_printf_printchar.c srcs/ft_printf_printhex.c \
       srcs/ft_printf_printint.c srcs/ft_printf_printptr.c srcs/ft_printf_printstr.c \
       srcs/ft_printf_uint.c srcs/ft_printf_utils.c srcs/ft_types.c srcs/ft_reset.c \
       srcs/ft_printint_norm.c srcs/ft_printf_flags2.c srcs/ft_printf_norm.c \
       srcs/ft_printf_flags3.c srcs/ft_printf_utils2.c
OBJ = $(SRCS:%.c=%.o)
OBJF = .cache_exists

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(PRINTF)

$(PRINTF) : $(OBJ)
	ar rcs $(PRINTF) $(OBJ)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

%.o : %.c $(HEADERS)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	$(CC) -o $@ -c $< 

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

clean:
	rm -f srcs/*.o
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean: clean
	rm -f $(PRINTF)
	@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"

.PHONY: re all clean fclean bonus
