/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:22:22 by jocorrea          #+#    #+#             */
/*   Updated: 2023/05/11 10:59:28 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

int  duplicate(char **str)
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

int inputcheck(char **arg)
{
    int i;

    i = 1;
    while (arg[i] && is_num(arg[i]))
        i++;
    if (arg[i] != 0 || duplicate(arg))
        return (0);
    return (1);
}

t_stack *generate_a(char **arg)
{
    t_stack *a = NULL;
    int size;

    size = 0;
    while (arg[size] != 0)
        size++;
    if (inputcheck(arg))
        while (size-- > 1)
            push(&a,ft_atoi(arg[size]));
    else
        printf("argumentos invalidos\n");
    return (a);
}