/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:57:49 by jocorrea          #+#    #+#             */
/*   Updated: 2023/05/28 20:50:08 by jocorrea         ###   ########.fr       */
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
        return (0);
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

    max = stack->index; 
    while (stack)
    {
        if (max < stack->index)
            max = stack->index;
        stack = stack->next;
    }
    return (max);
}

int stackMin(t_stack *stack)
{
    int min;

    min = stack->index; 
    while (stack)
    {
        if (min > stack->index)
            min = stack->index;
        stack = stack->next;
    }
    return (min);
}

void    index_stack(t_stack **a)
{
    int     ix;
    int     size;
    t_stack *tmp;
    t_stack *pivot;

    pivot = *a;
    size = ft_stacksize(*a);
    while (size-- > 0)
    {
        ix = 0;
        tmp = *a;
        while (tmp)
        {
            if (peek(pivot) > peek(tmp))
                ix++;
            tmp = tmp->next;
        }
        pivot->index = ix;
        pivot = pivot->next;
    } 
}

void    ft_update_pos(t_stack **a)
{
    int i;
    t_stack *tmp;

    tmp = *a;
    i = 0;
    while (tmp)
    {
        tmp->pos = i++;
        tmp = tmp->next;
    }
}

int media(t_stack **a)
{
    t_stack *tmp;
    int     media;

    tmp = *a;
    media = 0;
    while (tmp)
    {
        media += tmp->index;
        tmp = tmp->next;
    }
    media = (int)media / ft_stacksize(*a);
    return (media);
}
