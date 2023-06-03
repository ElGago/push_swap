/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:46:32 by jocorrea          #+#    #+#             */
/*   Updated: 2023/06/02 12:46:05 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int sort_10(t_stack **a, t_stack **b)
{
    int size;
    int mov;

    size = ft_stacksize(*a);
    mov = 0;
    while (!ft_is_order(*a) || size > ft_stacksize(*a))
        if (ft_is_order(*a))
        {
            pa(a, b);
            mov++;
        }
        else
        {
            if ((*a)->value > (*a)->next->value)
            {
                    sa(a);
                    mov++;
            }
            else if ((*a)->value < (*a)->next->value)
            {
                if ((*a)->value > ft_stacklast(*a)->value)
                {
                    rra(a);
                    mov++;
                }
                else
                {
                    pb(b, a);
                    mov++;
                }
                if (*b && ft_stacksize(*b) >= 2)
                {
                    if ((*b)->value < ft_stacklast(*b)->value)
                    {
                        rb(b);
                        mov++;
                    }
                    else if ((*b)->value < (*b)->next->value)
                    {
                        sb(b);
                        mov++;
                    }
                }
            }
        }  
            return mov;    
}

int    newsort(t_stack **a, t_stack **b)
{  
    
    int mov;

    mov = 0;
    while ((*a))
    {
        while ((*b) && (*b)->value < (*a)->value)
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

int    insertion_sort(t_stack **a, t_stack **b)
{
    int     min;
    t_stack *tmp;
    int mov;

    tmp = *a;
    min = stackMin(*a)->index;
    mov = 0;
    while (tmp && !ft_is_order(*a))
    {       
        if ((tmp)->index != min)
        {
            tmp = tmp->next;
            ra(a);
            mov++;
        }
        else 
        {
            pb(b,a);
            mov++;
            tmp = *a;
            min = stackMin(*a)->index;
        }
    }
    while((*b))
    {
        pa(a,b);
        mov++;
    }
    return mov;
}

t_stack *simple_sort(t_stack **a, t_stack **b)
{
    int a_size;
   // t_stack **tmp;
    
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
    if (a_size == 4)
        caso4(a,b);
    if (a_size == 5)
        caso5(a,b); 
    if (a_size >= 6 && a_size < 20)
    {
        //pb(b,a);
        //caso5(a,b);
       // pa(a,b);
        printf("mov = %d\n",sort_10(a, b));
    }
    if(a_size >= 20 && a_size < 50)
        printf("mov = %d\n",newsort(a,b));
    if(a_size >= 50 && a_size < 100)
        printf("mov = %d\n",sort_10(a,b));
    /*
    if (a_size > 6)
    {
        tmp = a;
        printf("movimientos de sort_10:%d\n", sort_10(tmp, b));
        tmp = a;
        printf("movimientos de new_sort:%d\n", newsort(tmp, b));
        //tmp = a;
        //printf("movimientos de insertion_sort:%d\n", insertion_sort(tmp, b));
        tmp = a;
        printf("movimientos de chunks_insertion_sort:%d\n", chunks_insertion_sort(tmp, b));
    }*/
    return (*a);
}
