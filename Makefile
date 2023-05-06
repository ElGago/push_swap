# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocorrea <jocorrea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 10:23:35 by jocorrea          #+#    #+#              #
#    Updated: 2023/05/06 15:50:44 by jocorrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap.a

SRC			=	stack.c swap.c 

SRC_BONUS	=	

PUSH_SWAP	=	-I push_swap.h ./libft/libft.a

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

AR = ar rcs

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -MMD

DEPS= $(OBJS:.o=.d)

%.o: %.c $(PUSH_SWAP)
	@$(CC) $(CFLAGS) $(PUSH_SWAP) -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJ)
			make fclean -C ./libft
			make bonus -C ./libft
			make clean -C ./libft
			@$(AR) $(NAME) $(OBJ)
-include $(DEPS)

clean:
			${RM} $(OBJ) 
			make clean -C ./libft
			
fclean: 	clean
			make fclean -C ./libft
			${RM} $(NAME) ${OBJ} 
	
re:			fclean $(NAME)

.PHONY:		all clean fclean re