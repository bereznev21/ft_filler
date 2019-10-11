NAME = libftfiller.a

SRC = ft_filler.c \
	ft_srch_figure.c \
	ft_crt_map.c \
	ft_preparation.c \
	ft_heatmap.c \
	ft_algo_heat_map.c \

FLS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft
	gcc -c $(SRC) -I libft
	@cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	@/bin/rm -f $(NAME)
	
re: fclean all
