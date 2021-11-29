##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## file making
##

NAME    = myhunter

CC    = gcc

RM    = rm -f

SRC    = myhunter.c			\

OBJ    = $(SRC:.c=.o)

LIBFLAG    = -L ./lib/my/ -lmy -I ./include -g3 -lcsfml-graphics -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME):
	cd ./lib/my/ && make
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)
	$(RM) $(OBJS)

re: fclean all
