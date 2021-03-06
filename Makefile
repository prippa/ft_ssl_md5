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
FLAGS		= 	-Wall -Werror -Wextra
CC			=	gcc

DIR_INC		=	./includes/
DIR_SRC		=	./source/
DIR_MD5		=	./source/md5/
DIR_SHA256	=	./source/sha256/
DIR_SHA512	=	./source/sha512/
DIR_OBJ		= 	./obj/
DIR_LIB		=	./libft/
DIR_LIB_INC	=	$(DIR_LIB)includes/
LIBFT		=	$(DIR_LIB)libft.a

#-------------------------- Header files ---------------------------------------
HEAD_SSL	=	ssl.h
HEAD_MD5	=	md5.h
HEAD_SHA256	=	sha256.h
HEAD_SHA512	=	sha512.h

#-------------------------- Source files ---------------------------------------
C_SSL		= 	main.c ssl_interactive_read.c ssl_parser.c ssl_trash.c\
				ssl_print_info.c ssl_read.c ssl_init.c ssl_flag_function.c\
				ssl_print_hash.c

C_MD5		= 	ssl_md5.c ssl_md5_rounds.c

C_SHA256	= 	ssl_sha256.c ssl_sha224.c ssl_sha256_algo.c

C_SHA512	= 	ssl_sha512.c ssl_sha512_algo.c ssl_sha512_helpers.c\
				ssl_sha384.c ssl_sha512_224.c ssl_sha512_256.c


OBJ 		= 	$(addprefix $(DIR_OBJ), $(C_SSL:.c=.o) $(C_MD5:.c=.o)\
					$(C_SHA256:.c=.o) $(C_SHA512:.c=.o))

INC 		= 	$(addprefix -I, $(DIR_INC) $(DIR_LIB_INC))
INC_SSL 	= 	$(addprefix $(DIR_INC), $(HEAD_SSL))
INC_MD5 	= 	$(addprefix $(DIR_INC), $(HEAD_SSL) $(HEAD_MD5))
INC_SHA256 	= 	$(addprefix $(DIR_INC), $(HEAD_SSL) $(HEAD_SHA256))
INC_SHA512 	= 	$(addprefix $(DIR_INC), $(HEAD_SSL) $(HEAD_SHA512))


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

#sha256
$(DIR_OBJ)%.o: $(DIR_SHA256)%.c $(INC_SHA256)
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#sha512
$(DIR_OBJ)%.o: $(DIR_SHA512)%.c $(INC_SHA512)
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
