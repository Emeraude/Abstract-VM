##
## Makefile for Makefile in /home/jacob_f/gitlab/Abstract_VM
## 
## Made by felix jacob
## Login   <jacob_f@epitech.net>
## 
## Started on  Mon Feb 16 22:57:41 2015 felix jacob
## Last update Mon Feb 16 23:03:16 2015 felix jacob
##

NAME	=	avm

CPP	=	g++

RM	=	rm -f

CPPFLAGS	+= -W -Wall -Wextra -Werror
CPPFLAGS	+= -I ./includes

DIR	=	./srcs

SRCS	=	$(DIR)/main.cpp \
		$(DIR)/VM.cpp

OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CPP) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
