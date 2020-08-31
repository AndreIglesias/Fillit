#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 19:19:55 by ciglesia          #+#    #+#              #
#    Updated: 2020/09/01 01:24:01 by ciglesia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fillit
DIRSRC		=	./src/
DIROBJ		=	./depo/

SUB_MAKE	=	./libft/
INCLUDE		=	-I libft/include
INC_LIB		=	-L./libft/ -lft

SRC			=	fillit.c identify.c solve.c treatment.c treatment2.c

OAUX		=	$(SRC:%=$(DIROBJ)%)
DEPS		=	$(OAUX:.c=.d)
OBJS		=	$(OAUX:.c=.o)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g
	endif
else
CFLAGS		=	-Wall -Wextra -Werror
endif

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e

%.o		:		../$(DIRSRC)/%.c
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

$(NAME)	:		submake $(OBJS)
				@$(CC) $(INCLUDE) $(CFLAGS) -o $(NAME) $(OBJS) $(INC_LIB)
				@$(ECHO) '> Compiled'

clean	:
				@($(RM) $(OBJS))
				@($(RM) $(DEPS))
				@(cd $(SUB_MAKE) && $(MAKE) clean)
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
				@(cd $(SUB_MAKE) && $(MAKE) fclean)
				@$(RM) $(NAME)
				@$(ECHO) '> Remove executable'

re		:		fclean all

submake	:
				@(cd $(SUB_MAKE) && $(MAKE))

.PHONY	:		all clean re

-include $(DEPS)
