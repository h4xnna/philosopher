/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 04:15:14 by hmimouni          #+#    #+#             */
/*   Updated: 2024/12/18 04:15:15 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_nbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += ft_printf_string("-2147483648");
		return (11);
	}
	if (nb < 0)
	{
		nb *= -1;
		count += write(1, "-", 1);
	}
	if (nb > 9)
		count += ft_printf_nbr(nb / 10);
	count += write(1, &"0123456789"[nb % 10], 1);
	return (count);
}
