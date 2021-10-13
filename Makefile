NAME_SRV=server
NAME_CL=client
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
all: $(NAME_SRV) $(NAME_CL)

$(NAME_SRV):
	make -C ./ft_printf
	make -C ./libft
	gcc -Wall -Werror -Wextra -o server server.c $(LIBFT) $(PRINTF)

$(NAME_CL):
	make -C ./libft
	make -C ./ft_printf
	gcc -Wall -Werror -Wextra -o client client.c $(LIBFT) $(PRINTF)

clean:
	cd libft && make clean
	cd ft_printf && make clean

fclean: clean
	cd libft && make fclean
	cd ft_printf && make fclean
	rm -f server client

re: fclean all

bonus:
	make -C ./libft
	make -C ./ft_printf
	gcc -Wall -Werror -Wextra -o server server_bonus.c $(LIBFT) $(PRINTF)
	gcc -Wall -Werror -Wextra -o client client_bonus.c $(LIBFT) $(PRINTF)

