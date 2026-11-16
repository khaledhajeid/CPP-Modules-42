# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kal-haj- <kal-haj-@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/16 17:51:50 by kal-haj-          #+#    #+#              #
#    Updated: 2026/11/16 17:51:51 by kal-haj-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bsp
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS		= main.cpp Fixed.cpp Point.cpp bsp.cpp
HDRS		= Fixed.hpp Point.hpp
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
