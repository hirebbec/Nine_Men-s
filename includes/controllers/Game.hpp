#ifndef GAME_HPP
#define GAME_HPP

#include "./../models/Board.hpp"
#include "Player.hpp"

#define WINDOW_HEIGHT	800
#define WINDOW_LEANGTH	800

class Game {
private:
    sf::RenderWindow	m_window;
	Player				m_player;
    Board				m_board;
public:
	Game();

	void loop();
private:
	void checkMouseCursor();
	void checkMouseChose();
	bool checkChosePlayerPiece();
	bool checkChoseEmpty();
};

#endif