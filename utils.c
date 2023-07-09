/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:57:49 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/09 15:00:42 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stackmax(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (max->index < stack->index)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*stackmin(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (min->index > stack->index)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	index_stack(t_stack **a)
{
	int		ix;
	int		size;
	t_stack	*tmp;
	t_stack	*pivot;

	pivot = *a;
	size = ft_stacksize(*a);
	while (size-- > 0)
	{
		ix = 0;
		tmp = *a;
		while (tmp)
		{
			if (pivot->value > tmp->value)
				ix++;
			tmp = tmp->next;
		}
		pivot->index = ix;
		pivot = pivot->next;
	}
}

void	ft_update_pos(t_stack **a)
{
	int		i;
	t_stack	*tmp;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		tmp->pos = i++;
		tmp = tmp->next;
	}
}
