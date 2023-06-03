/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   massive_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:47:22 by jocorrea          #+#    #+#             */
/*   Updated: 2023/06/02 12:51:33 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *near_edge(t_stack **a, int chunk, int s_chunk)
{
    t_stack *up;
    t_stack *down;
    t_stack *tmp;

    up = NULL;
    down = NULL;
    if (a && *a && ft_stacksize(*a) > 1)
    {
        tmp = *a;
        while (tmp && tmp->index > (s_chunk * (chunk + 1)) && tmp->pos <= ft_stacksize(*a) / 2)
            tmp = tmp->next;
        if (tmp->pos <= ft_stacksize(*a) / 2)
            up = tmp;
        while (tmp)
        {
            if (tmp->index < (s_chunk * (chunk + 1)) && tmp->pos > ft_stacksize(*a) / 2)
                down = tmp;
            tmp = tmp->next;
        }
    }
    else
    {
        if (!a)
            return (NULL);
        return (*a);
    }
    if (!up)
        return (down);
    if (!down)
        return (up);
    if (up->pos <= ft_stacksize(*a) - down->pos)
        return (up);
    return (down);
}

int fill_chunk_a_to_b(t_stack **a, t_stack **b, int chunk, int size_chunks)
{
    int mov;
    int size;
    t_stack *piv;

    mov = 0;
    size = ft_stacksize(*a);
    while (*a)
    {
        piv = near_edge(a, chunk, size_chunks);
        if (piv->pos <= ft_stacksize(*a) / 2)
            while ((*a)->index != piv->index)
            {
                ra(a);
                mov++;
            }
        else
            while ((*a)->index != piv->index)
            {
                rra(a);
                mov++;
            }
        pb(b, a);
        mov++;
        if (ft_stacksize(*b) > 1 && (*b)->index <= ((size_chunks) / 2) + ((size_chunks)*chunk))
        {
            piv = near_edge(a, chunk, size_chunks);
            if (piv && (*a)->index != piv->index && piv->pos <= ft_stacksize(*a) / 2)
                rr(a, b);
            else
                rb(b);
            mov++;
        }
        if (((ft_stacksize(*a) + ((size_chunks) * (chunk + 1))) + 1) == size)
            chunk++;
    }
    return (mov);
}

int try_b_to_a(t_stack **a, t_stack **b)
{
    int mov;
    t_stack *max;
    int size;

    mov = 0;
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
            mov++;
        }
        pa(a, b);
        mov++;
    }
    return (mov);
}

int insertion_chunks_sort(t_stack **a, t_stack **b)
{
    int max_chunks;
    int index_chunk;
    int mov;
    int size;

    size = ft_stacksize(*a);
    index_chunk = 0;
    mov = 0;
    max_chunks = 8;
    if (size >= 6 && size <= 20)
        max_chunks = 2;
    if (size > 20 && size <= 150)
        max_chunks = 5;
    mov += fill_chunk_a_to_b(a, b, index_chunk++, (size / max_chunks));
    mov += try_b_to_a(a, b);
    return (mov);
}