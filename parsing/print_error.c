/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 07:58:22 by hmimouni          #+#    #+#             */
/*   Updated: 2025/05/25 16:09:08 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_error(const char *msg)
{
	write(2, RED, sizeof(RED) - 1);
	write(2, "🚨 ERROR: ", 10);
	while (*msg)
		write(2, msg++, 1);
	write(2, "\n", 1);
	write(2, RESET, sizeof(RESET) - 1);
}

void	final_print(t_data *data)
{
	printf("						\n");
	if (data->someone_died == 0)
		printf("	(☞ﾟヮﾟ)☞ no one died today	\n");
	else
		printf("	¯\\_(ツ)_/¯			\n");
	printf("						\n");
}
