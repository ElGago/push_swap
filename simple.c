/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:17:48 by jocorrea          #+#    #+#             */
/*   Updated: 2023/05/26 11:03:28 by jocorrea         ###   ########.fr       */
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

int sort_10(t_stack **a, t_stack **b)
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
            if (peek(*a) > (*a)->next->value)
            {
                    sa(a);
                    mov++;
            }
            else if (peek(*a) < (*a)->next->value)
            {
                if (peek(*a) > ft_stacklast(*a)->value)
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
                    if (peek(*b) < ft_stacklast(*b)->value)
                    {
                        rb(b);
                        mov++;
                    }
                    else if (peek(*b) < (*b)->next->value)
                    {
                        sb(b);
                        mov++;
                    }
                }
            }
        }  
            return mov;    
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
void    caso4(t_stack **a, t_stack **b)
{
    pb(b,a);
    caso3(a);
    if (peek(*b) < peek(*a))
        pa(a,b);
    else if  (peek(*b) > ft_stacklast(*a)->value)
    {
        pa(a,b);
        ra(a);
    }
    else if (peek(*b) > (*a)->next->value)
    {
        rra(a);
        pa(a, b);
        ra(a);
        ra(a);
    }
}

void    caso5(t_stack **a, t_stack **b)
{
    pb(b, a);
    caso4(a,b);
    if (peek(*b) < peek(*a))
        pa(a, b);
    else if (peek(*b) > ft_stacklast(*a)->value)
    {
        pa(a,b);
        ra(a);
    }
    else if (peek(*b) < (*a)->next->value)
    {
        pa(a, b);
        sa(a);
    }
    else if (peek(*b) < (*a)->next->next->value)
    {
        ra(a);
        ra(a);
        pa(a,b);
        rra(a);
        rra(a);
    }
    else
    {
        rra(a);
        pa(a,b);
        ra(a);
        ra(a);
    }
}
int    insertion_sort(t_stack **a, t_stack **b)
{
    int     min;
    t_stack *tmp;
    int mov;

    tmp = *a;
    min = stackMin(*a);
    mov = 0;
    while (tmp && !ft_is_order(*a))
    {       
        if (peek(tmp) != min)
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
            min = stackMin(*a);
        }
    }
    while(!isEmpty(*b))
    {
        pa(a,b);
        mov++;
    }
    return mov;
}

t_stack *simple_sort(t_stack **a, t_stack **b)
{
    int a_size;
    t_stack **tmp;
    
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
    if (a_size == 6)
    {
        pb(b,a);
        caso5(a,b);
        pa(a,b);
        sort_10(a, b);
    }
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
    }
    return (*a);
}
