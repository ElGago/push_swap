/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:17:48 by jocorrea          #+#    #+#             */
/*   Updated: 2023/05/13 14:30:53 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *simple_sort(char **argv)
{
    t_stack *a;
    //t_stack *b;
    int a_size;
    int first;
    int last;

    a = generate_a(argv);
    //b = NULL;
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
        last = ft_stacklast(a)->value;
        if (first == 2)
        {
            if (last == 3)
            {
                sa(&a);
            }
            else
            {
                rra(&a);
            }
        }        
        if (first == 3)
        {
            if (last == 2)
            {
                ra(&a);
            }
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
    return (a);
} 

t_stack *sort(t_stack *a)
{
    t_stack *b;
    int top;
    int last;
    int next;

    b = ft_stacknew(-1);
    while (!ft_is_sort(*a) && b)
    {
        top = a->value;
        last = ft_stacklast(a)->value;
        next = a->next->value;
        if (top > next && top > last)
        {
            ra(&a);
        }
        if (top > next && top < last)
        {
            sa(&a);
        }
        if(top < next && top < last)
        {
            pb(b,a);
        }
    }
}