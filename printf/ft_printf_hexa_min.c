/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_min.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:11:51 by hmimouni          #+#    #+#             */
/*   Updated: 2024/12/18 04:14:47 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexa_min(unsigned int nb)
{
	char	result[3200];
	int		i;
	int		p;
	int		count;
	int		o;

	count = 0;
	i = 0;
	if (nb == 0)
		count += write(1, "0", 1);
	while (nb > 0)
	{
		p = nb % 16;
		if (p < 10)
			result[i++] = '0' + p;
		else
			result[i++] = 'a' + (p - 10);
		nb /= 16;
	}
	o = i;
	while (--o >= 0)
		count += write(1, &result[o], 1);
	return (count);
}
