#include "./../../includes/models/Piece.hpp"

Piece::Piece(int x, int y, sf::Color color): m_posX(x), m_posY(y),
            m_color(color), m_chosed(false) {};

void Piece::draw(sf::RenderWindow& window) {
    sf::CircleShape  piece(RADIUS);
    piece.setFillColor(m_color);
    if (m_chosed) {
        sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        cell.setFillColor(sf::Color(70, 97, 48));
        cell.setPosition(m_posX * CELL_SIZE, m_posY * CELL_SIZE);
        window.draw(cell);
    }
    piece.setPosition(m_posX * CELL_SIZE + (CELL_SIZE / 5) , m_posY * CELL_SIZE + (CELL_SIZE / 5));
    window.draw(piece);
}

int Piece::getPosX() {
    return m_posX;
}

int Piece::getPosY() {
    return m_posY;
}

void Piece::move(std::pair<int, int> pos) {
    m_posX = pos.second;
    m_posY = pos.first;
}