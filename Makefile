# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 10:23:35 by jocorrea          #+#    #+#              #
#    Updated: 2023/07/09 12:25:46 by jocorrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	stack.c swap.c stack_push.c rotate.c reverse_rotate.c ft_stack_input_check.c utils.c \
		massive_sort.c main.c sort_5.c sort_3.c fill_a_to_b.c stack_sort_mov.c ft_atol.c

OBJS = $(SRCS:.c=.o)

BONUS =	stack.c swap.c stack_push.c rotate.c reverse_rotate.c ft_stack_input_check.c utils.c \
		massive_sort.c sort_5.c sort_3.c fill_a_to_b.c stack_sort_mov.c checker.c ft_atol.c

BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -MMD

INCLUDE = -Ipush_swap.h ./libft/libft.a 

NAME = push_swap

DEPS= $(OBJS:.o=.d)

DEPS_BONUS= $(BONUS_OBJS:.o=.d)

# Metodo implicito
%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


# Mis metodos
all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJS)
	@make bonus -C ./libft
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

clean:
	@make clean -C ./libft
	@$(RM) $(OBJS) $(BONUS_OBJS) $(DEPS) $(DEPS_BONUS) bonus

fclean: clean
	@make fclean -C ./libft
	@$(RM) $(NAME)
	@$(RM) checker
	
re: fclean $(NAME)

-include $(DEPS_BONUS)
bonus: $(BONUS_OBJS)
	@make bonus -C ./libft
	$(CC) $(CFLAGS) $(INCLUDE) $(BONUS_OBJS) -o checker
	touch bonus

.PHONY: all clean fclean re
