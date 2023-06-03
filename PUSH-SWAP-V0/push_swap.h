#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <stdio.h>

// Stack
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	struct s_stack	*next;
}				t_stack;

t_stack		*ft_stacknew(int value);
int			ft_stacksize(t_stack *head);
void 		push(t_stack **top, t_stack *x);
t_stack		*pop(t_stack **top);
t_stack		*ft_stacklast(t_stack *stack);
// Instruction functions
void		swap(t_stack **a);
void		push_stack(t_stack **stack_to, t_stack **stack_from);
void		rotate(t_stack **stack);
void		reverseRotate(t_stack **stack);
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
//utils
int			ft_is_order(t_stack *a);
t_stack 	*stackMin(t_stack *stack);
void    	index_stack(t_stack **a);
t_stack 	*stackMax(t_stack *stack);
void	    ft_update_pos(t_stack **a);
int 		media(t_stack **a);
//check input
t_stack		*generate_a(char **arg);
//sort
void		caso3(t_stack **a);
void		caso4(t_stack **a, t_stack **b);
void		caso5(t_stack **a, t_stack **b);
t_stack 	*simple_sort(t_stack **a, t_stack **b);
int 		insertion_chunks_sort(t_stack **a, t_stack **b);
#endif