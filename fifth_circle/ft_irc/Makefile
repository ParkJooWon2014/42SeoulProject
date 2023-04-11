# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 14:51:43 by joowpark          #+#    #+#              #
#    Updated: 2023/03/03 16:56:25 by joowpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ircserv
CXX= c++
SRC = CommandManager.o Client.o Server.o main.o Channel.o  
OFLAGS =
CXXFLAGS += $(OFLAGS) -c
CXXFLAGS += -Wall -Wextra -Werror -std=c++98 
CXXFLAGS += #-I ./include  
FSA = #-fsanitize=address -g3 
TARGETS = $(NAME)

all : $(TARGETS)

$(TARGETS): $(SRC)
	$(CXX) $(FSA) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@ $(FSA)

.PHONY : clean
clean:
	rm -f ${SRC}

.PHONY : file
file :
	make re
	make clean

.PHONY : fclean

fclean : clean
	rm -f ${NAME}

.PHONY : re
re : 
	make fclean
	make all
