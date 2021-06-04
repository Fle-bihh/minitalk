# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fle-biha <fle-biha@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 15:47:30 by fle-biha          #+#    #+#              #
#    Updated: 2021/06/04 10:07:55 by fle-biha         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS_CLIENT		= srcs_client/client.c

OBJS_CLIENT		= $(SRCS_CLIENT:.c=.o)

SRCS_SERVER		= srcs_server/server.c

OBJS_SERVER		= $(SRCS_SERVER:.c=.o)

CC				= @gcc

RM				= @/bin/rm -f

CFLAGS			= -Wall -Wextra -Werror

LIB				= libft/libft.a

CLIENT			= client

SERVER			= server

HEADER			= incs/minitalk.h

.c.o:			$(HEADER) $(LIB)
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			compil $(CLIENT) $(SERVER)

compil:
				@make -C libft

$(OBJS_CLIENT):		$(HEADER)

$(OBJS_SERVER):		$(HEADER)

$(CLIENT):		$(OBJS_CLIENT)
				$(CC) $(CFLAGS) $(OBJS_CLIENT) -I $(HEADER) $(LIB) -o $(CLIENT)
				@echo "CLIENT COMPILED"

$(SERVER):		$(OBJS_SERVER)
				$(CC) $(CFLAGS) $(OBJS_SERVER) -I $(HEADER) $(LIB) -o $(SERVER)
				@echo "SERVER COMPILED"

clean:
				$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)
				@make clean -C libft
				@echo "MINITALK CLEAN"

fclean:			clean
				$(RM) $(CLIENT) $(SERVER)
				@make fclean -C libft
				@echo "MINITALK FCLEAN"

re:				fclean all

.PHONY:			all clean fclean re
