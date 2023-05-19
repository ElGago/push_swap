/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:17:48 by jocorrea          #+#    #+#             */
/*   Updated: 2023/05/18 12:42:50 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *simple_sort(char **argv)
{
    t_stack *a;
    t_stack *b;
    int a_size;
    int first;
    int last;

    a = generate_a(argv);
    b = NULL;
    a_size = ft_stacksize(a);
    if (a_size <= 1 || ft_is_order(a))
        return (a);
    if (a_size == 2)
    {
        sa(&a);
        return (a);
    }
    if (a_size == 3)
    {   
        first =  a->value;
        last = ft_stacklast(&a)->value;
        if (first == 2)
        {
            if (last == 3)
                sa(&a);
            else
                rra(&a);
        }        
        if (first == 3)
        {
            if (last == 2)
                ra(&a);
            else
            {
                sa(&a);
                rra(&a);
            }
        }
        if (first == 1 && last == 2)
        {
            ra(&a);
            sa(&a);
            rra(&a);
        }
    }
    if (a_size > 3)
         last = newsort(&a, &b);
    printf("la cantidad de movimientos es: %d\n", last);
    return (b);
} 

 int ft_Stack_sort(t_stack **a, t_stack **b)
{
    int top;
    int last;
    int next;
    int mov;

    mov = 0;
    if (ft_is_order(*a))
    { 
            if(isEmpty(*b))
                return mov;
            else
            {
                pa(a, b);
                mov++;
            }
    }
    else
    {
        top = (*a)->value;
        last = ft_stacklast(a)->value;
        next = (*a)->next->value; 
        if (top > last)
        {
            ra(a);
            mov++;
        }
        else
        { 
            if (top > next)
            { 
                sa(a);
                mov++;
            }
            else
            {
                if (top < next && top < last && !isEmpty(*b))
                {
                    pb(b, a);
                    mov++;
                }
            }
        }
    }
    return mov+ft_Stack_sort(a, b);
}

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

