EXEC = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/main.c mandatory/fractal_utils.c mandatory/fractal_init.c mandatory/fractal_render.c mandatory/math_utils.c mandatory/events.c\

SRCB = bonus/main_bonus.c bonus/fractal_utils_bonus.c bonus/fractal_init_bonus.c \
		bonus/fractal_render_bonus.c bonus/math_utils_bonus.c bonus/events_bonus.c\

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