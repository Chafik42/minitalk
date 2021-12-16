# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 13:04:14 by cmarouf           #+#    #+#              #
#    Updated: 2021/12/16 15:06:26 by cmarouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CLIENT		= srcs/client.c

SERVER		= srcs/server.c

UTILS		= srcs/utils.c

RM 			= rm -f

CFLAGS 		= -Wall -Wextra -Werror

NAME		= client

NAME2 		= server

PRINTFLIB	= ./ft_printf/libftprintf.a

CC 			= gcc

all:		$(NAME)

$(NAME):
					make -C ./ft_printf
					${CC} ${CFLAGS} -g3 -fsanitize=address ${CLIENT} ${UTILS} ${PRINTFLIB} -o ${NAME}
					${CC} ${CFLAGS} -g3 -fsanitize=address ${SERVER} ${PRINTFLIB} -o ${NAME2}

clean:
			make clean -C ./ft_printf
					${RM} ${NAME}
					${RM} ${NAME2}

fclean:		clean
			make fclean -C ./ft_printf

re:			fclean all
					
.PHONY: all clean fclean re bonus
