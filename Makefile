# ============================================================================ #
#                                  Minitalk                                    #
# ============================================================================ #

NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT = client
SERVER = server

CLIENT_SRC = client.c utils.c
SERVER_SRC = server.c utils.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

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

all: $(PRINTF_LIB) $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	@echo $(MINITALK_ART)
	@echo $(CREATED_BY)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(PRINTF_LIB) $(PRINTF_INC)
	@echo $(SUCCESS_MSG_CLIENT)

$(SERVER): $(SERVER_OBJ)
	@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(PRINTF_LIB) $(PRINTF_INC)
	@echo $(SUCCESS_MSG_SERVER)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF_LIB):
	@$(MAKE) -s -C $(PRINTF_DIR)

clean:
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	@echo "$(GREEN)$(BOLD)✔ Cleaned object files!$(RESET)"
	@$(MAKE) -s -C $(PRINTF_DIR) clean

fclean: clean
	@rm -f $(CLIENT) $(SERVER)
	@echo "$(GREEN)$(BOLD)✔ Removed $(CLIENT) and $(SERVER)!$(RESET)"
	@$(MAKE) -s -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re