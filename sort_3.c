/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:07:28 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/09 17:00:07 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_order(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp != NULL && tmp->next != NULL && tmp->value < tmp->next->value)
		tmp = tmp->next;
	if (tmp == NULL || tmp->next != NULL)
		return (0);
	return (1);
}

void	caso3(t_stack **a)
{
	int	first;
	int	last;
	int	next;

	first = (*a)->value;
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

t_stack	*near_edge(t_stack **a, int chunk, int s_chunk)
{
	t_stack	*up;
	t_stack	*down;
	t_stack	*tmp;

	tmp = *a;
	while (tmp && tmp->index > (s_chunk * (chunk + 1)))
		tmp = tmp->next;
	up = tmp;
	down = up;
	while (tmp)
	{
		if (tmp->index < (s_chunk * (chunk + 1)))
			down = tmp;
		tmp = tmp->next;
	}
	if (up->pos < ft_stacksize(*a) / 2 && (up->index < \
				(s_chunk * (chunk + 1)) + 1))
		return (up);
	return (down);
}

void	*freestack(t_stack **top)
{
	t_stack	*temp;

	while (*top != NULL)
	{
		temp = *top;
		*top = (*top)->next;
		free(temp);
	}
	return (NULL);
}
