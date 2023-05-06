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

t_stack		*swap(t_stack **a)
{
    t_stack  *tmp;

    if (*a != NULL && (*a)->next != NULL)
    {
        tmp = (*a)->next;
        (*a)->next = (*a)->next->next;
        tmp->next = (*a);
        *a = tmp;
    }  
    return (*a);
}

void		push_stack(t_stack **stack_to, t_stack **stack_from)
{
    int b;

    b = pop(stack_from);
    push(stack_to, b);
}

void		rotate(t_stack **stack)
{
    int top;
    t_stack *last;

    top = pop(stack);   
    last = ft_stacklast(*stack);
    last->next = ft_stacknew(top);
}

void		reverseRotate(t_stack **stack)
{
    t_stack *last;

    last = ft_stacklast(*stack);
    push(stack, last->value);
    ft_removeLast(stack);
}

void		sa(t_stack **stack_a)
{
    if(*stack_a != NULL)
        swap(stack_a);
    ft_putstr_fd("SA\n", 1);
}   

void		sb(t_stack **stack_b)
{
    if(*stack_b != NULL)
        swap(stack_b);
    ft_putstr_fd("SB\n", 1);
}

void		ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    ft_putstr_fd("SS\n", 1);
}

void    pa(t_stack **stack_a, t_stack **stack_b)
{
    push_stack(stack_a, stack_b);
    ft_putstr_fd("PA\n", 1);
}

void		pb(t_stack **stack_b, t_stack **stack_a)
{
    push_stack(stack_b, stack_a);
    ft_putstr_fd("PB\n", 1);
}

void		ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_putstr_fd("RA\n",1);   
}

void		rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_putstr_fd("RB\n",1);
}

void		rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr_fd("RR\n",1);
}

void		rra(t_stack **stack_a)
{
    reverseRotate(stack_a);
    ft_putstr_fd("RRA\n",1);
}

void		rrb(t_stack **stack_b)
{
    reverseRotate(stack_b);
    ft_putstr_fd("RRB\n",1);
}

void		rrr(t_stack **stack_a, t_stack **stack_b)
{
    reverseRotate(stack_a);
    reverseRotate(stack_b);
    ft_putstr_fd("RRR",1);
}