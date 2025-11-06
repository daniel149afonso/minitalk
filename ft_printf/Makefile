NAME =	libftprintf.a

SRC_DIR = sources

SRC =	$(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/ft_printstr.c \
		$(SRC_DIR)/ft_strlen_v2.c \
		$(SRC_DIR)/ft_printnbr.c \
		$(SRC_DIR)/ft_printptr.c \
		$(SRC_DIR)/ft_printhex.c \
		$(SRC_DIR)/ft_print_unsigned.c

OBJS = 	$(SRC:.c=.o)

CC = 	gcc
FLAGS =	-Wall -Werror -Wextra
RM =	rm -f
AR =	ar crs

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
