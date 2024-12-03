#include <iostream>
#include <cmath>
using namespace std;

// Function to check if there is a winner
bool checkWin(string board[4][4], string player) {
    // Check rows
    for (int r = 1; r < 4; r++) {
        if (board[r][1] == player && board[r][2] == player && board[r][3] == player)
            return true;
    }

    // Check columns
    for (int c = 1; c < 4; c++) {
        if (board[1][c] == player && board[2][c] == player && board[3][c] == player)
            return true;
    }

    // Check diagonals
    if (board[1][1] == player && board[2][2] == player && board[3][3] == player)
        return true;

    if (board[1][3] == player && board[2][2] == player && board[3][1] == player)
        return true;

    return false;
}

int main() {
    int rounds = 9;
    int row, column;
    string player;
    string ticTacToe[4][4] = {
        { "0", "1", "2", "3" },
        { "1", "", "", "" },
        { "2", "", "", "" },
        { "3", "", "", "" }
    };

    do{
        for (int c = 0; c < 4; c++) {
            for (int r = 0; r < 4; r++) {
                cout << ticTacToe[c][r] << " ";
            }
            cout << endl;
        }
        cout << "Choose a row number between 1 and 3: ";
        cin >> row;

        cout << "Choose a column number between 1 and 3: ";
        cin >> column;

        if (ticTacToe[row][column] == "X" || ticTacToe[row][column] == "O") {
            cout << "This spot is already taken. Please choose another spot." << endl;
        } else {
            (rounds % 2 == 0) ? player = "X" : player = "O";
            ticTacToe[row][column] = player;
            // Check for a win
            if (checkWin(ticTacToe, player)) {
                // Display the board
                for (int c = 0; c < 4; c++) {
                    for (int r = 0; r < 4; r++) {
                        cout << ticTacToe[c][r] << " ";
                    }
                    cout << endl;
                }

                cout << "Player " << player << " wins!" << endl;
                return 0; // End the game
            }
            rounds--;
        }

    }while (rounds > 0);

    cout << "It's a draw!" << endl;

    return 0;
}