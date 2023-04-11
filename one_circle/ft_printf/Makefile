NAME= libftprintf.a
CC= gcc 
AR= ar
MAND= ft_flags.o ft_itoa_base.o ft_parse.o ft_print_chrs.o \
	  ft_print_hex.o ft_print_nbr.o ft_print_pointer.o \
	  ft_utils.o ft_printf.o ft_print_format.o 
BONUS= ft_flags_bonus.o ft_itoa_base.o ft_parse_bonus.o ft_print_chrs_bonus.o \
	  ft_print_hex_bonus.o ft_print_nbr_bonus.o ft_print_pointer_bonus.o \
	  ft_utils_bonus.o ft_printf_bonus.o ft_print_format_bonus.o 

OFLAGS = 
CFLAGS += $(OFLAGS) 
CFLAGS +=  -Wall -Wextra -Werror 
TARGETS = $(NAME)

.PHONY : all
all : $(TARGETS)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : ${MAND}
	$(MAKE) -C ./libfta
	cp libfta/libft.a ${NAME}
	$(AR) rcs $@ $^

.PHONY: bonus
bonus : ${BONUS}
	$(MAKE) -C ./libfta
	cp libfta/libft.a ${NAME}
	$(AR) rcs ${NAME} $^
.PHONY: clean
clean:
	$(MAKE) clean -C ./libfta
	rm -f ${MAND} ${BONUS}

.PHONY : fclean
fclean : clean
	rm -f ${NAME}

.PHONY : re
re : fclean all
