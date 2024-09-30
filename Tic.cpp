#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = { {'1', '2', '3'},
                           {'4', '5', '6'},
                           {'7', '8', '9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    system("clear");  // Clears the console (use "cls" for Windows)
    cout << "Tic-Tac-Toe Game" << endl;
    cout << "Player 1 (X)  -  Player 2 (O)\n\n";

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--|---|--\n";
    }
    cout << endl;
}

bool placeMarker(int slot) {
    int row = (slot - 1) / SIZE;
    int col = (slot - 1) % SIZE;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int checkWin() {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
    }
    // Check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return currentPlayer;

    return 0;
}

void switchPlayer() {
    if (currentPlayer == 1) {
        currentPlayer = 2;
        currentMarker = 'O';
    } else {
        currentPlayer = 1;
        currentMarker = 'X';
    }
}

void game() {
    int playerWon;

    drawBoard();
    for (int i = 0; i < SIZE * SIZE; i++) {
        int slot;
        cout << "Player " << currentPlayer << "'s turn. Enter a slot number: ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already taken! Try again.\n";
            i--;
            continue;
        }

        drawBoard();
        playerWon = checkWin();

        if (playerWon != 0) {
            cout << "Player " << playerWon << " wins! Congratulations!\n";
            return;
        }

        switchPlayer();
    }
    cout << "It's a tie!\n";
}

int main() {
    currentPlayer = 1;
    currentMarker = 'X';

    game();

    return 0;
}
