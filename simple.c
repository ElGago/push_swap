/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:17:48 by jocorrea          #+#    #+#             */
/*   Updated: 2023/05/11 11:41:35 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *simple_sort(char **argv)
{
    t_stack *a;
    //t_stack *b;
    int a_size;

    a = generate_a(argv);
    //b = NULL;
    a_size = ft_stacksize(a);
    if (a_size <= 1 || ft_is_order(a))
        return (a);
    if (a_size == 2)
    {
        sa(&a);
        return (a);
    }
    return (a);
} 