/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:05:51 by jocorrea          #+#    #+#             */
/*   Updated: 2023/07/09 16:58:06 by jocorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include <stdio.h>

// Stack
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	struct s_stack	*next;
}	t_stack;

t_stack		*ft_stacknew(int value);
int			ft_stacksize(t_stack *head);
void		push(t_stack **top, t_stack *x);
t_stack		*pop(t_stack **top);
t_stack		*ft_stacklast(t_stack *stack);
// Instruction functions
void		swap(t_stack **a);
void		push_stack(t_stack **stack_to, t_stack **stack_from);
void		rotate(t_stack **stack);
void		reverserotate(t_stack **stack);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_b, t_stack **stack_a);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
// utils
int			ft_is_order(t_stack *a);
t_stack		*stackmin(t_stack *stack);
void		index_stack(t_stack **a);
t_stack		*stackmax(t_stack *stack);
void		ft_update_pos(t_stack **a);
void		printstack(t_stack *head);
void		*freestack(t_stack **top);
int			ft_str_cmp(char *s1, char *s2);
long		ft_atol(const char *str);
// check input
t_stack		*generate_a(char **arg);
// sort
void		caso3(t_stack **a);
void		caso4(t_stack **a, t_stack **b);
void		caso5(t_stack **a, t_stack **b);
void		sort(t_stack **a, t_stack **b);
// sort insertion massive +100 +500
void		fill_chunk_a_to_b(t_stack **a, t_stack **b, \
		int chunk, int size_chunks);
// void	try_b_to_a(t_stack **a, t_stack **b, t_stack *max, int down);
t_stack		*near_edge(t_stack **a, int chunk, int s_chunk);
void		insertion_chunks_sort(t_stack **a, t_stack **b);
// checker
int			process_move(t_stack **a, t_stack **b, char *line);
#endif
