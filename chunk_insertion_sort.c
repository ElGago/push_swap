/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_insertion_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:13:28 by jocorrea          #+#    #+#             */
/*   Updated: 2023/06/02 12:50:23 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *hold_stack(t_stack **a, int s_chunk, int i)
{
    t_stack *up;
    t_stack *down;
    t_stack *tmp;

    tmp = *a;
    while (tmp && tmp->index > (s_chunk * (i + 1)) && tmp->pos < ft_stacksize(*a) / 2)
        tmp = tmp->next;
    up = tmp;
    down = up;
    while (tmp)
    {
        if (tmp->index < (s_chunk * (i + 1)) && tmp->pos >= ft_stacksize(*a) / 2)
            down = tmp;
        tmp = tmp->next;
    }
    if (up->pos < ft_stacksize(*a) - down->pos)
        return (up);
    return (down);
}

int try_a_to_b(t_stack **a, t_stack **b, int size, int chunks)
{
    int i;
    int mov;
    t_stack *hold;

    mov = 0;
    i = 0;
    while (*a)
    {
        hold = hold_stack(a, (size / chunks), i);
        if (hold->pos < ft_stacksize(*a) / 2)
        {
            while (*a && (*a)->index > ((size / chunks) * (i + 1)))
            {
                if (ft_stacksize(*b) > 1 && (*b)->index > (hold)->index)
                    rr(a,b);
                else
                    ra(a);
                mov++;
            }
        }
        else
            while (*a && (*a)->index > ((size / chunks) * (i + 1)))
            {
                rra(a);
                mov++;
            }
        pb(b, a);
        mov++;
        if (ft_stacksize(*b) > 1 && (*b)->index <= ((size / chunks) / 2) + ((size / chunks) * i))
        {
            if (ft_stacksize(*a) > 1 && (*a)->index > (size / chunks) * (i + 1))
                rr(a,b);
            else
                rb(b);
            mov++;
        }
        if (((ft_stacksize(*a) + ((size / chunks) * (i + 1))) + 1) == size)
            i++;
    }
    return (mov);
}

int try_b_to_a(t_stack **a, t_stack **b, int size)
{
    int mov;

    mov = 0;
    while (*b)
    {
        while ((*b)->index != stackMax(*b))
        {   
            size = ft_stacksize(*b);
            if ((*b)->next->index == stackMax(*b))
               sb(b);
            else if (stackMax(*b) > size / 2)
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

int chunks_insertion_sort(t_stack **a, t_stack **b)
{
    int chunks;
    int size;
    int mov;

    size = ft_stacksize(*a);
    mov = 0;
    chunks = 8;
    if (size >= 6 && size <= 20)
        chunks = 2;
    if (size > 20 && size <= 150)
        chunks = 7;
    mov = try_a_to_b(a,b,size,chunks);
    mov += try_b_to_a(a, b, size);
    printf("chunks = %d, s_chunks = %d\n", chunks, ft_stacksize(*a)/chunks);
    return mov;
}