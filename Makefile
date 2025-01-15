EXEC = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/fractal_utils.c src/fractal_init.c src/fractal_render.c src/math_utils.c src/events.c\

SRCB = src_bonus/main_bonus.c src_bonus/fractal_utils_bonus.c src_bonus/fractal_init_bonus.c \
		src_bonus/fractal_render_bonus.c src_bonus/math_utils_bonus.c src_bonus/events_bonus.c\

OBJ = $(SRC:.c=.o)

OBFB = $(SRCB:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -LMLX -lMLX -framework OpenGL -framework AppKit -o $(EXEC)

bonus: $(OBFB)
	$(CC) $(CFLAGS) $(OBFB) -LMLX -lMLX -framework OpenGL -framework AppKit -o $(EXEC)

clean:
	rm -rf $(OBJ) $(OBFB)

fclean: clean
	rm -rf $(EXEC)

re: fclean all
 
.PHONY : clean