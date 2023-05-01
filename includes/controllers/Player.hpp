#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "./../models/Piece.hpp"

class Player {
private:
    std::vector<Piece> m_pieces;
public:
    Player();
    std::vector<Piece>& getPieces();
	void makeMove();
};

#endif