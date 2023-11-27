NAME = libftprintf.a

SRC = \
	ft_strlen.c \
	ft_strchr.c \
	ft_atoi.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_itoa.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_substr.c\
	


OBJ = $(SRC:.c=.o)


HEAD = libftprintf.h
AR = ar rc

CC = cc
CFLAGS = -Wall -Wextra -Werror


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)


clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
