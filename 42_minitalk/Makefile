# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 14:41:58 by adelaloy          #+#    #+#              #
#    Updated: 2023/11/13 16:14:36 by adelaloy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  server.c client.c	    
OBJS = ${SRCS:.c=.o}
NAME = server
NAME1 = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: ${OBJS}
    ${CC} ${CFLAGS} ${OBJS} -o ${NAME}
    ${CC} ${CFLAGS} ${OBJS} -o ${NAME1}

%.o: %.c
    ${CC} ${CFLAGS} -c $< -o $@

clean:
    ${RM} ${OBJS} 

fclean: clean
    ${RM} ${NAME} ${NAME1}

re: fclean all