.PHONY: bonus all clean fclean re

all: server client

server: functions/functions.a server.c
		gcc -Wall -Wextra -Werror server.c functions/functions.a -o server

client: functions/functions.a client.c 
		gcc -Wall -Wextra -Werror client.c functions/functions.a -o client

functions/functions.a:
	make -C functions
clean:
	make -C functions clean
	rm -f server client

fclean: clean
	make -C functions fclean
	
re: fclean all

