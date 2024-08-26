#include<iostream>
using namespace std;

bool checkWinRow(char arr[3][3]) {
    for(int i = 0; i < 3; i++) {
        char same = arr[i][0];
        if(same == '-') continue;
        bool res = true;
        for(int j = 1; j < 3; j++) {
            if(arr[i][j] != same) {
                res = false;
                break;
            }
        }
        if(res) return true;
    }    
    return false;
}

bool checkWinCol(char arr[3][3]) {
    for(int i = 0; i < 3; i++) {
        char same = arr[0][i];
        if(same == '-') continue;
        bool res = true;
        for(int j = 1; j < 3; j++) {
            if(arr[j][i] != same) {
                res = false;
                break;
            }
        }
        if(res) return true;
    }    
    return false;
}

bool checkWinDiag1(char arr[3][3]) {
    char same = arr[0][0];
    if(same == '-') return false;
    for(int i = 1; i < 3; i++) {
        if(arr[i][i] != same) return false;
    }
    return true;
}

bool checkWinDiag2(char arr[3][3]) {
    char same = arr[0][2];
    if(same == '-') return false;
    for(int i = 1; i < 3; i++) {
        if(arr[i][2 - i] != same) return false;
    }
    return true;
}

void displayBoard(char arr[3][3]) {
    cout << "\n" << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << endl;
    cout << "---------\n";
    cout << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << endl;
    cout << "---------\n";
    cout << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << endl;
}

bool isFilled(char arr[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(arr[i][j] == '-') return false;
        }
    }
    return true;
}

void updateBoard(char arr[3][3], int row, int col, int turn) {
    arr[row][col] = (turn == 0) ? 'O' : 'X';
}

bool isPositionFilled(char arr[3][3], int row, int col) {
    return arr[row][col] == 'X' || arr[row][col] == 'O';
}

int main() {
    while(true) {
        char arr[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
        int turn = 1;
        string temp_turn;

        cout << "Player-1 will play with 'X'\n";
        cout << "Player-2 will play with 'O'\n\n";

        while(true) {
            cout << "Which Player will turn first (1 or 2): ";
            getline(cin, temp_turn);
    
            if(temp_turn == "1") {
                turn = 1;
                break;
            } else if(temp_turn == "2") {
                turn = 0;
                break;
            } else {
                cout << "Wrong Input! Try Again\n\n";
            }
        }

        int row, col;
        while(true) {
            while(true) {
                cout << "\nEnter a row number (1 or 2 or 3): ";
                cin >> row;
                cout << "Enter a column number (1 or 2 or 3): ";
                cin >> col;
                if(row <= 0 || row >= 4) {
                    cout << "Invalid Row Number Input! Try Again\n";
                } else if(col <= 0 || col >= 4) {
                    cout << "Invalid Column Number Input! Try Again\n";
                } else if(isPositionFilled(arr, row - 1, col - 1)) {
                    cout << "Place Already Filled! Try Again\n";
                } else {
                    break;
                }
            }
            updateBoard(arr, row - 1, col - 1, turn);
            displayBoard(arr);

            if(checkWinCol(arr) || checkWinRow(arr) || checkWinDiag1(arr) || checkWinDiag2(arr)) {
                cout << (turn == 0 ? "Player-2 won the game!\n" : "Player-1 won the game!\n");
                break;
            }

            if(isFilled(arr)) {
                cout << "\n****It's a tie!!****\nBoard has been completely filled\n";
                break;
            }
            turn = (turn + 1) % 2;
        }

        string choice;
        cout << "\nDo you want to play again? (y/n): ";
        getline(cin >> ws, choice);

        if(choice != "y") break;
    }
    return 0;
}
