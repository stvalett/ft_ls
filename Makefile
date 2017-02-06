# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stvalett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 16:57:07 by stvalett          #+#    #+#              #
#*   Updated: 2017/02/03 23:21:29 by stvalett         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME = ft_ls

CC = gcc

CFLAG = -Wall -Wextra -Werror

INCLUDE = includes/ls.h

SRCS = srcs/dir.c\
	   srcs/error.c\
	   srcs/info.c\
	   srcs/main.c\
	   srcs/parser.c\
	   srcs/print.c\
	   srcs/print_opt.c\
	   srcs/print_opt2.c\
	   srcs/size.c\
	   srcs/sort.c\
	   srcs/sort_2.c\
	   srcs/tool.c\
	   srcs/utils.c\
	   srcs/utils2.c\
	   srcs/colors.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(OBJ) :
	$(CC) $(CFLAG) -c $(SRCS)
$(NAME) :
	@make -C libft
	$(CC) $(CFLAG) $(SRCS) libft/libft.a $(INCLUDE) -o $(NAME)

clean :
	@make clean -C libft
	rm -f $(OBJ)

fclean : clean
	@make fclean -C libft
	rm -f $(NAME)

re : fclean all
