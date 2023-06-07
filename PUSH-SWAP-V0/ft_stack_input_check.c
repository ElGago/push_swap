/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_input_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:24:34 by jocorrea          #+#    #+#             */
/*   Updated: 2023/06/01 11:36:30 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_str_cmp(char *s1, char *s2)
{
	int i;

    i = 0;
    while(s1[i] && s2[i] && s1[i] == s2[i])i++;
	return (s1[i] - s2[i]);
}

static int  duplicate(char **str)
{
    int i;
    int j;

    i = 1;
    if (str[i])
    {
        while(str[i] != 0)
        {
            j = i + 1;
            while (str[j])
            {
                if(ft_str_cmp(str[i], str[j]) == 0)
                    return (1);
                j++;
            }
            
            i++;
        }
    }
    return (0); 
}

static int is_num(char *str)
{
    int i;

    i = 0;
    while(str[i] && ft_isdigit(str[i]))
    i++;
    if(str[i] != '\0')
        return (0);
    return (1);
}

t_stack *generate_a(char **arg)
{
    t_stack *a = NULL;
    t_stack *node;
    int size;
    int i;

    size = 0;
    i = 1;
    while (arg[size] != 0)
        size++;
    while (arg[i] && is_num(arg[i]))
        i++;   
    if (arg[i] == 0 && !duplicate(arg))
        while (size-- > 1)
        {
            node = ft_stacknew(ft_atoi(arg[size]));
            push(&a,node);
        }
    else
        printf("argumentos invalidos\n");
    index_stack(&a);
    return (a);
}