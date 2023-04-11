NAME= pipex

CC= cc
ADR = ./src/
SRC = pipex_utils.o pipex.o error_utils.o
B_SRC = pipex_utils_bonus.o pipex_bonus.o error_utils_bonus.o get_next_line_bonus.o
SRCS = ${addprefix ${ADR}, ${SRC}}
B_SRCS = ${addprefix ${ADR}, ${B_SRC}}
BONUS= $(NAME)
LIBFTA = ./libfta/libft.a

OFLAGS = 
CFLAGS += $(OFLAGS)
CFLAGS +=  -Wall -Wextra -Werror
CFLAGS +=  -I ./include

all : $(NAME)

$(NAME): $(SRCS)
	$(MAKE) -C ./libfta 
	$(CC) $(CFLAGS) ${LIBFTA} $^ -o $@ -g3

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -g3

.PHONY: bonus
bonus : $(B_SRCS)
	$(MAKE) -C ./libfta
	$(CC) $(CFLAGS) ${LIBFTA} $^ -o ${BONUS} -g3

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

