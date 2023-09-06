NAME = fractol
BONUS = fractol_bonus
FLAGS 			= -Wall -Wextra -Werror -g3
LIBFTFLAGS 		= -L ./libft/ -lft
LIBXFLAGS 		= -lmlx -lXext -lX11 -lm -lz

FILES 	= 	actions.c \
			calc_fractol.c \
			fractol_utils.c \
			init_mlx.c \
			julia.c \
			main.c \
			mandelbrot.c \
						
PATH_SRC 		= ./src/
SRCS 			= $(addprefix $(PATH_SRC), $(FILES))
OBJS 			= $(SRCS:.c=.o)
INCLUDES 		= -I ./mandatory/includes -I ./libft

FILES_BONUS =	actions_bonus.c \
				calc_fractol_bonus.c \
				fractol_utils_bonus.c \
				init_mlx_bonus.c \
				julia_bonus.c \
				main_bonus.c \
				mandelbrot_bonus.c \
				tricorn_bonus.c

PATH_SRC_BONUS 	= ./bonus/src_bonus/
SRCS_BONUS 		= $(addprefix $(PATH_SRC_BONUS), $(FILES_BONUS))
OBJS_BONUS 		= $(SRCS_BONUS:.c=.o)
INCLUDES_BONUS 	= -I ./bonus/includes_bonus -I ./libft

all:	$(NAME)

$(NAME): libft/libft.a $(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFTFLAGS) $(LIBXFLAGS) $(INCLUDES)

libft/libft.a : 
	@make -C ./libft --no-print-directory

%.o: $(PATH_SRC)%.c
	cc $(FLAGS) $(INCLUDES) -c $< -o $@

bonus:  $(BONUS)

$(BONUS): libft/libft.a $(OBJS_BONUS)
	cc $(FLAGS) -o $(BONUS) $(OBJS_BONUS) $(LIBFTFLAGS) $(LIBXFLAGS) $(INCLUDES_BONUS)
	
%.o: $(PATH_SRC_BONUS)%.c
	cc $(FLAGS) $(INCLUDES_BONUS) -c $< -o $@

clean:
		rm -rf $(OBJS) $(OBJS_BONUS)
		make -C ./libft clean

fclean:	clean
		rm -rf $(NAME) $(BONUS)
		make -C ./libft fclean

re:		fclean all

# TEST RULES ************************************************************* #
testm:
	@clear
	@make re
	@make bonus
	./fractol_bonus mandelbrot

testj:
	@clear
	@make re
	@make bonus
	./fractol_bonus julia 0.2 0.6

testt:
	@clear
	@make re
	@make bonus
	./fractol_bonus tricorn

.PHONY: all bonus clean fclean re