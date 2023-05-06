/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:09:38 by marvin            #+#    #+#             */
/*   Updated: 2023/04/24 10:09:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int value)
{
    t_stack	*linkedstack;

	linkedstack = (t_stack *)malloc(sizeof(t_stack));
	if (!linkedstack)
		return (NULL);
	linkedstack->value = value;
    linkedstack->index = -1;
	linkedstack->next = NULL;
	return (linkedstack);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	if (!stack->next)
		return (stack);
	while (stack)
	{
		if (!stack->next)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = (*stack);
	if ((*stack))
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	if (!(*stack))
		((*stack) = new);
}

void	ft_removeLast(t_stack **stack)
{
	t_stack	*tmp;
	t_stack *pre;

	tmp = (*stack);
	pre = NULL;
	if ((*stack))
	{
		while (tmp->next != NULL)
		{
			pre = tmp;
			tmp = tmp->next;
		}
		pre->next = NULL;
		free(tmp);
	}
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	printStack(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value,1);
		ft_putendl_fd("",1);
		tmp = tmp->next;
	}
}

void push(t_stack **top, int x)        // insertar al principio
{
    // asignar un nuevo nodo en un heap
    t_stack *node = NULL;

    node = (t_stack *)malloc(sizeof(t_stack));
    // comtrie si la stack (heap) está llena. Entonces insertar un elemento sería
    // conduce al desbordamiento de la stack
    if (!node)
    {
        ft_putstr_fd("Heap Overflow\n",2);
        exit(-1);
    }
    // establecer datos en el nodo asignado
    node->value = x;
    // establece el puntero .next del nuevo nodo para que apunte al actual
    // nodo superior de la lista
    node->next = *top;
    // actualiza el puntero superior
    *top = node;
}

int isEmpty(t_stack *top) {
    return (top == NULL);
}

// Función de utilidad para devolver el elemento superior de la stack
int peek(t_stack *top)
{
    // comprobar si hay una stack vacía
    if (!isEmpty(top)) {
        return top->value;
    }
    else {
        ft_putstr_fd("The stack is empty\n",2);
        exit(1);
    }
}

// Función de utilidad para sacar un elemento superior de la stack
int pop(t_stack **top)        // eliminar al principio
{
    t_stack *node;
	int x;
    // comprobar si hay subdesbordamiento de stack
    if (*top == NULL)
    {
        ft_putstr_fd("Stack Underflow\n", 1);
        exit(1);
    }
    // tomar nota de los datos del nodo superior
 	x = peek(*top);
    node = *top;
    // actualiza el puntero superior para que apunte al siguiente nodo
    *top = (*top)->next;
    // memoria asignada libre
    free(node);
    return x;
}
