/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:17:34 by jocorrea          #+#    #+#             */
/*   Updated: 2023/06/01 11:19:09 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		reverseRotate(t_stack **stack)
{
    t_stack *last;
    t_stack *pre;

    last = *stack;
    while (last && (last)->next)
    {
        pre = last;
		last = (last)->next;
    }
    pre->next = NULL;
    if (last != NULL)
        push(stack, last);
}

void    rra(t_stack **stack_a)
{
    reverseRotate(stack_a);
    ft_putstr_fd("rra\n",1);
}

void    rrb(t_stack **stack_b)
{
    reverseRotate(stack_b);
    ft_putstr_fd("rrb\n",1);
}

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    reverseRotate(stack_a);
    reverseRotate(stack_b);
    ft_putstr_fd("rrr",1);
}