# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joowpark <joowpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 14:51:43 by joowpark          #+#    #+#              #
#    Updated: 2023/02/01 22:18:22 by joowpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= scavtrap
CC= c++
SRC = ScavTrap.o ClapTrap.o main.o
OFLAGS =
CPPFLAGS += $(OFLAGS) -c
CPPFLAGS += -Wall -Wextra -Werror -std=c++98

TARGETS = $(NAME)

all : $(TARGETS)

$(TARGETS): $(SRC)
	$(CC) -o $@ $^ -g

%.o : %.cpp
	$(CC) $(CPPFLAGS) $^ -o $@ -g

.PHONY : clean
clean:
	rm -f ${SRC}

.PHONY : fclean

fclean : clean
	rm -f ${NAME}

.PHONY : re
re : 
	make fclean
	make all
