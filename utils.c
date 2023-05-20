/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:57:49 by jocorrea          #+#    #+#             */
/*   Updated: 2023/05/20 12:04:00 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_order(t_stack *a)
{
    t_stack *tmp;

    tmp = a;
    while (tmp != NULL && tmp->next != NULL && tmp->value < tmp->next->value)
        tmp = tmp->next;
    if(tmp->next != NULL)
        return (0);//si no termina en el ultimo elemento el ciclo anterior es que la pila no esta ordenada
    return (1);
}

int	ft_str_cmp(char *s1, char *s2)
{
	int i;

    i = 0;
    while(s1[i] && s2[i] && s1[i] == s2[i])i++;
	return (s1[i] - s2[i]);
}

int is_num(char *str)
{
    int i;

    i = 0;
    while(str[i] && ft_isdigit(str[i]))
    i++;
    if(str[i] != '\0')
        return (0);
    return (1);
}

int stackMax(t_stack *stack)
{
    int max;

    max = (stack)->value; 
    while (stack)
    {
        if (max < peek(stack))
            max = peek(stack);
        stack = stack->next;
    }
    return (max);
}

int stackMin(t_stack *stack)
{
    int min;

    min = stack->value; 
    while (stack)
    {
        if (min < peek(stack))
            min = peek(stack);
        stack = stack->next;
    }
    return (min);
}

