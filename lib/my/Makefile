##
## EPITECH PROJECT, 2022
## B-SYN-200-NAN-2-1-sbmlparser-aimeric.rouyer
## File description:
## Makefile
##

SRC		=

OBJ		=     	$(SRC:.c=.o)

NAME	=    	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
