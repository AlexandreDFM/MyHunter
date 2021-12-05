##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## file making
##

NAME    = myhunter

CC    = gcc

RM    = rm -f

SRC    = myhunter.c				\
		 duck.c					\
		 duck_fall.c			\
		 dog.c					\
		 dog2.c					\
		 dog3.c					\
		 systemhunter.c			\
		 systemhunter2.c		\
		 setstructurehunter.c 	\
		 setstructurehunter2.c	\
		 destroystructure.c		\
		 displaymenus.c			\
		 displayscore.c			\
		 gameover.c				\

OBJ    = $(SRC:.c=.o)

LIBFLAG    = -L ./lib/my/ -lmy -I ./include -g3 -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

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
