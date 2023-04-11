# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joowpark <joowpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 14:51:43 by joowpark          #+#    #+#              #
#    Updated: 2023/01/31 20:46:59 by joowpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= claptrap
CC= c++
SRC = ClapTrap.o main.o
OFLAGS =
CPPFLAGS += $(OFLAGS) -c
CPPFLAGS += -Wall -Wextra -Werror -std=c++98
CPPFLAGS +=  -I ./include

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
