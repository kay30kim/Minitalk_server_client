# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 21:13:41 by kyung-ki          #+#    #+#              #
#    Updated: 2023/11/14 14:26:14 by kyung-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra

SERVER		=	server
CLIENT		=	client
SERVER_BON	=	server_bonus
CLIENT_BON	=	client_bonus
SERVER_SRCS	=	server.c
CLIENT_SRCS	=	client.c
SER_BON_SRCS=	server_bonus.c
CLI_BON_SRCS=	client_bonus.c

SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)
CLIENT_OBJS	=	$(CLIENT_SRCS:.c=.o)
SER_BON_OBJS=	$(SER_BON_SRCS:.c=.o)
CLI_BON_OBJS=	$(CLI_BON_SRCS:.c=.o)

LIBFT		=	./library/libft
LIBPF		=	./library/ft_printf
LIBS		=	$(LIBFT)/libft.a $(LIBPF)/libftprintf.a
HEADERS		=	-I$(LIBFT)/include -I$(LIBPF)

all : libft libpf $(SERVER) $(CLIENT)

libft :
	$(MAKE) -C $(LIBFT)

libpf :
	$(MAKE) -C $(LIBPF)

%.o: %.c
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

$(SERVER) : $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBS) $(HEADERS) -o $(SERVER)

$(CLIENT) : $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBS) $(HEADERS) -o $(CLIENT)

clean :
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)
	rm -rf $(SER_BON_OBJS) $(CLI_BON_OBJS)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(LIBPF) clean

fclean : clean
	rm -rf $(SERVER) $(CLIENT)
	rm -rf $(SERVER_BON) $(CLIENT_BON)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(LIBPF) fclean

re : fclean all

bonus : libft libpf $(SERVER_BON) $(CLIENT_BON)

$(SERVER_BON) : $(SER_BON_OBJS)
	$(CC) $(CFLAGS) $(SER_BON_OBJS) $(LIBS) $(HEADERS) -o $(SERVER_BON)

$(CLIENT_BON) : $(CLI_BON_OBJS) 
	$(CC) $(CFLAGS) $(CLI_BON_OBJS) $(LIBS) $(HEADERS) -o $(CLIENT_BON)

.PHONY : all libft libpf clean fclean re