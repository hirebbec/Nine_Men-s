#ifndef PIECE_HPP
#define PIECE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "Board.hpp"
#include <iostream>

#define RADIUS	30

class Piece {
private:
    int			m_posX;
    int			m_posY;
    sf::Color	m_color;
public:
    bool        m_chosed;
public:
    Piece(int x, int y, sf::Color color);

    void draw(sf::RenderWindow& window);

	int     getPosX();
	int     getPosY();
    bool    isChosed();
	void	move(std::pair<int, int> pos);
};

#endif