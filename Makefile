
NAME = libftprintf.a
HEAD = libftprintf.h

#COMPIL
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_PATH)

#PARAM
AR = ar rc
RM = rm -f

# LIBFT
LIBFT_PATH = libft
LIBFT_MAKE = libft_Makefile
LIBFT = $(LIBFT_PATH)/libft.a

#SOURCES
SRCS = \
		ft_printf.c\
		ft_strlen.c \
		ft_strchr.c \
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putnbr_fd.c\
		ft_putnbr_hexa.C
	

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@



$(NAME): $(OBJ) $(LIBFT)
	$(AR) $(NAME) $(OBJ)


$(LIBFT):
	make -C $(LIBFT_PATH) -f $(LIBFT_MAKE)
	make -C $(LIBFT_PATH) -f $(LIBFT_MAKE) bonus
	mv $(LIBFT) $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ) 
	make -C $(LIBFT_PATH) -f $(LIBFT_MAKE) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) -f $(LIBFT_MAKE) fclean

re: fclean all
	

.PHONY: all clean fclean re
