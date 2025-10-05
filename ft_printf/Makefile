# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwafi <kwafi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/04 11:36:32 by kwafi             #+#    #+#              #
#    Updated: 2025/10/04 11:36:32 by kwafi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SRCS = ft_printf.c ft_printf_utilities.c ft_printf_str.c ft_printf_num.c \
       ft_print_hex.c ft_print_ptr.c ft_print_unsigned.c
OBJ_FILES	= 	$(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJ_FILES)
			$(AR) $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ_FILES)

fclean:		clean	
			$(RM) $(NAME)	

re:			fclean all		


.PHONY:		all clean fclean re
