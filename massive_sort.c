/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   massive_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:47:22 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/01 12:44:24 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_a_mov_update(t_stack **a, t_stack **b, int *down)
{
	if (*b)
	{
		while ((*a)->index \
				> ft_stacklast(*a)->index && ft_stacklast(*a)->index \
				> stackmax(*b)->index)
		{
			rra(a);
			(*down)--;
		}
	}
	else
	{
		while ((*a)->index > ft_stacklast(*a)->index)
		{
			rra(a);
			(*down)--;
		}
	}
}

void	b_position(t_stack **a, t_stack **b, int *down)
{
	t_stack	*max;
	int		size;

	max = stackmax(*b);
	while ((*b)->index != max->index)
	{
		size = ft_stacksize(*b);
		if (*down == 0 || *a == NULL || (*b)->index > ft_stacklast(*a)->index)
		{
			pa(a, b);
			ra(a);
			(*down)++;
		}
		else if ((*b)->next->index == max->index)
			sb(b);
		else if (max->pos > size / 2)
			rrb(b);
		else
			rb(b);
	}
}

void	try_b_to_a(t_stack **a, t_stack **b)
{
	int	down;

	down = 0;
	while (*b)
	{
		b_position(a, b, &down);
		pa(a, b);
		last_a_mov_update(a, b, &down);
	}
}

void	insertion_chunks_sort(t_stack **a, t_stack **b)
{
	int	max_chunks;
	int	index_chunk;
	int	size;

	size = ft_stacksize(*a);
	index_chunk = 0;
	max_chunks = 8;
	if (size >= 6 && size <= 20)
		max_chunks = 2;
	if (size > 20 && size <= 150)
		max_chunks = 4;
	fill_chunk_a_to_b(a, b, index_chunk, (size / max_chunks));
	try_b_to_a(a, b);
}
