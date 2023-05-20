/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:20:44 by marvin            #+#    #+#             */
/*   Updated: 2023/04/24 11:20:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int args, char **argv)
{
    t_stack *top;
    (void)args;
    top = generate_a(argv);
    top = simple_sort(&top);
    printStack(top);
}


   