NAME = PmergeMe

OBJ_PATH = obj
SRC = src/

SRCS = $(SRC)main.cpp $(SRC)PmergeMe.cpp

OBJS = $(addprefix obj/,$(notdir $(SRCS:.cpp=.o)))
CFLAG = -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address -O0
HEADERS = -I ./inc

all: $(NAME)

$(NAME): $(OBJS)
	@clang++ $(CFLAG) $(HEADERS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC)%.cpp
	@mkdir -p $(@D)
	clang++ $(CFLAG) $(HEADERS) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
