#include "./../../includes/controllers/Game.hpp"

bool Game::checkChosePlayerPiece() {
	sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
	return (m_board.map[mousePos.y / 100][mousePos.x / 100] == PLAYER_PIECE);
}

bool Game::checkChoseEmpty() {
	sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
	return (m_board.map[mousePos.y / 100][mousePos.x / 100] == EMPTY);
}

Game::Game():	m_window(sf::RenderWindow(sf::VideoMode(WINDOW_HEIGHT, WINDOW_LEANGTH),
				"Nine Men's Morris")), m_player(),  m_board(m_window, m_player.getPieces()) {};

void Game::loop() {
	while (m_window.isOpen()) {
		sf::Event event;
		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				m_window.close();
			}
			if (event.type == sf::Event::MouseMoved) {
				checkMouseCursor();
			} else if (event.type == sf::Event::MouseButtonReleased) {
				checkMouseChose();
			}
			
			m_window.clear(sf::Color::White);
			m_board.drawfield();
			m_board.drawPieces();
			m_window.display();
		}
	}
}

void Game::checkMouseCursor() {
	sf::Cursor cursor;
	if (checkChosePlayerPiece()) {
		if (cursor.loadFromSystem(sf::Cursor::Hand)) {
			m_window.setMouseCursor(cursor);
		}
		return;
	}
	if (cursor.loadFromSystem(sf::Cursor::Arrow)) { // TODO: cursor error
		m_window.setMouseCursor(cursor);
	}
}

void Game::checkMouseChose() {
	sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
	if (checkChosePlayerPiece()) {
		for (auto it = m_board.getPlayerPieces().begin(); it != m_board.getPlayerPieces().end(); ++it) {
			(*it).m_chosed = false;
		}
		m_board.getPiece(mousePos.y / 100, mousePos.x / 100)->m_chosed = true;
		return;
	} else if (checkChoseEmpty()) {
		m_board.tryMove(std::make_pair(mousePos.y / 100, mousePos.x / 100));
	}
}