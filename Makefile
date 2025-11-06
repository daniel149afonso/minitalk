# ================== VARIABLES ==================
NAMEC = client
NAMES = server
NAMEC_BONUS = client_bonus
NAMES_BONUS = server_bonus

DIR = src
SRCS = $(DIR)/server.c
SRCC = $(DIR)/client.c
SRCS_BONUS = $(DIR)/server_bonus.c
SRCC_BONUS = $(DIR)/client_bonus.c

OBJS = $(SRCS:.c=.o)
OBJC = $(SRCC:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJC_BONUS = $(SRCC_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

# ================== RULES ==================
all: $(NAMEC) $(NAMES)
	@echo "\033[1;32m✔ Compilation successful!\033[0m"

$(NAMES): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf -o $@
	@echo "Built: $@"

$(NAMEC): $(OBJC) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJC) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf -o $@
	@echo "Built: $@"

bonus: $(NAMEC_BONUS) $(NAMES_BONUS)
	@echo "\033[1;32m✔ Bonus compiled successfully!\033[0m"

$(NAMES_BONUS): $(OBJS_BONUS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf -o $@
	@echo "Built: $@"

$(NAMEC_BONUS): $(OBJC_BONUS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJC_BONUS) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf -o $@
	@echo "Built: $@"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

clean:
	@$(RM) $(OBJS) $(OBJC) $(OBJS_BONUS) $(OBJC_BONUS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@echo "🧹 Cleaned objects."

fclean: clean
	@$(RM) $(NAMEC) $(NAMES) $(NAMEC_BONUS) $(NAMES_BONUS)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@echo "🗑 Full clean done."

re: fclean all

.PHONY: all clean fclean re bonus
