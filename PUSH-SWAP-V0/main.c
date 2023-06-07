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


static void freeStack(t_stack** top) 
{
	t_stack *temp;

    while (*top != NULL)
	{
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int main(int args, char **argv)
{
    t_stack *top;
    t_stack *tmp;
    int     size;
    (void)args;

    top = generate_a(argv);
    tmp = NULL;
    insertion_chunks_sort(&top, &tmp);
   // printStack(top);
    freeStack(&top);
    freeStack(&tmp);
    return (0);
}

