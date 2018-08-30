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
DIR_MD5		=	./source/md5/
DIR_SHA		=	./source/sha/
DIR_OBJ		= 	./obj/
DIR_LIB		=	./libft/
DIR_LIB_INC	=	$(DIR_LIB)includes/
LIBFT		=	$(DIR_LIB)libft.a

#-------------------------- Header files ---------------------------------------
HEAD_SSL	=	ssl.h
HEAD_MD5	=	md5.h
HEAD_SHA	=	sha.h

#-------------------------- Source files ---------------------------------------
C_SSL		= 	main.c ssl_interactive_read.c

C_MD5		= 	

C_SHA		= 	


OBJ 		= 	$(addprefix $(DIR_OBJ), $(C_SSL:.c=.o) $(C_MD5:.c=.o)\
					$(C_SHA:.c=.o))

INC 		= 	$(addprefix -I, $(DIR_INC) $(DIR_LIB_INC))
INC_SSL 	= 	$(addprefix $(DIR_INC), $(HEAD_SSL))
INC_MD5 	= 	$(addprefix $(DIR_INC), $(HEAD_SSL) $(HEAD_MD5))
INC_SHA 	= 	$(addprefix $(DIR_INC), $(HEAD_SSL) $(HEAD_SHA))


all: lib $(NAME)

lib:
	@make -C $(DIR_LIB)

#-------------------------- Compil Block ---------------------------------------
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "Compiling" [ $(NAME) ]

#-------------------------- Link Block -----------------------------------------
#source
$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(INC_SSL)
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#md5
$(DIR_OBJ)%.o: $(DIR_MD5)%.c $(INC_MD5)
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#sha
$(DIR_OBJ)%.o: $(DIR_SHA)%.c $(INC_SHA)
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
