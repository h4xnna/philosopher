/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:03:06 by hmimouni          #+#    #+#             */
/*   Updated: 2024/12/18 04:15:48 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf.h"
# include "printf.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf_string(char *s);
int		ft_printf_char(char c);
int		ft_printf_nbr(int nb);
int		ft_printf_char(char c);
int		ft_printf(const char *s, ...);
int		ft_printf_hexa_max(unsigned int nb);
int		ft_printf_hexa_min(unsigned int nb);
int		ft_printf_pointer(unsigned long nb);
int		ft_printf_unsigned(unsigned int nb);
int		ft_sub(const char *s, va_list args, int i);
void	ft_nbr(unsigned int nb);

#endif
