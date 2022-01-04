NAME = pipex

CC = gcc

HEADER = pipex.h

#CFLAGS = -Wall -Wextra -Werror -I $(HEADER)
CFLAGS = -I $(HEADER) #КЛОУНСКАЯ СТРОКА

SRC = pipex.c pipex_utils.c

OBJ = $(SRC:c=o)

SRCB = pipex_bonus.c pipex_utils.c

OBJB = $(SRCB:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compilation of $(NAME)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo Compilation done!

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@
# $< - Имя первого пререквизита (подставляется первая зависимость).
# $@ - Имя файла цели обрабатываемого правила.

clean:
	@echo Deleting .o files
	@rm -f $(OBJ)
	@echo Deleting done!

fclean: clean
	@echo Deleting $(NAME)
	@rm -f $(OBJ) $(OBJB)
	@rm -f $(NAME)
	@echo Deleting done!

re: fclean all

bonus: $(OBJB)
	@echo Bonus part compilation
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJB)
	@echo Compilation done!

.PHONY: clean fclean re bonus