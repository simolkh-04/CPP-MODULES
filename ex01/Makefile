NAME = phonebook

CXX = g++

CXXFLAGS = -Wall -Wextra -Werror

SRC = Contact.cpp main.cpp Phonebook.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re