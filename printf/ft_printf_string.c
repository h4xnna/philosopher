/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:14:14 by hmimouni          #+#    #+#             */
/*   Updated: 2024/12/18 04:13:51 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_string(char *s)
{
	int		i;
	int		count;
	char	*empty;

	i = 0;
	count = 0;
	empty = "(null)";
	if (!s)
	{
		while (empty[i])
			ft_printf_char(empty[i++]);
		return (6);
	}
	else
		while (s[i])
			count += ft_printf_char(s[i++]);
	return (count);
}
