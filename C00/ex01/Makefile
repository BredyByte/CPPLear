NAME = PhoneBook

SRCS = main.cpp PhoneBook.cpp Contact.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = -I ./

all: $(NAME)

$(NAME): $(SRCS)
	clang++ -Wall -Wextra -Werror -std=c++98 $(HEADERS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all
