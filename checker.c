/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:18:00 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/01 19:15:52 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	chek_a_b(t_stack **a, t_stack **b)
{
	if (ft_is_order(*a) && !*b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

static int	free_all(t_stack **a, t_stack **b, char **line)
{
	free(*line);
	freestack(a);
	freestack(b);
	return (0);
}

int	main(int args, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (args < 2)
		return (0);
	b = NULL;
	a = generate_a(argv);
	if (a)
	{
		line = get_next_line(0);
		while (line)
		{
			if (process_move(&a, &b, line))
				return (free_all(&a, &b, &line));
			free(line);
			line = get_next_line(0);
		}
		chek_a_b(&a, &b);
	}
	else
		ft_putstr_fd("Error\n", 1);
	return (free_all(&a, &b, &line));
}
