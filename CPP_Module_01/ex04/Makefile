NAME		= sedIsForLosers
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)
TEST		= runTests
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

test: $(NAME)
	$(CXX) $(CXXFLAGS) tests.cpp -o $(TEST)
	./$(TEST)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(TEST)

re: fclean all

.PHONY: all test clean fclean re
