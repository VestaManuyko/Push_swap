# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 17:13:00 by vmanuyko          #+#    #+#              #
#    Updated: 2025/05/03 16:22:10 by vmanuyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BNS_NAME = push_swap_bonus
LIBFT = libft/libft.a
CC = cc -Wall -Wextra -Werror -g
#project program sources
PSRC = main.c free.c helpers.c swap_op.c push_op.c rotate_op.c \
rev_rotate_op.c list.c sort.c max_min.c count_op.c
#object files
POBJ = $(PSRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(POBJ)
	@$(CC) $(POBJ) $(LIBFT) -o $(NAME)
	@echo "Push_swap compiled successfully."

%.o : %.c
	@$(CC) -c $< -o $@

$(LIBFT) :
	@$(MAKE) -C libft --no-print-directory

clean :
	@rm -f $(OBJ) $(POBJ)
	@$(MAKE) -C libft --no-print-directory clean
	@echo "Cleaned."

fclean : clean
	@rm -f $(LIBFT) $(NAME)
	@$(MAKE) -C libft --no-print-directory fclean

re : fclean $(NAME)

bonus : $(BNS_NAME)

$(BNS_NAME) : $(LIBFT) $(BOBJ)
	@$(CC) $(BOBJ) $(LIBFT) -o $(BNS_NAME)
	@echo "Push_swap bonus compiled successfully."
#if you decide on bonus add clean for bonus files aswell

.PHONY : all clean fclean re bonus
