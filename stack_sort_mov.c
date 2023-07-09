/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_mov.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:08:18 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/09 15:01:19 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_case(t_stack **a, t_stack **b, char *line)
{
	if (!(ft_str_cmp(line, "sa\n")))
	{
		swap(a);
		return (0);
	}
	if (!(ft_str_cmp(line, "sb\n")))
	{
		swap(b);
		return (0);
	}
	if (!(ft_str_cmp(line, "ss\n")))
	{
		swap(a);
		swap(b);
		return (0);
	}
	return (1);
}

static int	rotate_case(t_stack **a, t_stack **b, char *line)
{
	if (!(ft_str_cmp(line, "ra\n")))
	{
		rotate(a);
		return (0);
	}
	if (!(ft_str_cmp(line, "rb\n")))
	{
		rotate(b);
		return (0);
	}
	if (!(ft_str_cmp(line, "rr\n")))
	{
		rotate(a);
		rotate(b);
		return (0);
	}
	return (1);
}

static int	reverserotate_case(t_stack **a, t_stack **b, char *line)
{
	if (!(ft_str_cmp(line, "rra\n")))
	{
		reverserotate(a);
		return (0);
	}
	if (!(ft_str_cmp(line, "rrb\n")))
	{
		reverserotate(b);
		return (0);
	}
	if (!(ft_str_cmp(line, "rrr\n")))
	{
		reverserotate(a);
		reverserotate(b);
		return (0);
	}
	return (1);
}

int	process_move(t_stack **a, t_stack **b, char *line)
{
	if (!swap_case(a, b, line))
		return (0);
	else if (!rotate_case(a, b, line))
		return (0);
	else if (!reverserotate_case(a, b, line))
		return (0);
	else if (!(ft_str_cmp(line, "pa\n")))
	{
		push_stack(a, b);
		return (0);
	}
	else if (!(ft_str_cmp(line, "pb\n")))
	{
		push_stack(b, a);
		return (0);
	}
	else
		ft_putstr_fd("Error\n", 1);
	return (1);
}

void	sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stacksize(*a);
	if (!ft_is_order(*a))
	{
		if (size == 2)
			sa(a);
		else if (size == 3)
			caso3(a);
		else if (size == 4)
			caso4(a, b);
		else if (size == 5)
			caso5(a, b);
		else
			insertion_chunks_sort(a, b);
	}
}
