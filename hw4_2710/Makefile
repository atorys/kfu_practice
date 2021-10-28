NAME = hw4

FILES = main.cpp \
		n1.cpp	\
		n2.cpp	\
		n3.cpp	\
		array_utils.cpp \

HEADER = array_utils.hpp

all:	$(NAME)

$(NAME): $(HEADER) $(FILES)
		g++ $(FILES) -o $(NAME)

clean:
		rm $(NAME)

re: clean all