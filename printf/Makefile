NAME = libftprintf.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c -I includes/ft_printf.h sources/*.c
	gcc -Wall -Wextra -Werror -c -I libft/libft.h libft/*.c
	ar rc $(NAME) *.o
	mkdir obj
	mv *.o obj
	ranlib $(NAME)

clean:
	/bin/rm -r -f obj
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all 

.PHONY : clean fclean
