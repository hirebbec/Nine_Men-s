#ifndef AI_HPP
#define AI_HPP

#include <vector>
#include "./../models/Piece.hpp"

class AI {
private:
    std::vector<Piece>  m_pieces;
public:
    AI();
    std::vector<Piece>& getPieces();
};

#endif