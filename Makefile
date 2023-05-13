# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 10:23:35 by jocorrea          #+#    #+#              #
#    Updated: 2023/05/13 14:02:23 by jocorrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	stack.c swap.c utils.c inputcheck.c simple.c

OBJS = $(SRCS:.c=.o)

BONUS =	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

BONUS_OBJS = $(BONUS:.c=.o)

AR = ar rcs

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -MMD

INCLUDE = -I ./libft/libft.a push_swap.h

NAME = push_swap.a

DEPS= $(OBJS:.o=.d)

DEPS_BONUS= $(BONUS_OBJS:.o=.d)

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make fclean -C ./libft
	@make bonus -C ./libft
	@make clean -C ./libft
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
