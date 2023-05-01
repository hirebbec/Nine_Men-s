#include "./../../includes/models/Board.hpp"

Board::Board(sf::RenderWindow& window, std::vector<Piece>& pieces): m_window(window), playerPieces(pieces) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            aiPieces.push_back(Piece(i, j, sf::Color::Black));
        }
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            map[i][j] = EMPTY;
        }
    }
    for (int i = 0; i < 9; ++i) {
        map[playerPieces[i].getPosY()][playerPieces[i].getPosX()] = PLAYER_PIECE;
        map[aiPieces[i].getPosY()][aiPieces[i].getPosX()] = AI_PIECE;
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
        if ((*it).m_chosed) {

        }
    }

    for (auto it = playerPieces.begin(); it != playerPieces.end(); ++it) {
        (*it).draw(m_window);
        if ((*it).m_chosed) {
            drawMoves(*it);
        }
    }
}

std::vector<Piece>& Board::getPlayerPieces(){
    return playerPieces;
}

Piece* Board::getPiece(int y, int x) {
    for (auto it = playerPieces.begin(); it != playerPieces.end(); ++it) {
        if ((*it).getPosX() == x && ((*it).getPosY() == y)) {
            return &(*it);
        }
    }
    return nullptr;
}

void Board::drawMoves(Piece& piece) {
    auto moves = getLegalMoves(piece);
    for (auto it = moves.begin(); it != moves.end(); ++it) {
        sf::CircleShape move(17);
        move.setFillColor(sf::Color(70, 97, 48));
        move.setPosition(((*it).second)* CELL_SIZE + (CELL_SIZE / 3) , (*it).first * CELL_SIZE + (CELL_SIZE / 3));
        m_window.draw(move);
    }
}

std::vector<std::pair<int, int> > Board::getLegalMoves(Piece& piece) {
    std::vector<std::pair<int, int> > moves;
    int x = piece.getPosX();
    int y = piece.getPosY();
    if (x < 8) {
        if (map[y][x + 1] == EMPTY) {
            moves.push_back(std::make_pair(y, x + 1));
        }
    }
    if (x > 0) {
        if (map[y][x - 1] == EMPTY) {
            moves.push_back(std::make_pair(y, x - 1));
        }
    }
    if (y < 8) {
        if (map[y + 1][x] == EMPTY) {
            moves.push_back(std::make_pair(y + 1, x));
        }
    }
    if (y > 0) {
        if (map[y - 1][x] == EMPTY) {
            moves.push_back(std::make_pair(y - 1, x));
        }
    }
    return moves;
}

bool Board::tryMove(std::pair<int, int> pos) {
    for (auto it = playerPieces.begin(); it != playerPieces.end(); ++it) {
        if ((*it).m_chosed) {
            auto moves = getLegalMoves(*it);
            for (auto mit = moves.begin(); mit != moves.end(); ++mit) {
                if ((*mit) == pos) {
                    std::swap(map[(*it).getPosY()][(*it).getPosX()], map[pos.first][pos.second]);
                    (*it).move(pos);
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}