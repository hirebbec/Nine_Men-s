#include "./../../includes/models/Piece.hpp"

Piece::Piece(int x, int y, sf::Color color): m_posX(x), m_posY(y),
            m_color(color) {};

void Piece::draw(sf::RenderWindow& window) {
    sf::CircleShape  piece(RADIUS);
    piece.setFillColor(m_color);
    piece.setPosition(m_posX * CELL_SIZE + (CELL_SIZE / 5) , m_posY * CELL_SIZE + (CELL_SIZE / 5));
    window.draw(piece);
}

int Piece::getPosX() {
    return m_posX;
}

int Piece::getPosY() {
    return m_posY;
}