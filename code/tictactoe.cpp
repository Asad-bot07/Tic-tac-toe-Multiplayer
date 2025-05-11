#include <iostream>
using namespace std;
char board[3][3];
char currentMarker;
int currentPlayer;
void initializeBoard() 
{
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            board[i][j] = '1' + (i * 3 + j);
}
void printBoard() {
    for (int i = 0; i < 3; i++) 
    {
        cout << " ";
        for (int j = 0; j < 3; j++) 
        {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
}
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') 
    {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}
int checkWin() 
{
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;
    return 0;
}
void swapPlayerAndMarker() 
{
    if (currentMarker == 'X') 
    {
        currentMarker = 'O';
        currentPlayer = 2;
    } else 
    {
        currentMarker = 'X';
        currentPlayer = 1;
    }
}
int main() 
{
    initializeBoard();
    currentMarker = 'X';
    currentPlayer = 1;
    printBoard();
    for (int i = 0; i < 9; i++) 
    {
        int slot;
        cout << "Player " << currentPlayer << " (" << currentMarker << "), choose your slot (1-9): ";
        cin >> slot;
        if (slot < 1 || slot > 9) 
        {
            cout << "Invalid slot. Try again.\n";
            i--;
            continue;
        }
        if (!placeMarker(slot)) 
        {
            cout << "Slot already taken. Try again.\n";
            i--;
            continue;
        }
        printBoard();
        if (checkWin() != 0) 
        {
            cout << "Player " << currentPlayer << " wins!\n";
            return 0;
        }
        swapPlayerAndMarker();
    }
    cout << "It's a draw!\n";
    return 0;
}

