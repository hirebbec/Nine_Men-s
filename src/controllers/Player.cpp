#include "./../../includes/controllers/Player.hpp"

Player::Player() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m_pieces.push_back(Piece(i + 5, j + 5, sf::Color::White));
        }
    }
}

std::vector<Piece>& Player::getPieces() {
    return m_pieces;
}

void Player::makeMove() {
}
