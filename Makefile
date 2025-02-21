# ================== VARIABLES ==================
# Nom de l'exécutable
NAMES = server
NAMEC = client
PRINTF = libftprintf.a

SRCS = server.c
SRCC = client.c

OBJS	=	$(SRCS:.c=.o)
OBJC	=	$(SRCC:.c=.o)

# Nom des exécutables bonus
NAMES_BONUS = server_bonus
NAMEC_BONUS = client_bonus

SRCS_BONUS = server_bonus.c
SRCC_BONUS = client_bonus.c

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
OBJC_BONUS	=	$(SRCC_BONUS:.c=.o)

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

# Compilation des exécutables bonus
bonus:		$(NAMEC_BONUS) $(NAMES_BONUS)

$(NAMES_BONUS): $(OBJS_BONUS) $(LIBFT) $(PRINTF)
			$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf -o $(NAMES_BONUS)

$(NAMEC_BONUS): $(OBJC_BONUS) $(LIBFT) $(PRINTF)
			$(CC) $(CFLAGS) $(OBJC_BONUS) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf -o $(NAMEC_BONUS)

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
			$(RM) $(OBJS) $(OBJC) $(OBJS_BONUS) $(OBJC_BONUS)
			@make -C $(LIBFT_DIR) clean
			@make -C $(PRINTF_DIR) clean

# Nettoyage complet
fclean:		clean
			$(RM) $(NAMES) $(NAMEC) $(NAMES_BONUS) $(NAMEC_BONUS)
			@make -C $(LIBFT_DIR) fclean
			@make -C $(PRINTF_DIR) fclean

# Recompile tout
re:			fclean all

.PHONY:		all clean fclean re bonus
