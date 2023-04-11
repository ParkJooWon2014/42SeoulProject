# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joowpark <joowpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 14:51:43 by joowpark          #+#    #+#              #
#    Updated: 2023/02/11 13:37:54 by joowpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= span
CXX= c++
SRC = Span.o main.o
OFLAGS =
CXXFLAGS += $(OFLAGS) -c
CXXFLAGS += -Wall -Wextra -Werror -std=c++98
CXXFLAGS +=  -I ./include

TARGETS = $(NAME)

all : $(TARGETS)

$(TARGETS): $(SRC)
	$(CXX) -o $@ $^ -g

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@ -g

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
