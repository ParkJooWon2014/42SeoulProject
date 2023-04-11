# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joowpark <joowpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 14:51:43 by joowpark          #+#    #+#              #
#    Updated: 2023/02/05 22:30:10 by joowpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= form
CXX= c++
SRC = Bureaucrat.o Form.o main.o
OFLAGS =
CXXFLAGS += $(OFLAGS) -c
CXXFLAGS += -Wall -Wextra -Werror -std=c++98 -g3
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
