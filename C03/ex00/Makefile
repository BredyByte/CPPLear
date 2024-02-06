NAME = program

SRCS = main.cpp ClapTrap.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAG = -Wall -Wextra -Werror -std=c++98

HEADERS = -I ./

all: $(NAME)

$(NAME): $(OBJS)
	clang++ $(CFLAG) $(HEADERS) $(OBJS) -o $(NAME)

%.o: %.cpp
	clang++ $(CFLAG) $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
