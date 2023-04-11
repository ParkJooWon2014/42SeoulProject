NAME= philo

CC= cc
ADR = ./src/
SRC = ft_atoi.o ft_parse_input.o ft_philo_utils.o ft_tables.o main.o\
	  philo.o ft_free.o ft_philo_other_utils.o ft_itoa.o ft_philo_moniter.o
SRCS = ${addprefix ${ADR}, ${SRC}}
BONUS= $(NAME)

OFLAGS = 
CFLAGS += $(OFLAGS)
CFLAGS +=  -Wall -Wextra -Werror
CFLAGS +=  -I ./include
all : $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS)  $^ -o $@ 
%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ 

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
