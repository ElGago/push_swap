#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>

// Stack
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

// Util functions
void		ft_putstr_fd(char *s, int fd);
t_stack		*ft_stacknew(int value);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_removeLast(t_stack **stack);
void		printStack(t_stack *head);
int			ft_stacksize(t_stack *head);
void 		push(t_stack **top, int x);
int			isEmpty(t_stack *top);
int			peek(t_stack *top);
int			pop(t_stack **top);
void 		freeStack(t_stack** top);
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
void		ft_putstr_fd(char *s, int fd);
int			ft_str_cmp(char *s1, char *s2);
int 		is_num(char *str);
int  		duplicate(char **str);
int			ft_is_order(t_stack *a);
int stackMin(t_stack *stack);
//check input
int			inputcheck(char **arg);
t_stack		*generate_a(char **arg);
//sort
t_stack		*simple_sort(t_stack **a);
int 		ft_Stack_sort(t_stack **a, t_stack **b);
int    		newsort(t_stack **a, t_stack **b);
#endif