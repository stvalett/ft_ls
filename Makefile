# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stvalett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 16:57:07 by stvalett          #+#    #+#              #
#    Updated: 2017/01/23 17:12:25 by stvalett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

CFLAG = -Wall -Wextra -Werror

INCLUDE = ls.h

SRCS = dir.c\
	   error.c\
	   info.c\
	   main.c\
	   parser.c\
	   print.c\
	   print_opt.c\
	   print_opt2.c\
	   size.c\
	   sort.c\
	   tool.c\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C libft
	@$(CC) $(CFLAG) $(SRCS) libft/libft.a -I$(INCLUDE) -o $(NAME)

clean :
	@make clean -C libft
	@rm -f $(OBJ)

fclean : clean
	@make fclean -C libft
	@rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re
