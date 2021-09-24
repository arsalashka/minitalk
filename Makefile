# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maearly <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 16:34:47 by maearly           #+#    #+#              #
#    Updated: 2021/06/11 16:34:51 by maearly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server
NAME2 = client

LIST1 =			server.c loop.c utils.c utils2.c
LIST2 =			client.c utils.c utils2.c

OBJ1 = $(patsubst %.c,%.o,$(LIST1))
OBJ2 = $(patsubst %.c,%.o,$(LIST2))

D_FILES1 = $(patsubst %.c,%.d,$(LIST1))
D_FILES2 = $(patsubst %.c,%.d,$(LIST2))

OTPFLAGS = -O2

FLAGS = -Wall -Wextra -Werror

all :	$(NAME1) $(NAME2)

bonus:	all

$(NAME1) :	$(OBJ1)
	gcc $(FLAGS) $(OPTFLAGS) $(OBJ1) -o $(NAME1)

$(NAME2) :	$(OBJ2)
	gcc $(FLAGS) $(OPTFLAGS) $(OBJ2) -o $(NAME2)

%.o : %.c
	gcc $(FLAGS) $(OPTFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean :
	rm -f $(OBJ1) $(OBJ2) $(D_FILES1) $(D_FILES2)

fclean : clean
	rm -f $(NAME1) $(NAME2) $(D_FILES1) $(D_FILES2)

re : fclean all

.PHONY : all clean fclean re