# ================== VARIABLES ==================
# Nom de l'exécutable
NAMES = server
NAMEC = client
PRINTF = libftprintf.a

SRCS = server.c
SRCC = client.c

OBJS	=	$(SRCS:.c=.o)
OBJC	=	$(SRCC:.c=.o)

# Compilation
CC			= 		gcc
CFLAGS		= 		-Wall -Wextra -Werror

# Libft et MiniLibX
LIBFT_DIR	= 		./libft
LIBFT		= 		$(LIBFT_DIR)/libft.a

PRINTF_DIR		= 		./ft_printf
PRINTF		= 		$(PRINTF_DIR)/libftprintf.a

# ================== REGLES ==================
all:		$(NAMEC) $(NAMES)

# Compilation de l'exécutable
$(NAMES):	$(OBJS) $(LIBFT) $(PRINTF)
			$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf -o $(NAMES)

$(NAMEC):	$(OBJC) $(LIBFT) $(PRINTF)
			$(CC) $(CFLAGS) $(OBJC) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf -o $(NAMEC)

# Compilation des fichiers .o
%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

# Compilation de la Libft
$(LIBFT):
			@make -C $(LIBFT_DIR)

# Compilation de Ft_printf
$(PRINTF):
			@make -C $(PRINTF_DIR)

# Nettoyage des fichiers objets
clean:
			$(RM) $(OBJS)
			$(RM) $(OBJC)
			@make -C $(LIBFT_DIR) clean
			@make -C $(PRINTF_DIR) clean

# Nettoyage complet
fclean:		clean
			$(RM) $(NAMES)
			$(RM) $(NAMEC)
			@make -C $(LIBFT_DIR) fclean
			@make -C $(PRINTF_DIR) fclean

# Recompile tout
re:			fclean all

.PHONY:		all clean fclean re
