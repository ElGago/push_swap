/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_insertion_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:13:28 by jocorrea          #+#    #+#             */
/*   Updated: 2023/05/26 10:52:09 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    printStack_index(t_stack **a)
{
    t_stack *tmp;

    tmp = *a;
    while (tmp)
    {
        printf("(valor:%d, indice:%d), ", peek(tmp), (tmp)->index);
        tmp= (tmp)->next;
    }
    printf("\n");
}

int    chunks_insertion_sort(t_stack **a, t_stack **b)
{
    int chunks;
    int s_chunks;
    int i;
    int size;
    int mov;


    size = ft_stacksize(*a);
    mov =0;
    chunks = 8;
    if (size >= 6 && size <=20)
        chunks = 2;
    if (size >20 && size <=150)
        chunks = 5;
    s_chunks = size / chunks;
    i = 0;
    while (*a)
    {
        while (*a && (*a)->index > (s_chunks * (i + 1)))
        {
            ra(a);
            mov++;
        }
        pb(b,a);
        mov++;
        if (((ft_stacksize(*a) + (s_chunks * (i + 1))) + 1) == size)
            i++;
    }
    while (*b)
    {
        i = stackMax(*b);
        while (peek(*b) != i)
        {
            rb(b);
            mov++;
        }
        pa(a,b);
        mov++;
    }
    return mov;
}