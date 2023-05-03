#include "./../../includes/controllers/Game.hpp"
#include "unistd.h"

bool Game::checkChosePlayerPiece() {
	sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
	return (m_board.map[mousePos.y / 100][mousePos.x / 100] == PLAYER_PIECE);
}

bool Game::checkChoseEmpty() {
	sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
	return (m_board.map[mousePos.y / 100][mousePos.x / 100] == EMPTY);
}

Game::Game():	m_window(sf::RenderWindow(sf::VideoMode(WINDOW_HEIGHT, WINDOW_LEANGTH),
				"Nine Men's Morris")), m_player(),  m_board(m_window, m_player.getPieces()), m_turn(false) {};

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
			if (m_turn) {
				m_board.moveAI();
				m_turn = false;
			}
			if (checkWin())
				return;
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
		m_turn = m_board.tryMove(std::make_pair(mousePos.y / 100, mousePos.x / 100));
	}
}

bool Game::checkPlayerWin() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (m_board.map[i][j] != PLAYER_PIECE) {
				return false;
			}		
		}
	}
	sf::Font font;
	if (!font.loadFromFile("./assets/fonts/EndGameFont.ttf")) {
		std::cout << "Player Win!\n";
		return true;
	}
	sf::Text text("Player Win!", font, 50);
	text.setFillColor(sf::Color::Black);
	text.setPosition(330, 330);
	while (m_window.isOpen()) {
		m_window.clear(sf::Color::White);
		m_window.draw(text);
		m_window.display();
	}
	return true;
}

bool Game::checkAIWin() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (m_board.map[i + 5][j + 5] != AI_PIECE) {
				return false;
			}		
		}
	}
	m_window.clear();
	sf::Font font;
	if (!font.loadFromFile("./assets/fonts/EndGameFont.ttf")) {
		std::cout << "AI Win!\n";
		return true;
	}
	sf::Text text("AI Win!", font, 50);
	text.setFillColor(sf::Color::Black);
	text.setPosition(340, 340);
	while (m_window.isOpen()) {
		m_window.clear(sf::Color::White);
		m_window.draw(text);
		m_window.display();
	}
	return true;
}

bool Game::checkWin() {
	return checkPlayerWin() || checkAIWin();
}
