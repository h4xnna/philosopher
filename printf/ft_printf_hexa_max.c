/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_maj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:23:47 by hmimouni          #+#    #+#             */
/*   Updated: 2024/12/18 03:06:36 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexa_max(unsigned int nb)
{
	char	result[3200];
	int		i;
	int		p;
	int		count;
	int		o;

	count = 0;
	i = 0;
	if (nb == 0)
		return (write(1, "0", 1), 1);
	while (nb > 0)
	{
		p = nb % 16;
		if (p < 10)
			result[i++] = '0' + p;
		else
			result[i++] = 'A' + (p - 10);
		nb /= 16;
	}
	o = i;
	while (--o >= 0)
		count += write(1, &result[o], 1);
	return (count);
}

// int	main(void)
// {
// 	unsigned int nb = 255;
// 	printf("%X\n", 255);
// 	ft_printf_hexa_maj(nb);
// 	return (0);
// }