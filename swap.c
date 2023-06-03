/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:12:42 by marvin            #+#    #+#             */
/*   Updated: 2023/04/11 10:12:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    swap(t_stack **a)
{
    t_stack  *tmp;

    if (*a != NULL && (*a)->next != NULL)
    {
        tmp = *a;
        *a = (*a)->next;
        tmp->next = (*a)->next;
        (*a)->next = tmp;
    }
    ft_update_pos(a);  
}

void    push_stack(t_stack **stack_to, t_stack **stack_from)
{
    t_stack *b;

    b = pop(stack_from);
    if (b)
        push(stack_to, b);
}

void		rotate(t_stack **stack)
{   
    t_stack *last;

    last= *stack;
    *stack = (*stack)->next;
    ft_stackadd_back(stack,last);
}

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

void		sa(t_stack **stack_a)
{
    swap(stack_a);
    ft_putstr_fd("sa\n", 1);
}   

void		sb(t_stack **stack_b)
{
    swap(stack_b);
    ft_putstr_fd("sb\n", 1);
}

void		ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    ft_putstr_fd("ss\n", 1);
}

void    pa(t_stack **stack_a, t_stack **stack_b)
{
    push_stack(stack_a, stack_b);
    ft_putstr_fd("pa\n", 1);
}

void    pb(t_stack **stack_b, t_stack **stack_a)
{
    push_stack(stack_b, stack_a);
    ft_putstr_fd("pb\n", 1);
}

void    ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_putstr_fd("ra\n",1);   
}

void    rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_putstr_fd("rb\n",1);
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr_fd("rr\n",1);
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