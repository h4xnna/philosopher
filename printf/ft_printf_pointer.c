/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:11:15 by hmimouni          #+#    #+#             */
/*   Updated: 2024/12/18 02:22:37 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pointer(unsigned long nb)
{
	char	result[3200];
	int		i;
	int		p;
	int		count;
	int		o;

	count = 0;
	i = 0;
	if (!nb)
		return (write(1, "(nil)", 5), 5);
	while (nb > 0)
	{
		p = nb % 16;
		if (p < 10)
			result[i++] = '0' + p;
		else
			result[i++] = 'a' + (p - 10);
		nb /= 16;
	}
	o = i - 1;
	write(1, "0x", 2);
	while (o >= 0)
		count += write(1, &result[o--], 1);
	return (count + 2);
}
/*int	main(void)
{
	unsigned int nb = 556;
	int a = 556;
	printf("%p\n", (void *)&a);
	ft_printf_pointer((unsigned long)&a);
	return (0);
}*/
