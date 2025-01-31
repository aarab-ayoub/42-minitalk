# ============================================================================ #
#                                  Minitalk                                    #
# ============================================================================ #

NAME = minitalk
CC = cc
# CFLAGS = -Wall -Wextra -Werror

CLIENT = client
SERVER = server

CLIENT_SRC = client.c utils.c
SERVER_SRC = server.c utils.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

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


all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	@echo $(MINITALK_ART)
	@echo $(CREATED_BY)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ)
	@echo $(SUCCESS_MSG_CLIENT)

$(SERVER): $(SERVER_OBJ)
	@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ)
	@echo $(SUCCESS_MSG_SERVER)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	@echo "$(GREEN)$(BOLD)✔ Cleaned object files!$(RESET)"

fclean: clean
	@rm -f $(CLIENT) $(SERVER)
	@echo "$(GREEN)$(BOLD)✔ Removed $(CLIENT) and $(SERVER)!$(RESET)"

re: fclean all

.PHONY: all clean fclean re