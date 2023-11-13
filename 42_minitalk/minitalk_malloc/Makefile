# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 14:41:58 by adelaloy          #+#    #+#              #
#    Updated: 2023/11/10 15:51:08 by adelaloy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  server.c client.c	    
OBJS = ${SRCS:.c=.o}
NAME = server
NAME1 = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: 
	${CC} ${CFLAGS} server.c -o ${NAME}
	${CC} ${CFLAGS} client.c -o ${NAME1}
	
clean:
			${RM} ${OBJS} 

fclean: clean
			${RM} ${NAME} ${NAME1}

re: fclean all