
NAME	=	bin/game

CC		=	g++
CFLAGS	=	-Wall -Wextra -Werror
LFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lGL
RM		=	rm -f

FILES	=	src/main.cpp			src/controllers/Game.cpp		src/models/Board.cpp \
			src/models/Piece.cpp	src/controllers/Player.cpp		src/controllers/AI.cpp			
OBJS	=	$(FILES:%.cpp=%.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LFLAGS)  

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re