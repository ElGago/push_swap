/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_input_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:24:34 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/09 16:53:41 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	duplicate(char **str)
{
	int	i;
	int	j;

	i = 1;
	if (str[i])
	{
		while (str[i] != 0)
		{
			j = i + 1;
			while (str[j])
			{
				if (ft_str_cmp(str[i], str[j]) == 0)
					return (1);
				j++;
			}
			i++;
		}
	}
	return (0);
}

static int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

static int	inputcheck(char **arg)
{
	int		i;
	long	num;

	i = 1;
	while (arg[i] && is_num(arg[i]))
	{
		if (ft_strlen(arg[i]) <= 11)
			num = ft_atol(arg[i]);
		else
			return (0);
		if (num < -2147483648 || num > 2147483647)
			return (0);
		i++;
	}
	if (arg[i] != 0 || duplicate(arg))
		return (0);
	return (1);
}

t_stack	*generate_a(char **arg)
{
	t_stack	*a;
	t_stack	*node;
	int		size;

	size = 0;
	a = NULL;
	while (arg[size] != 0)
		size++;
	if (inputcheck(arg))
	{
		while (size-- > 1)
		{
			node = ft_stacknew(ft_atoi(arg[size]));
			if (!node)
				return (freestack(&a));
			push(&a, node);
		}
	}
	else
		return (NULL);
	index_stack(&a);
	ft_update_pos(&a);
	return (a);
}
