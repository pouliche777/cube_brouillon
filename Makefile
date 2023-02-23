S = src/
O = obj/
L = libft/
M = mlx/

SOURCES = $Scub3d.c $Sraycasting.c $Smove.c

OBJS = $(SOURCES:$S%=$O%.o)

LIB = libft/libft.a
MLXA = mlx/libmlx.a
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

NAME = cub3d

all: $(NAME)


$O:
	@mkdir $@

$(OBJS): | $O


$(OBJS): $O%.o: $S%
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(L) --silent
	@make -C $(M) --silent
	@$(CC) $(CFLAGS) $(LIB) $(MLXA) -framework OpenGL -framework AppKit $^ -o $@
	@echo "\033[0;32m Compilation complétée"

clean: 
	@$(RM) $(OBJS)
	@$(RM) $O
	@echo "\033[0;31m Fichiers .o supprimés"

fclean:	clean

	@$(RM) $(NAME)
	@echo "\033[0;31m Executable supprimé"


re:	fclean $(NAME)
