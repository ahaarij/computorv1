NAME     = computor
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

SRCS     = src/main.cpp src/Parser.cpp src/Equation.cpp src/Solver.cpp
OBJS     = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all