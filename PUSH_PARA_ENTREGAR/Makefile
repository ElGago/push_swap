# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 10:23:35 by jocorrea          #+#    #+#              #
#    Updated: 2023/06/20 10:34:05 by jocorrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	stack.c swap.c stack_push.c rotate.c reverse_rotate.c ft_stack_input_check.c utils.c \
		massive_sort.c main.c sort_5.c sort_3.c fill_a_to_b.c stack_sort_mov.c sort_simple.c

OBJS = $(SRCS:.c=.o)

BONUS =	stack.c swap.c stack_push.c rotate.c reverse_rotate.c ft_stack_input_check.c utils.c \
		massive_sort.c sort_5.c sort_3.c fill_a_to_b.c stack_sort_mov.c checker.c

BONUS_OBJS = $(BONUS:.c=.o)

AR = ar rcs

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -MMD

INCLUDE = -Ipush_swap.h ./libft/libft.a 

NAME = push_swap.a

DEPS= $(OBJS:.o=.d)

DEPS_BONUS= $(BONUS_OBJS:.o=.d)

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C ./libft
	@$(AR) $(NAME) $(OBJS)
-include $(DEPS)

clean:
	@make clean -C ./libft
	@$(RM) $(OBJS) $(BONUS_OBJS) $(DEPS) $(DEPS_BONUS)
	

fclean: clean
	@make fclean -C ./libft
	@$(RM) $(NAME)
	

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
-include $(DEPS_BONUS)

.PHONY: all clean fclean re bonus
