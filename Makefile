NAME = rpoetess.filler
LIBFT = $(addprefix libft/, libft.a)

SRC = ft_filler.c \
	ft_srch_figure.c \
	ft_crt_map.c \
	ft_preparation.c \
	ft_heatmap.c \
	ft_go_south.c \
	ft_go_north.c \
	ft_go_west.c \
	ft_go_east.c \
	ft_insert_figure.c \
	ft_free.c \

FLS = -Wall -Wextra -g

OBJ = $(SRC:.c=.o)

%.o:%.c
		gcc $(FLS) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ)
	gcc $(FLS) $(OBJ) -o $(NAME) -L libft -lft

clean:
	make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	@/bin/rm -f $(NAME)
	
re: fclean all
