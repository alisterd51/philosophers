# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 13:07:16 by anclarma          #+#    #+#              #
#    Updated: 2021/07/29 19:56:09 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo_bonus
C_FILES		= philo_bonus.c					\
			  secure_atoi.c					\
			  ft.c							\
			  life.c
SRCS		= $(addprefix srcs/,$(C_FILES))
OBJS		= $(SRCS:.c=.o)
DEPS		= $(OBJS:.o=.d)
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD	\
			  -I ./includes
#-fsanitize=address -fsanitize=leak -g3
#-fsanitize=thread -g3
CLIBS		= -lpthread

all:		$(NAME)

-include	$(DEPS)
.c.o:
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(CFLAGS) $(CLIBS) -o $(NAME)

clean:
			rm -f $(OBJS) $(DEPS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
