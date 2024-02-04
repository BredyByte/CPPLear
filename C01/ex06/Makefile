NAME = harlFilter

SRCS = main.cpp Harl.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = -I ./

all: $(NAME)

$(NAME): $(OBJS)
	clang++ -Wall -Wextra -Werror -std=c++98 $(HEADERS) $(OBJS) -o $(NAME)

%.o: %.cpp
	clang++ -Wall -Wextra -Werror $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
