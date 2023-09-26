#include <iostream>
using namespace std;

char board[3][3];  // Игровое поле 3x3

void initializeBoard() {
    // Инициализация игрового поля, заполняем пробелами
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void drawBoard() {
    // Отрисовка текущего состояния игрового поля
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << '|';
        }
        cout << endl;
        if (i < 2) cout << "-----" << endl;
    }
}

bool makeMove(char player, int row, int col) {
    // Проверка и размещение символа игрока на поле
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool checkWin(char player) {
    // Проверка на победу по горизонтали, вертикали и диагоналям
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;  // Проверка горизонтали
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;  // Проверка вертикали
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;  // Проверка главной диагонали
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;  // Проверка побочной диагонали
    return false;
}

bool isBoardFull() {
    // Проверка на ничью
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;  // Найдена пустая ячейка, игра продолжается
        }
    }
    return true;  // Нет пустых ячеек, ничья
}

int main() {
    initializeBoard();
    char currentPlayer = 'X';

    while (true) {
        drawBoard();
        int row, col;
        cout << "The trun of " << currentPlayer << "! Write down coordinats (row and column): ";
        cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3) {
            if (makeMove(currentPlayer, row, col)) {
                if (checkWin(currentPlayer)) {
                    drawBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break;
                }
                else if (isBoardFull()) {
                    drawBoard();
                    cout << "Bet!" << endl;
                    break;
                }
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            else {
                cout << "That's unacceptible. Try again." << endl;
            }
        }
        else {
            cout << "Uncorrect coordinats. Put down coordinats from 0 to 2." << endl;
        }
    }

    return 0;
}