#include "./../../includes/controllers/AI.hpp"
#include <random>

AI::AI() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m_pieces.push_back(Piece(i, j, sf::Color::Black));
        }
    }
}

std::vector<Piece>& AI::getPieces() {
    return m_pieces;
}