#include "./../../includes/models/Game.hpp"

Game::Game():	m_window(sf::RenderWindow(sf::VideoMode(WINDOW_HEIGHT, WINDOW_LEANGTH),
				"Nine Men's Morris")), m_board(m_window) {};

void Game::loop() {
	while (m_window.isOpen()) {
		sf::Event event;
		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				m_window.close();
			}
			if (event.type == sf::Event::MouseMoved) {
				checkMouseCursor();
			}
			m_window.clear(sf::Color::White);
			m_board.drawfield();
			m_board.drawPieces();
			m_window.display();
		}
	}
}

void Game::checkMouseCursor() {
	sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
	sf::Cursor cursor;
	std::vector<Piece> pieces = m_board.getPlayerPieces();
	for (auto it = pieces.begin(); it != pieces.end(); ++it) {
		if (mousePos.x >= ((*it).getPosX() * 100) && mousePos.x <= ((*it).getPosX() * 100 + 100) &&
		mousePos.y >= ((*it).getPosY() * 100) && mousePos.y <= ((*it).getPosY() * 100 + 100)) {
			if (cursor.loadFromSystem(sf::Cursor::Hand)) {
				m_window.setMouseCursor(cursor);
			}
			return;	
		}
	}
	if (cursor.loadFromSystem(sf::Cursor::Arrow)) {
		m_window.setMouseCursor(cursor);
	}
}