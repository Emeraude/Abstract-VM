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

DIR	=	./srcs

SRCS	=	$(DIR)/main.cpp \
		$(DIR)/Parser.cpp \
		$(DIR)/VM.cpp

CPPFLAGS	+= -W -Wall -Wextra -Werror
CPPFLAGS	+= -I ./includes

CC	=	g++

RM	=	rm -f

OBJS	=	$(SRCS:.cpp=.o)

%.o: %.cpp
		@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $<
		@$(CC) -c -o $@ $< $(CPPFLAGS)

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CC) $(OBJS) -o $(NAME)
		@printf "[\033[0;36mbuilded\033[0m] % 30s\n" $(NAME)

clean:
		@$(RM) $(OBJS)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJS)

fclean:		clean
		@$(RM) $(NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
