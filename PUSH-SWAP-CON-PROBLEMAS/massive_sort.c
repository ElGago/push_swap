/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   massive_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:47:22 by jocorrea          #+#    #+#             */
/*   Updated: 2023/06/11 20:14:39 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prepare_b_to_a(t_stack **a, t_stack **b, int down, t_stack *max)
{
	int	size;

	size = ft_stacksize(*b);
	if (down == 0 || *a == NULL || (*b)->index > ft_stacklast(*a)->index)
	{
		pa(a, b);
		ra(a);
		down++;
	}
	else if ((*b)->next->index == max->index)
		sb(b);
	else if (max->pos > size / 2)
		rrb(b);
	else
		rb(b);
	return (down);
}

void	try_b_to_a(t_stack **a, t_stack **b, t_stack *max, int down)
{
	down = 0;
	while (*b)
	{
		max = stackmax(*b);
		while ((*b)->index != max->index)
			down = prepare_b_to_a(a, b, down, max);
		pa(a, b);
		if (*b)
		{
			while ((*a)->index > ft_stacklast(*a)->index && \
					ft_stacklast(*a)->index > stackmax(*b)->index)
			{
				rra(a);
				down--;
			}
		}
		else
		{
			while ((*a)->index > ft_stacklast(*a)->index)
			{
				rra(a);
				down--;
			}
		}
	}
}

void	insertion_chunks_sort(t_stack **a, t_stack **b)
{
	int		max_chunks;
	int		index_chunk;
	int		size;
	t_stack	*max;

	size = ft_stacksize(*a);
	index_chunk = 0;
	max_chunks = 8;
	max = NULL;
	if (size >= 6 && size <= 20)
		max_chunks = 2;
	if (size > 20 && size <= 150)
		max_chunks = 4;
	fill_chunk_a_to_b(a, b, index_chunk, (size / max_chunks));
	try_b_to_a(a, b, max, size);
}
