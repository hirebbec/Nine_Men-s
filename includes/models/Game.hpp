#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"

#define WINDOW_HEIGHT	800
#define WINDOW_LEANGTH	800

class Game {
private:
    sf::RenderWindow	m_window;
    Board				m_board;
public:
	Game();

	void loop();
private:
	void checkMouseCursor();
};

#endif