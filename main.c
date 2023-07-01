/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:20:44 by marvin            #+#    #+#             */
/*   Updated: 2023/07/01 12:18:27 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int args, char **argv)
{
	t_stack	*top;
	t_stack	*tmp;

	(void)args;
	if (args < 2)
		return (0);
	top = generate_a(argv);
	tmp = NULL;
	if (!top)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	sort(&top, &tmp);
	freestack(&top);
	freestack(&tmp);
	return (0);
}
