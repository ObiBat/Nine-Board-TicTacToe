//
//  Tictactoe.h
//  Practical 4.5
//
//  Created by Otgonbileg on 31/8/2023.
//  SID :22037760
//

/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the
code has been written/produced for me by another person or copied
from any other source.
I hold a copy of this assignment that I can produce if the original
is lost or damaged.
**************************/

#ifndef Tictactoe_h
#define Tictactoe_h

const int BOARDSIZE = 3;

struct Coordinate {
    int x;
    int y;
};


class TicTacToe {
private:
    int board[BOARDSIZE][BOARDSIZE];
    int noOfMoves;
    vector<int> emptyCells;
public:
    TicTacToe();
    TicTacToe(const TicTacToe& cboard) {
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
                board[row][col] = cboard.board[row][col];
        noOfMoves = cboard.noOfMoves;
        emptyCells = cboard.emptyCells;
    }
    bool isValidMove(int, int);
    bool check_full();
    void addMove(int, int, int);
    int gameStatus();
    int play();
    int getValue(int, int);
    void getaRandomMove(int& x, int& y);
    
//    int board[BOARDSIZE][BOARDSIZE];
    void displayBoard();
    vector<int> getEmptyPositions(); //Function to get empty positions
};

TicTacToe::TicTacToe() {//How to call this function?
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = 0;

    noOfMoves = 0;
}

vector<int> TicTacToe:: getEmptyPositions() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0)
                emptyCells.push_back(i * 3 + j);
        }
    }
    return emptyCells;
}

int TicTacToe::getValue(int x, int y) {
    return board[x][y];
}

bool TicTacToe::isValidMove(int x, int y) {//Add your code to complete the program
    if (x>=0 && x<=2 && y<=2 && y>=0 && board[x][y] == 0 ) //Add your code here)
        return true;
    else
        return false;
}


bool TicTacToe::check_full() {
    if(noOfMoves>=9){
        return true;
    } else
        return false;
}

void TicTacToe::getaRandomMove(int& x, int& y) {
   // vector<int> emptyCells = getEmptyPositions();

    int index = rand() % emptyCells.size();
    x = emptyCells[index] / 3;
    y = emptyCells[index] % 3;
}




void TicTacToe::addMove(int x, int y, int player) {//What is this function for?
    
    
    board[x][y] = player;
    noOfMoves++;
}

int TicTacToe::gameStatus() {//Add your code to complete the program
//Write your code here to check if the game has been in a win status or a draw status
//Check rows for a win

    //Add your code here
        for (int x=0; x<=2; x++) {
                if (board[x][0] !=0 && board[x][0] == board[x][1] && board[x][0] == board[x][2]) {
                    return board[x][0];
                }
        }

        


    //Check columns for a win

    //Add your code here
        
        for (int x=0; x<=2; x++) {
                if (board[0][x] !=0 && board[0][x] == board[1][x] && board[0][x] == board[2][x]) {
                    return board[0][x];
                }
        }

    //Check diagonals for a win

        if (board[0][0] !=0 && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return board[0][0];
        }
        
        if (board[0][2] !=0 && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return board[0][2];
        }

    //Add your code here


        return 0;
        
}


#endif /* Tictactoe_h */
