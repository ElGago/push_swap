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
    t_stack *tmp;
    int     size;
    (void)args;

    top = generate_a(argv);
    tmp = NULL;
    //size = ft_stacksize(top);
    // size = insertion_sort(&top,&tmp);
    size =chunks_insertion_sort(&top,&tmp);
    //top = simple_sort(&top, &tmp);
  //  size= sort_10(&top, &tmp);
    //size = newsort(&top,&tmp);
    printf("movimientos:%d\n", size);
    printStack(top);
    freeStack(&top);
    freeStack(&tmp);
    return (0);
}


   