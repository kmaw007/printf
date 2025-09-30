#Variables

Name = libftprintf.a
INCLUDE = include 
SRC_DIR = src/
OBJ_DIR = obj/
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SRC_FILES	=	ft_printf ft_printf_utils ft_print_ptr ft_print_unsigned ft_print_hex


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))


.PHONY:		all clean fclean re
all:		$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJ)
			$(AR) $@ $^

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) -r $(OBJ_DIR)

fclean:		clean	
			$(RM) $(NAME)	

re:			fclean all		
