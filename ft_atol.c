/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:24:15 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/09 12:24:23 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int					i;
	int					sig;
	unsigned long long	res;

	i = 0;
	res = 0;
	sig = 1;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		if (res > __LONG_LONG_MAX__ && sig == 1)
			return (0);
		if (res > __LONG_LONG_MAX__ && sig == -1)
			return (-1);
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * sig);
}
