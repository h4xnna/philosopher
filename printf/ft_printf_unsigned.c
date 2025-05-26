/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:24:14 by hmimouni          #+#    #+#             */
/*   Updated: 2024/12/18 02:26:12 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_printf_unsigned(unsigned int nb)
{
	int				i;
	unsigned int	temp;

	temp = nb;
	i = 0;
	if (nb == 0)
	{
		ft_putchar_fd(48, 1);
		return (1);
	}
	while (temp > 0)
	{
		temp = temp / 10;
		i++;
	}
	ft_nbr(nb);
	return (i);
}

void	ft_nbr(unsigned int nb)
{
	if (nb >= 10)
		ft_nbr(nb / 10);
	ft_putchar_fd((nb % 10) + 48, 1);
}

/*int	main(void)
{
	unsigned int	num;
	int				longueur;

	num = 12345;
	longueur = ft_printf_unsigned(num);
	printf(" %d\n", longueur);
	return (0);
}*/
