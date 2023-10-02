/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:08:27 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/22 10:54:54 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_print_c(int c);
int	ft_print_s(char *s);
int	ft_print_d_i(int nb);
int	ft_print_u(unsigned int nb);
int	ft_print_hexa(unsigned int nb, char format);
int	ft_print_p(unsigned long long ptr);

#endif
