/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:17:48 by jocorrea          #+#    #+#             */
/*   Updated: 2023/05/20 17:53:44 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    newsort(t_stack **a, t_stack **b)
{  
    
    int mov;

    mov = 0;
    while (!isEmpty(*a))
    {
        while (!isEmpty(*b) && peek(*b) < peek(*a))
        {
            pa(a,b);
            sa(a);
            mov++;
            mov++;
        }
        pb(b,a);
        mov++;
    }
    return (mov);
}

int sort_10(t_stack **a)
{
    int pivote;
    int size;
    int last;
    int next;
    int mov;
    t_stack *b;

    b = NULL;
    mov = 0;
    size = ft_stacksize(*a);
    while (!ft_is_order(*a) || size > ft_stacksize(*a))
    {
        if (ft_is_order(*a))
        {
            pa(a, &b);
            mov++;
        }
        else
        {
            pivote = peek(*a);
            last = ft_stacklast(*a)->value;
            next = (*a)->next->value;
            if (pivote > next)
            {
               // if (pivote > last)
               /* { 
                    printf("Caso nuevo entro\n");
                    rra(a);
                    sa(a);
                    ra(a);
                    mov += 3;*/
             //   }
             //   else
             //   {
                    sa(a);
                    mov++;
              //  }
            }
            else if (pivote < next)
            {
                if (pivote > last)
                {
                    rra(a);
                    mov++;
                }
                else
                {
                    pb(&b, a);
                }
                if (ft_stacksize(b) >= 2)
                {
                    pivote = peek(b);
                    next = b->next->value;
                    last = ft_stacklast(b)->value;
                    if (pivote < last)
                    {
                        rb(&b);
                        mov++;
                    }
                    else if (pivote < next)
                    {
                        sb(&b);
                        mov++;
                    }
                }
            }
        }
    }
    return (mov);
}

void caso3(t_stack **a)
{
    int first;
    int last;
    int next;
    
    first = peek(*a);
    last = ft_stacklast(*a)->value;
    next = (*a)->next->value;
    if (first > next && first < last)
        sa(a);
    else if (first < next && first > last)
        rra(a);
    else if (first > next && first > last)
    {
        ra(a);
        if (next > last)
            sa(a);
    }
    else if (first < next && next > last)
    {
        sa(a);
        ra(a);
    }
}

t_stack *simple_sort(t_stack **a)
{
    int a_size;
    t_stack *b;

    b = NULL;
    a_size = ft_stacksize(*a);
    if (a_size <= 1 || ft_is_order(*a))
        return (*a);
    if (a_size == 2)
    {
        sa(a);
        return (*a);
    }
    if (a_size == 3)
        caso3(a);
    if (a_size > 3)
        // sort_10(a);
        printf("son %d movimientos\n", sort_10(a));
       
    return (*a);
}
