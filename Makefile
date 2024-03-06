# Compilers & Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIB_DIR = libft/
OBJ_DIR = obj/

# Files
CLIENT_SRC = client.c
SERVER_SRC = server.c
LIBFT = $(LIB_DIR)libft.a
CLIENT = client
SERVER = server

# Rules & Recipes
all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	make -C $(LIB_DIR)

$(CLIENT): $(CLIENT_SRC)
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIB_DIR) -lft

$(SERVER): $(SERVER_SRC)
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIB_DIR) -lft

clean:
	rm -f $(CLIENT) $(SERVER)
	make -C $(LIB_DIR) clean

re: clean all

.PHONY: all clean re
