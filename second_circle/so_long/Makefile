NAME= so_long

CC= cc
ADR = ./src/
MLX=./minilibx
SRC = so_long.o ft_free.o ft_parse_input.o ft_render.o ft_keys.o \
	   ft_utils.o ft_valid_map.o get_next_line.o ft_game.o
B_SRC = 
SRCS = ${addprefix ${ADR}, ${SRC}}
#B_SRCS = ${addprefix ${ADR}, ${B_SRC}}
BONUS= $(NAME)
LIBFTA = ./libfta/libft.a

OFLAGS = 
CFLAGS += $(OFLAGS) 
CFLAGS +=  -Wall -Wextra -Werror
CFLAGS +=  -I ./include

all : $(NAME)

$(NAME): $(SRCS)
	$(MAKE) -C ./libfta 
	$(CC) $(CFLAGS) ${LIBFTA} -L ${MLX} -lmlx -framework OpenGL -framework AppKit  $^ -o $@ -g3

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -g3  -Imlx

.PHONY: libft
libft :
	$(MAKE) -C libfta re

.PHONY : clean
clean:
	rm -f ${SRCS} ${B_SRCS}
	$(MAKE) -C libfta clean

.PHONY : fclean

fclean : clean
	rm -f ${NAME}
	$(MAKE) -C libfta fclean
.PHONY : re
re : 
	$(MAKE) fclean 
	$(MAKE) all
