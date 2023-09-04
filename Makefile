NAME = fractol
FLAGS 			= -Wall -Wextra -Werror -g3
LIBFTFLAGS 		= -L ./libft/ -lft
LIBXFLAGS 		= -lmlx -lXext -lX11 -lm -lz

FILES 	= 	actions.c \
			calc_fractal.c \
			fractol_utils.c \
			init_mlx.c \
			julia.c \
			main.c \
			mandelbrot.c \
			
			
PATH_SRC 		= ./src/
SRCS 			= $(addprefix $(PATH_SRC), $(FILES))
OBJS 			= $(FILES:.c=.o)
INCLUDES 		= -I ./mandatory/includes -I ./libft

all:	$(NAME)

$(NAME): libft/libft.a $(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFTFLAGS) $(LIBXFLAGS) $(INCLUDES)

libft/libft.a : 
	@make -C ./libft --no-print-directory

%.o: $(PATH_SRC)%.c
	@cc $(FLAGS) $(INCLUDES) -c $< -o $@


clean:
		rm -rf $(OBJS)
		make -C ./libft clean

fclean:	clean
		rm -rf $(NAME)
		make -C ./libft fclean

re:		fclean all