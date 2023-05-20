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
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	if (!(stack)->next)
		return (stack);
	while (stack && (stack)->next)
		stack = (stack)->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = ft_stacklast(*stack);
	if ((tmp))
		tmp->next = new;
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
		ft_putstr_fd(", ",1);
		tmp = tmp->next;
	}
	ft_putendl_fd("",1);
}

void push(t_stack **top, int x)
{
    t_stack *node;

    node = ft_stacknew(x);
    if (node)
	{
    	node->next = *top;
    	*top = node;
	}
}

int isEmpty(t_stack *top) 
{
    return (top == NULL);
}

int peek(t_stack *top)
{
    if (!isEmpty(top)) 
        return (top->value);
    else
		return (-1);
}

int pop(t_stack **top)
{
    t_stack *node;
	int x;
   
    if (*top)
    {
 		x = peek(*top);
    	node = *top;
   		*top = (*top)->next;
    	free(node);
    	return (x);
	}
	else
		return (-1);
}

void freeStack(t_stack** top) 
{
	t_stack *temp;

    while (*top != NULL)
	{
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}
