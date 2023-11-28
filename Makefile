##
## EPITECH PROJECT, 2023
## my_hunter
## File description:
## Infos
##

CFLAGS	= 	-W -Wall -Wextra

SRCLIB	=	lib/my_atoi.c 	\

SRCNAME	=	main.c		\
			play.c 	\


LIB = libmy.a

OBJLIB	=	$(SRCLIB:.c=.o)

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

NAME	=	my_hunter

UNAME   :=	$(shell uname -s)

1 = -I/opt/homebrew/Cellar/csfml/2.5.2_1/include/

2 = -L/opt/homebrew/Cellar/csfml/2.5.2_1/lib

$(NAME) : $(LIB) $(OBJNAME)

ifeq ($(UNAME),Linux)
	gcc -o $(NAME) $(SRCNAME) -lmy -L./ $(CSFML) $(CFLAGS)
else ifeq ($(UNAME),Darwin)
	gcc -o $(NAME) $(SRCNAME) -lmy -L./ $(CSFML) $(1) $(2) -g3 $(CFLAGS)
endif

$(LIB) : $(OBJLIB)
	ar rc libmy.a lib/*.o

all:	$(LIB) $(NAME)

clean:
	rm -f $(OBJLIB) $(OBJNAME) libmy.a

fclean: clean
	rm -f $(NAME)

re: 	fclean all
