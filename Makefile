# Makefile for a C project

.PHONY: bonus all clean fclean re

CORSIVO='\033[3m'
NONE='\033[0m'
GRAY='\033[2;37m'
GREEN='\033[32m'
YELLOW='\033[33m'
WIERD='\033[38;5;206m'

all: server client

server: functions/functions.a server.c
		@echo $(CORSIVO)$(GREEN) "     - MAKE SERVER..."
		@gcc -Wall -Wextra -Werror server.c functions/functions.a -o server

client: functions/functions.a client.c 
		@echo $(CORSIVO)$(YELLOW) "     -              ...MAKE CLIENT"
		@gcc -Wall -Wextra -Werror client.c functions/functions.a -o client

functions/functions.a:
	@echo $(GRAY)"...  ...   ..."	
	make -C functions

clean:
	@echo $(GRAY)"       MAKE CLEAN..."	
	@make -C functions clean
	@rm -f server client

fclean: clean
	@echo $(WIERD)"         MAKE FCLEAN..."
	@make -C functions fclean
	
re: fclean all
	@echo $(WIERD)"    ...     "

