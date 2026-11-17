# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kal-haj- <kal-haj-@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/17 16:26:00 by kal-haj-          #+#    #+#              #
#    Updated: 2026/11/17 16:26:00 by kal-haj-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= brain
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS		= main.cpp Brain.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
HDRS		= Brain.hpp Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp
OBJS		= $(SRCS:.cpp=.o)
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(HDRS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
