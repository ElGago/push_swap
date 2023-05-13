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
    t_stack *top = NULL;
    //t_stack *b = NULL;
    (void)args;

    top = generate_a(argv);
    printStack(top);
    if (ft_is_order(top))
        printf("Esta ordenada la pila\n");
    else
    {
         printf("no esta ordenada la pila\n");
         top = simple_sort(argv);
         printStack(top);
    }
       

    /*
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    push(&top, 5);
    printStack(top);
    printf("The top element is %d\n", peek(top));

    pop(&top);
    pop(&top);
    pop(&top);
 
    if (isEmpty(top)) {
        printf("The stack is empty\n");
    }
    else {
        printf("The stack is not empty\n");
        pop(&top);
    }
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    printStack(top);
    top = swap(&top);
    printf("el swap es:\n");
    printStack(top);
    top = swap(&top);
    printf("el nuevo swap es:\n");
    printStack(top);
    push(&b, pop(&top));
    printf("el stack b es: \n");
    printStack(b);
    printf("El stack top es:\n");
    printStack(top);
    push_stack(&top, &b);
    printf("el stack b es: \n");
    printStack(b);
    printf("El stack top es:\n");
    printStack(top);
    push(&top, 5);
    printf("top es:\n");
    printStack(top);
    rotate(&top);
    printf("el nuevo top es :\n");
    printStack(top);
    reverseRotate(&top);
    printStack(top);
    sa(&top);
    return 0;
    */

}
