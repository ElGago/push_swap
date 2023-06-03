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
static void	printStack(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value,1);
		ft_putstr_fd(", ",1);
		tmp = tmp->next;
	}
	ft_putendl_fd("",1);
}

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
    printStack(top);
    //rra(&top);
    tmp = NULL;
    //size = ft_stacksize(top);
     //size = insertion_sort(&top,&tmp);
    size = insertion_chunks_sort(&top, &tmp);
    //top = simple_sort(&top, &tmp);
    //size= sort_10(&top, &tmp);
    //size = newsort(&top,&tmp);
    printf("movimientos:%d\n", size);
    printStack(top);
    freeStack(&top);
    freeStack(&tmp);
    return (0);
}

