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
LIBFT = libft.a
CC = cc -Wall -Wextra -Werror -g
#everything needed for libft.a
LIBFTSRC = libft/ft_bzero.c libft/ft_calloc.c \
libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c \
libft/ft_isprint.c libft/ft_itoa.c libft/ft_memcmp.c libft/ft_memcpy.c \
libft/ft_memmove.c libft/ft_memset.c libft/ft_putendl_fd.c \
libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c \
libft/ft_get_next_line_utils.c libft/ft_strjoin.c libft/ft_strchr.c \
libft/ft_strdup.c libft/ft_striteri.c libft/ft_strlcat.c \
libft/ft_strlcpy.c libft/ft_strmapi.c libft/ft_strncmp.c \
libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strlen.c \
libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c \
libft/ft_toupper.c libft/ft_help.c libft/ft_printf.c \
libft/ft_get_next_line.c libft/ft_lstnew_bonus.c libft/ft_memchr.c \
libft/ft_lstadd_front_bonus.c libft/ft_lstsize_bonus.c \
libft/ft_lstlast_bonus.c libft/ft_lstadd_back_bonus.c \
libft/ft_lstdelone_bonus.c libft/ft_lstclear_bonus.c \
libft/ft_putchar_fd.c libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c
#project program sources
PSRC = main.c free.c helpers.c swap_op.c push_op.c rotate_op.c \
rev_rotate_op.c list.c sort.c
#object files
OBJ = $(LIBFTSRC:.c=.o)
POBJ = $(PSRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(POBJ)
	@$(CC) $(POBJ) $(LIBFT) -o $(NAME)
	@echo "Push_swap compiled successfully."

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) : $(OBJ)
	@ar -rsc $(LIBFT) $(OBJ)

clean :
	@rm -f $(OBJ) $(POBJ)
	@echo "Cleaned."

fclean : clean
	@rm -f $(LIBFT) $(NAME)

re : fclean $(LIBFT) $(NAME)

bonus : $(BNS_NAME)

$(BNS_NAME) : $(LIBFT) $(BOBJ)
	@$(CC) $(BOBJ) $(LIBFT) -o $(BNS_NAME)
	@echo "Push_swap bonus compiled successfully."
#if you decide on bonus add clean for bonus files aswell

.PHONY : all clean fclean re bonus
