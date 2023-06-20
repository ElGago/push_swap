/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:04:43 by jocorrea          #+#    #+#             */
/*   Updated: 2023/06/12 12:46:12 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_chunk_a_to_b(t_stack **a, t_stack **b, int chunk, int size_chunks)
{
    int size;
    t_stack *piv;

    size = ft_stacksize(*a);
    while (*a)
    {
        piv = near_edge(a, chunk, size_chunks);
        if (piv->pos < ft_stacksize(*a) / 2)
            while (*a && (*a)->index > ((size_chunks) * (chunk + 1)))
                if ((*a)->next->index == piv->index)
                    sa(a);
                else
                    ra(a);
        else
            while (*a && (*a)->index > ((size_chunks) * (chunk + 1)))
                rra(a);
        pb(b, a);
        if (ft_stacksize(*b) > 1 && (*b)->index < ((size_chunks) / 2) + ((size_chunks) * chunk))
        {
            if ((ft_stacksize(*a) > 1 && (ft_stacksize(*a) + ((size_chunks) * (chunk + 1))) + 1) == size)
            {
                chunk++;
                piv = near_edge(a, chunk, size_chunks);
            }
            if (ft_stacksize(*a) > 1 && (*a)->index != piv->index && piv->pos < ft_stacksize(*a) / 2)
                rr(a, b);
            else
                rb(b);
        }
        if (((ft_stacksize(*a) + ((size_chunks) * (chunk + 1))) + 1) == size)
            chunk++;
    }
}