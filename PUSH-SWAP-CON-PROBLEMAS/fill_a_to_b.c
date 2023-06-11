/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:09:48 by jocorrea          #+#    #+#             */
/*   Updated: 2023/06/11 20:31:00 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void try_a_to_b(t_stack **a, t_stack *piv, int chunk, int size_chunks)
{
	if (piv->pos < ft_stacksize(*a) / 2)
	{
		while (*a && (*a)->index > (size_chunks * (chunk + 1)))
		{
			if ((*a)->next->index == piv->index)
				sa(a);
			else
				ra(a);
		}
	}
	else
		while (*a && (*a)->index > size_chunks * (chunk + 1))
		{
			rra(a);
		}
}

void fill_chunk_a_to_b(t_stack **a, t_stack **b, int chunk, int size_chunks)
{
	int size;
	t_stack *piv;
	int index;

	size = ft_stacksize(*a);
	index = size_chunks * (chunk + 1);
	while (*a)
	{
		piv = near_edge(a, chunk, size_chunks);
		try_a_to_b(a, piv, chunk, size_chunks);
		pb(b, a);
		if (ft_stacksize(*b) > 1 && (*b)->index < ((size_chunks) / 2) +
													  ((size_chunks)*chunk))
		{
			if (ft_stacksize(*a) > 1 && (ft_stacksize(*a) + index + 1) == size)
				piv = near_edge(a, chunk++, size_chunks);
			if (ft_stacksize(*a) > 1 && (*a)->index != piv->index &&
				piv->pos < ft_stacksize(*a) / 2)
				rr(a, b);
			else
				rb(b);
		}
		if ((ft_stacksize(*a) + index + 1) == size)
			chunk++;
	}
}
