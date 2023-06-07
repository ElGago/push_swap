/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   massive_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:47:22 by jocorrea          #+#    #+#             */
/*   Updated: 2023/06/07 10:28:52 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *near_edge(t_stack **a, int chunk, int s_chunk)
{
    t_stack *up;
    t_stack *down;
    t_stack *tmp;

    tmp = *a;
    while (tmp && tmp->index > (s_chunk * (chunk + 1)))
        tmp = tmp->next;
    up = tmp;
    down = up;
    while (tmp)
    {
        if (tmp->index < (s_chunk * (chunk + 1)))
            down = tmp;
        tmp = tmp->next;
    }
    if (up->pos < ft_stacksize(*a) / 2 && (up->index < (s_chunk * (chunk + 1))+1))
        return (up);
    return (down);
}

void fill_chunk_a_to_b(t_stack **a, t_stack **b, int chunk, int size_chunks)
{
    int size;
    t_stack *piv;

    size = ft_stacksize(*a);
    while (*a)
    {
        piv = near_edge(a, chunk, size_chunks);
        if (piv->pos < ft_stacksize(*a) / 2)
            while (*a && (*a)->index > ((size_chunks) * (chunk + 1)))
                if ((*a)->next->index == piv->index)
                    sa(a);
                else
                    ra(a);
        else
            while (*a && (*a)->index > ((size_chunks) * (chunk + 1)))
                rra(a);
        pb(b, a);
        if (ft_stacksize(*b) > 1 && (*b)->index < ((size_chunks) / 2) + ((size_chunks) * chunk))
        {
            if ((ft_stacksize(*a) > 1 && (ft_stacksize(*a) + ((size_chunks) * (chunk + 1))) + 1) == size)
            {
                chunk++;
                piv = near_edge(a, chunk, size_chunks);
            }
            if (ft_stacksize(*a) > 1 && (*a)->index != piv->index && piv->pos < ft_stacksize(*a) / 2)
                rr(a, b);
            else
                rb(b);
        }
        if (((ft_stacksize(*a) + ((size_chunks) * (chunk + 1))) + 1) == size)
            chunk++;
    }
}

void try_b_to_a(t_stack **a, t_stack **b)
{
    t_stack *max;
    int size;
    
    while (*b)
    {
        max = stackMax(*b);
        while ((*b)->index != max->index)
        {   
            size = ft_stacksize(*b);
            if ((*b)->next->index == max->index)
               sb(b);
            else if (max->pos > size / 2)
                    rrb(b);
                else
                    rb(b);
        }
        pa(a, b);
    }
}

void try_b_to_a1(t_stack **a, t_stack **b)
{
    t_stack *max;
    int size;
    int down;
    
    down = 0;
    while (*b)
    {
        /*printf("EN EL INICIO LAS PILAS\n");
        printStack(*a);
        printStack(*b);*/
        max = stackMax(*b);
        while ((*b)->index != max->index)
        {   
            size = ft_stacksize(*b);
            if (down == 0 || *a == NULL || (*b)->index > ft_stacklast(*a)->index)
            {//esto se hace para aprobechar el final de la pila a
                pa(a,b);
                ra(a);
                down++;
            }//intento flotar hacia arriba el maxmo de b
            else if ((*b)->next->index == max->index)
                    sb(b);
            else if (max->pos > size / 2)
                    rrb(b);
                else
                    rb(b);
        }
        pa(a, b);/*
        printf("EN EL FINAL LAS PILAS\n");
        printStack(*a);
        printStack(*b);*/
        //si el ultimo de a es mayo que el maximo de b lo muevo a su pos
        if (*b)
            while ((*a)->index > ft_stacklast(*a)->index && ft_stacklast(*a)->index > stackMax(*b)->index)
            {
                rra(a);
                down--;
            }
        else//si ya be esta vacio entonces
            while ((*a)->index > ft_stacklast(*a)->index)
            {
                rra(a);
                down--;
            }
    }
}

void insertion_chunks_sort(t_stack **a, t_stack **b)
{
    int max_chunks;
    int index_chunk;
    int size;

    size = ft_stacksize(*a);
    index_chunk = 0;
    max_chunks = 8;
    if (size >= 6 && size <= 20)
        max_chunks = 2;
    if (size > 20 && size <= 150)
        max_chunks = 4;
    fill_chunk_a_to_b(a, b, index_chunk, (size / max_chunks));
    try_b_to_a1(a, b);
}

void	printStack(t_stack *head)
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