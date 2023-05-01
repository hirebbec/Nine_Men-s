#ifndef BOARD_HPP
#define BOARD_HPP

#include "Piece.hpp"
#include <vector>
#include <utility>

class Piece;

#define BOARD_SIZE  800
#define CELL_SIZE   (BOARD_SIZE / 8)
#define BOARD_X_POS 0
#define BOARD_Y_POS 0

#define EMPTY			0
#define	PLAYER_PIECE	1
#define AI_PIECE		2

class Board {
private:
    sf::RenderWindow&	m_window;
    std::vector<Piece>	aiPieces;
    std::vector<Piece>	playerPieces;
public:
    int					map[8][8];
public:
	Board(sf::RenderWindow& window, std::vector<Piece>& pieces);
    void drawfield();
    void drawPieces();
    std::vector<Piece>& getPlayerPieces();
	Piece*	getPiece(int y, int x);
	std::vector<std::pair<int, int> > getLegalMoves(Piece& piece);
	bool tryMove(std::pair<int, int> pos);
private:
	void	drawMoves(Piece& (piece));
};

#endif