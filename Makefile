# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prippa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:20:39 by prippa            #+#    #+#              #
#    Updated: 2017/11/13 14:21:04 by prippa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ssl
# FLAGS		= 	-Wall -Werror -Wextra
CC			=	gcc

DIR_INC		=	./includes/
DIR_SRC		=	./source/
DIR_OBJ		= 	./obj/
DIR_LIB		=	./libft/
DIR_LIB_INC	=	$(DIR_LIB)includes/
LIBFT		=	$(DIR_LIB)libft.a

HEAD_SSL	=	ft_ssl.h

C_SSL		= 	main.c


OBJ 		= 	$(addprefix $(DIR_OBJ), $(C_SSL:.c=.o))

INC 		= 	$(addprefix -I, $(DIR_INC) $(DIR_LIB_INC))
INC_SSL 	= 	$(addprefix $(DIR_INC), $(HEAD_SSL))


all: lib $(NAME)

lib:
	@make -C $(DIR_LIB)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "Compiling" [ $(NAME) ]

$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(INC_SSL)
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

clean:
	@make -C $(DIR_LIB) clean
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files ft_ssl ]"

fclean:
	@make -C $(DIR_LIB) fclean
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files ft_ssl ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re
