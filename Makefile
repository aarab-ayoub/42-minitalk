# ============================================================================ #
#                                  Minitalk                                    #
# ============================================================================ #

NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CLIENT_SRC = client.c utils.c
SERVER_SRC = server.c utils.c
CLIENT_BONUS_SRC = client_bonus.c utils.c
SERVER_BONUS_SRC = server_bonus.c utils.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)

# Path to the ft_printf library
PRINTF_DIR = 42-ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC = -I$(PRINTF_DIR)

# ANSI escape codes for styling
BOLD = \033[1m
PURPLE = \033[35m
GREEN = \033[32m
BLUE = \033[34m
RESET = \033[0m

# ASCII art for "MINITALK"
MINITALK_ART = "\n\
$(PURPLE)$(BOLD)███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗$(RESET)\n\
$(PURPLE)$(BOLD)████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝$(RESET)\n\
$(PURPLE)$(BOLD)██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ $(RESET)\n\
$(PURPLE)$(BOLD)██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ $(RESET)\n\
$(PURPLE)$(BOLD)██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗$(RESET)\n\
$(PURPLE)$(BOLD)╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝$(RESET)\n\
"

# Success messages
SUCCESS_MSG_CLIENT = "$(GREEN)$(BOLD)✔ Successfully compiled $(CLIENT)!$(RESET)"
SUCCESS_MSG_SERVER = "$(GREEN)$(BOLD)✔ Successfully compiled $(SERVER)!$(RESET)"
CREATED_BY = "$(PURPLE)                                 created by : ayaarab[ESBG] 💜$(RESET)"

.PHONY: all bonus clean fclean re

all: $(PRINTF_LIB) $(CLIENT) $(SERVER)

bonus: $(PRINTF_LIB) $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT): $(CLIENT_OBJ)
	@echo $(MINITALK_ART)
	@echo $(CREATED_BY)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(PRINTF_LIB) $(PRINTF_INC)
	@echo $(SUCCESS_MSG_CLIENT)

$(SERVER): $(SERVER_OBJ)
	@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(PRINTF_LIB) $(PRINTF_INC)
	@echo $(SUCCESS_MSG_SERVER)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ)
	@$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_BONUS_OBJ) $(PRINTF_LIB) $(PRINTF_INC)
	@echo $(SUCCESS_MSG_CLIENT)

$(SERVER_BONUS): $(SERVER_BONUS_OBJ)
	@$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_BONUS_OBJ) $(PRINTF_LIB) $(PRINTF_INC)
	@echo $(SUCCESS_MSG_SERVER)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF_LIB):
	@$(MAKE) -C $(PRINTF_DIR)

clean:
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)
	@echo "$(GREEN)$(BOLD)✔ Cleaned object files!$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@echo "$(GREEN)$(BOLD)✔ Cleaned up done!$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all