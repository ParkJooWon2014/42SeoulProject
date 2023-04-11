NAME= philo

CC= cc
ADR = ./src/
SRC = ft_atoi.o ft_parse_input.o ft_philo_utils.o ft_tables.o main.o\
	  philo.o ft_free.o ft_philo_lock.o
SRCS = ${addprefix ${ADR}, ${SRC}}

BONUS= $(NAME)

OFLAGS = 
CFLAGS += $(OFLAGS)
CFLAGS +=  -Wall -Wextra -Werror 
CFLAGS +=  -I ./include 
all : $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS)  $^ -o $@ -g3 
%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -g3

.PHONY : clean
clean:
	rm -f ${SRCS}

.PHONY : fclean

fclean : clean
	rm -f ${NAME} 

.PHONY : re
re : 
	$(MAKE) fclean 
	$(MAKE) all
