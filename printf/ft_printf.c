/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:47:32 by hmimouni          #+#    #+#             */
/*   Updated: 2024/12/18 04:22:30 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sub(const char *s, va_list args, int i)
{
	if (s[i + 1] == 'd' || s[i + 1] == 'i')
		return (ft_printf_nbr(va_arg(args, int)));
	else if (s[i + 1] == 'c')
		return (ft_printf_char(va_arg(args, int)));
	else if (s[i + 1] == 'p')
		return (ft_printf_pointer(va_arg(args, unsigned long)));
	else if (s[i + 1] == 'x')
		return (ft_printf_hexa_min(va_arg(args, unsigned int)));
	else if (s[i + 1] == 'X')
		return (ft_printf_hexa_max(va_arg(args, unsigned int)));
	else if (s[i + 1] == 'u')
		return (ft_printf_unsigned(va_arg(args, unsigned int)));
	else if (s[i + 1] == 's')
		return (ft_printf_string(va_arg(args, char *)));
	else if (s[i + 1] == '%')
		return (write(1, &s[i + 1], 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!s)
		return (-1);
	va_start(args, s);
	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] == '%')
			count += ft_sub(&s[i++], args, 0);
		else
		{
			ft_printf_char(s[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}

// // int	main(void)
// {
// 	int	a;

// 	a = 55;
// 	printf("%d\n", ft_printf("%s"));
// 	printf("%d", printf(" %d %d\n", -12, -57));

// }
/*
{
	int	k;
	int	h;

	k = 0;
	h = 0;
	k = printf(" %s ", "48B");
	h = ft_printf(" %s ", "48B");
	printf("%i, %i", k, h);
	return (0);
}*/
// my_print = printf(" %d %s", 123, "salut")
// int	main(void)
// {
// 	int i = 0;
// 	int j = 0;

// 	i = printf("%s", "ethan");
//     printf("\n");
// 	j = ft_printf("%s", "ethan");
// 	printf("\n%d, %d", i, j);
// 	return (0);
// }