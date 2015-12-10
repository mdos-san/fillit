NAME=		fillit

COMPILER=	gcc
FLAGS=		-Wall -Werror -Wextra -I.
LIB=		libft.a

SRC_C=		create_double_tab.c		init_double_tab.c\
			display_double_tab.c	add_tetrimino.c\
			check_place.c			free_double_tab.c\
			tetri_new.c				tetri_add.c\
			init_shape.c			fillit.c\
			tetri_count.c			ft_sqrt.c\
			main.c					file_valide.c

SRC_O=	$(SRC_C:.c=.o)

all: libft.a libft.h $(NAME)

$(NAME): $(SRC_O)
	$(COMPILER) $(FLAGS) -o $(NAME) $(SRC_O) $(LIB)
	@echo "\033[32m=======FILLIT HAS BEEN CREATED=======\033[0m"

%.o: %.c
	$(COMPILER) $(FLAGS) -c $<

libft.a:
	@echo "\033[32m==================================="
	@echo "==========COMPILING LIBFT=========="
	@echo "===================================\033[0m"
	make re -C ./libft/
	cp libft/libft.a .
	make fclean -C ./libft/
	
libft.h:
	cp ./libft/includes/libft.h .

clean:
	@echo "\033[33m==========REMOVING OBJ FILES==========\033[0m"
	rm -rf $(SRC_O)

fclean: clean
	@echo "\033[31m==========REMOVING BIN FILES==========\033[0m"
	rm -rf $(NAME) libft.a
	rm -rf $(NAME) libft.h

re: fclean all
