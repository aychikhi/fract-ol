EXEC = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c fractal_utils.c fractal_init.c fractal_render.c math.utils.c events.c\

OBJ = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -LMLX -lMLX -framework OpenGL -framework AppKit -o $(EXEC)

%.o : %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXEC)

re: fclean all
 
.PHONY : clean