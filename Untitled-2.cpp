#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void printBoard() {
    cout << "\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "---------\n";
    }
    cout << "\n";
}

bool isValidMove(int choice) {
    if (choice < 1 || choice > 9) return false;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    return board[row][col] != 'X' && board[row][col] != 'O';
}

void makeMove(int choice, char player) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    board[row][col] = player;
}

char checkWinner() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return '\0';
}

int main() {
    char currentPlayer = 'X';
    int move;

    cout << "=== Game XO ===\n";
    printBoard();

    for (int turns = 0; turns < 9; turns++) {
        cout << "Player " << currentPlayer << " : choose a box (1-9): ";
        cin >> move;

        if (!isValidMove(move)) {
            cout << "Invalid move. Try again.\n";
            turns--;
            continue;
        }

        makeMove(move, currentPlayer);
        printBoard();

        char winner = checkWinner();
        if (winner == 'X' || winner == 'O') {
            cout << "Player " << winner << " wins!\n";
            return 0;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Draw! No winner.\n";
    return 0;
}