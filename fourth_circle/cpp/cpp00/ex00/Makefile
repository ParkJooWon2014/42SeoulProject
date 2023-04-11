# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joowpark <joowpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 14:51:43 by joowpark          #+#    #+#              #
#    Updated: 2023/01/31 12:16:16 by joowpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= megaphone
CC= c++
SRC = megaphone.o
OFLAGS =
CFLAGS += $(OFLAGS) -c
CFLAGS += -Wall -Wextra -Werror -std=c++98
CFLAGS +=  -I ./include

TARGETS = $(NAME)

all : $(TARGETS)

$(TARGETS): $(SRC)
	$(CC) -o $@ $^ -g

%.o : %.cpp
	$(CC) $(CFLAGS) $^ -o $@ -g

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
