NAME= push_swap

CC= cc
ADR = ./src/
SRC = ft_free.o ft_node.o ft_node.o ft_node_utils.o \
	  ft_parse_input.o ft_sort_in_tab.o ft_stack.o \
	  ft_stack_utils.o main.o push_swap.o push_swap_three.o \
	  swap_operator.o ft_find_node.o

B_SRC = ft_free.o ft_node.o ft_node.o ft_node_utils.o \
	  ft_parse_input.o ft_sort_in_tab.o ft_stack.o \
	  ft_stack_utils.o push_swap.o push_swap_three.o \
	  swap_operator.o ft_find_node.o checker.o checker_operator.o get_next_line.o
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
	$(CC) $(CFLAGS) ${LIBFTA} $^ -o checker -g3

.PHONY: libft
libft :
	$(MAKE) -C libfta re

.PHONY : clean
clean:
	rm -f ${SRCS} ${B_SRCS}
	$(MAKE) -C libfta clean

.PHONY : fclean

fclean : clean
	rm -f ${NAME} checker
	$(MAKE) -C libfta fclean
.PHONY : re
re : 
	$(MAKE) fclean 
	$(MAKE) all
