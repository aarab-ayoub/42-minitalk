NAME = minitalk
CLIENT = client
SERVER = server
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)

$(CLIENT): client.c
	$(CC) $(CFLAGS) client.c -o $(CLIENT)

$(SERVER): server.c
	$(CC) $(CFLAGS) server.c -o $(SERVER)

clean:
	rm -f $(CLIENT) $(SERVER)

fclean: clean

re: fclean all

.PHONY: all clean fclean re