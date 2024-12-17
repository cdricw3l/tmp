CC = gcc 
GFLAGS= -Werror -Wall- Wextra
SRCS = srcs/main.c 
NAME= so_long



$(NAME): $(OBJ)
	$(CC) $(OBJ) ${SRCS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f srcs/*.o
fclean: clean
	rm -f ${NAME}