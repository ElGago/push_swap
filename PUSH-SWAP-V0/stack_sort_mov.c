/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_mov.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:08:18 by jocorrea          #+#    #+#             */
/*   Updated: 2023/06/07 10:27:53 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void    try_prepare_fill_b(t_stack  **a, int chunk, int size_chunks, t_stack *piv)
{
    if (piv->pos < ft_stacksize(*a) / 2)
            while (*a && (*a)->index > ((size_chunks) * (chunk + 1)))
                if ((*a)->next->index == piv->index)
                    sa(a);
                else
                    ra(a);
        else
            while (*a && (*a)->index > ((size_chunks) * (chunk + 1)))
                rra(a);
}

void fill_chunk_a_to_b(t_stack **a, t_stack **b, int chunk, int size_chunks)
{
    int size;
    t_stack *piv;

    size = ft_stacksize(*a);
    while (*a)
    {
        piv = near_edge(a, chunk, size_chunks);
        try_prepare_fill_b(a, chunk, size_chunks, piv);
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

void try_b_to_a(t_stack **a, t_stack **b)
{
    t_stack *max;
    int size;
    
    while (*b)
    {
        max = stackMax(*b);
        while ((*b)->index != max->index)
        {   
            size = ft_stacksize(*b);
            if ((*b)->next->index == max->index)
               sb(b);
            else if (max->pos > size / 2)
                    rrb(b);
                else
                    rb(b);
        }
        pa(a, b);
    }
}


void    try_fill_b_a_(t_stack **a, t_stack **b, int down)
{
    t_stack *max;
    int     size;

    max = stackMax(*b);
        while ((*b)->index != max->index)
        {   
            size = ft_stacksize(*b);
            if (down == 0 || *a == NULL || (*b)->index > ft_stacklast(*a)->index)
            {//esto se hace para aprobechar el final de la pila a
                pa(a,b);
                ra(a);
                down++;
            }//intento flotar hacia arriba el maxmo de b
            else if ((*b)->next->index == max->index)
                    sb(b);
            else if (max->pos > size / 2)
                    rrb(b);
                else
                    rb(b);
        }
}

void try_b_to_a(t_stack **a, t_stack **b)
{
    int down;
    
    down = 0;
    while (*b)
    {
        try_fill_b_a_(a, b, down);
        pa(a, b);
        //si el ultimo de a es mayo que el maximo de b lo muevo a su pos
        if (*b)
            while ((*a)->index > ft_stacklast(*a)->index && ft_stacklast(*a)->index > stackMax(*b)->index)
            {
                rra(a);
                down--;
            }
        else//si ya be esta vacio entonces chequear que los ultimos de a no sean menores que el primero de a
            while ((*a)->index > ft_stacklast(*a)->index)
            {
                rra(a);
                down--;
            }
    }
}*/