
NAME = libftprintf.a
HEAD = ft_printf.h

#COMPIL
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_PATH)

#PARAM
AR = ar rc
RM = rm -f

# LIBFT
LIBFT_PATH = libft_1
LIBFT_MAKE = libft_Makefile
LIBFT = $(LIBFT_PATH)/libft.a

#SOURCES
SRCS = \
		ft_printf.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putnbr.c\
		ft_putnbr_hexa.c\
		ft_findformat.c\
		ft_printpointer.c\
		ft_putnbr_unsigned.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@



$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(NAME) $(OBJS)


$(LIBFT):
	make -C $(LIBFT_PATH) -f $(LIBFT_MAKE)
	mv $(LIBFT) $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS) 
	make -C $(LIBFT_PATH) -f $(LIBFT_MAKE) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) -f $(LIBFT_MAKE) fclean

re: fclean all
	

.PHONY: all clean fclean re
