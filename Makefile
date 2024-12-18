CC = gcc 
GFLAGS= -Werror -Wall -Wextra
SRCS = srcs/main.c srcs/so_long_utils.c srcs/check_params.c gnl/get_next_line_utils.c gnl/get_next_line.c
NAME= so_long
LIB= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -Llibft -Lprintf -lftprintf

OBJS = $(SRCS:.c =.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(GFLAGS) $(OBJS) $(LIB) -o $(NAME)

#%.o: %.c
#	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f srcs/*.o

fclean: clean
	rm -f ${NAME}

re: clean fclean ${NAME}

gdev: copy
	git add .
	git commit -m ${NAME}
	git push

copy:
	cd .. && cd 42-katas && rm -rf ${NAME}
	cd ..  
	cp -rf ${NAME}  ../42-katas/
	cd 	.. && cd  42-katas &&  git add . && git commit -m ${NAME} && git push 


libft:
	rm -rf libft
	cp -rf ../42-katas/libft .


.PHONY: re all clean fclean so_long copy libft