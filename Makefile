NAME = libftprintf.a
HEADER = ft_printf.h

SRC = ft_printf.c	\
				ft_isformat.c	\
				ft_format.c	\
				ft_putchar.c	\
				ft_putstr.c	\
				ft_putnbr.c	\
				ft_hexa.c	\
				ft_ptr.c	\
				ft_printu.c
OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
				ar -rcs $@ $^

%.o : %.c
				$(CC) $(FLAGS) -c -o $@ $^

clean :
				$(RM) $(OBJ)

fclean : clean
				$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re