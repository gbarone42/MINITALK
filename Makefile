all: server client

server:
	 make -C functions 
		gcc -Wall -Wextra -Werror server.c functions/functions.a -o server

client: 
	make -C functions
	gcc -Wall -Wextra -Werror client.c functions/functions.a -o client
clean:
	make -C functions clean

fclean: clean
	rm -f server client 
	 make -C functions fclean

re: fclean all

.PHONY: bonus all clean fclean re

