/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:57:49 by jocorrea          #+#    #+#             */
/*   Updated: 2023/06/03 13:28:34 by jocorrea         ###   ########.fr       */
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

t_stack *stackMax(t_stack *stack)
{
    t_stack *max;

    max = stack; 
    while (stack)
    {
        if (max->index < stack->index)
            max = stack;
        stack = stack->next;
    }
    return (max);
}

t_stack *stackMin(t_stack *stack)
{
    t_stack *min;

    min = stack; 
    while (stack)
    {
        if (min->index > stack->index)
            min = stack;
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
            if (pivot->value > tmp->value)
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
    
    media = 0;
	tmp = *a;
    while (tmp)
    {
        media += tmp->index;
        tmp = tmp->next;
    }
    media = (int)media / ft_stacksize(*a);
    return (media);
}
