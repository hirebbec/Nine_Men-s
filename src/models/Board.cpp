#include "./../../includes/models/Game.hpp"

Board::Board(sf::RenderWindow& window): m_window(window) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            aiPieces.push_back(Piece(i, j, sf::Color::Black));
            playerPieces.push_back(Piece(i + 5, j + 5, sf::Color::White));
        }
    }
};

void Board::drawfield() {
    // draw board background
    sf::RectangleShape board(sf::Vector2f(BOARD_SIZE, BOARD_SIZE));
    board.setPosition(BOARD_X_POS,BOARD_Y_POS);
    board.setFillColor(sf::Color(209, 177, 138));
    m_window.draw(board);

    // draw board cells
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 4; ++j) {
            sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            int multi = (i % 2 == 0) ? 1 : 0;
            cell.setFillColor(sf::Color(153, 88, 18));
            cell.setPosition((2 * j + multi) * CELL_SIZE, i * CELL_SIZE);
            m_window.draw(cell);
        }
    }
};

void Board::drawPieces() {
    for (auto it = aiPieces.begin(); it != aiPieces.end(); ++it) {
        (*it).draw(m_window);
    }

    for (auto it = playerPieces.begin(); it != playerPieces.end(); ++it) {
        (*it).draw(m_window);
    }
}

std::vector<Piece>& Board::getPlayerPieces(){
    return playerPieces;
}