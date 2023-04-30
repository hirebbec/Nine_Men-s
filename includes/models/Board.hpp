#ifndef BOARD_HPP
#define BOARD_HPP

#include "Piece.hpp"
#include <vector>

class Piece;

#define BOARD_SIZE  800
#define CELL_SIZE   (BOARD_SIZE / 8)
#define BOARD_X_POS 0
#define BOARD_Y_POS 0

class Board {
private:
    sf::RenderWindow&	m_window;
    std::vector<Piece>  aiPieces;
    std::vector<Piece>  playerPieces;
public:
	Board(sf::RenderWindow& window);
    void drawfield();
    void drawPieces();
    std::vector<Piece>& getPlayerPieces();
};

#endif