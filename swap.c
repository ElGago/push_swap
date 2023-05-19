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
    int  tmp;

    if (*a != NULL && (*a)->next != NULL)
    {
        tmp = peek(*a);
        (*a)->value = (*a)->next->value;
        (*a)->next->value = tmp;
    }  
}

void    push_stack(t_stack **stack_to, t_stack **stack_from)
{
    int b;

    b = pop(stack_from);
    if (b != -1)
        push(stack_to, b);
}

void		rotate(t_stack **stack)
{
    int top;
    t_stack *last;

    top = pop(stack);
    if (top != -1)
    {
        last = ft_stacklast(stack);
        last->next = ft_stacknew(top);
    }
}

void		reverseRotate(t_stack **stack)
{
    t_stack *last;

    last = ft_stacklast(stack);
    if (last != NULL)
        push(stack, last->value);
    ft_removeLast(stack);
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