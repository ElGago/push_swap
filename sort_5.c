/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:37:27 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/01 19:02:05 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	if (!(stack)->next)
		return (stack);
	while (stack && (stack)->next)
		stack = (stack)->next;
	return (stack);
}

void	caso4(t_stack **a, t_stack **b)
{
	pb(b, a);
	caso3(a);
	if ((*b)->value < (*a)->value)
		pa(a, b);
	else if ((*b)->value > ft_stacklast(*a)->value)
	{
		pa(a, b);
		ra(a);
	}
	else if ((*b)->value > (*a)->next->value)
	{
		rra(a);
		pa(a, b);
		ra(a);
		ra(a);
	}
	else
	{
		pa(a, b);
		sa(a);
	}
}

void	parte2(t_stack **a, t_stack **b)
{
	if ((*b)->value < (*a)->next->value)
	{
		pa(a, b);
		sa(a);
	}
	else if ((*b)->value < (*a)->next->next->value)
	{
		ra(a);
		pa(a, b);
		sa(a);
		rra(a);
	}
	else
	{
		rra(a);
		pa(a, b);
		ra(a);
		ra(a);
	}
}

void	caso5(t_stack **a, t_stack **b)
{
	pb(b, a);
	caso4(a, b);
	if ((*b)->value < (*a)->value)
		pa(a, b);
	else if ((*b)->value > ft_stacklast(*a)->value)
	{
		pa(a, b);
		ra(a);
	}
	else
		parte2(a, b);
}
