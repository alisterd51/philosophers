# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 13:07:16 by anclarma          #+#    #+#              #
#    Updated: 2021/07/28 07:13:13 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
C_FILES		= philo.c						\
			  ft.c							\
			  secure_atoi.c					\
			  secure.c						\
			  use_fork.c					\
			  philosophize.c				\
			  life.c						\
			  init_philo.c					\
			  init_table.c
SRCS		= $(addprefix srcs/,$(C_FILES))
OBJS		= $(SRCS:.c=.o)
DEPS		= $(OBJS:.o=.d)
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD	\
			  -I ./includes
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
