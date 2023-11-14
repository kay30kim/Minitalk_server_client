# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 21:13:41 by kyung-ki          #+#    #+#              #
#    Updated: 2023/11/13 22:50:07 by kyung-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra

SERVER		=	server
CLIENT		=	client
SERVER_SRCS	=	server.c
CLIENT_SRCS	=	client.c

SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)
CLIENT_OBJS	=	$(CLIENT_SRCS:.c=.o)

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
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(LIBPF) clean

fclean : clean
	rm -rf $(SERVER) $(CLIENT)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(LIBPF) fclean

re : fclean all
