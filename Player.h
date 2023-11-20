//
//  Player.h
//  Practical 4.5
//
//  Created by Otgonbileg on 7/9/2023.
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
#include <queue>
#include "Cell.h"

#ifndef Player_h
#define Player_h

class Player {
public:
    virtual void getMove(int& x , int& y, TicTacToe& board) = 0;
protected:
    char symbol;
};






class RandomPlayer : public Player {
public:
    
    RandomPlayer(int s) {
        symbol = s;
    }

    void getMove(int& x , int& y, TicTacToe& board) {
        int row, col;
        srand(static_cast<unsigned int>(std::time(nullptr)));
        
        row = rand() % 3 + 1;
        col = rand() % 3 + 1;
//        do {
//
//        } while (!grid[currentBoard.x][currentBoard.y].isValidMove(row - 1, col - 1));
        x = row - 1;
        y = col - 1;
    }
};



class HumanPlayer : public Player {
public:
    
    HumanPlayer(int s) {
        symbol = s;
    }

    void getMove(int& x , int& y, TicTacToe& board) {
        int row, col;
        
        cin >> row >> col;
        cout << endl;
//        do {
//            cin >> row >> col;
//            cout << endl;
//        } while (!grid[currentBoard.x][currentBoard.y].isValidMove(row - 1, col - 1));
        x = row - 1;
        y = col - 1;
    }
};


const int simulation_times = 100;

class MonteCarloPlayer {
    char playerSymbol;
public:
    MonteCarloPlayer(int s) {
        
        playerSymbol = s;
        
    }

    void getMove(int& x, int& y, TicTacToe& board) {

        vector<int> emptyCells = board.getEmptyPositions();
        if (emptyCells.empty())
            return;

        priority_queue<Cell> moves;

        for (int index : emptyCells) {
            int i = index / 3;
            int j = index % 3;
            TicTacToe tempBoard(board);
            tempBoard.addMove(i, j, playerSymbol);
            if (tempBoard.check_full()) {
                if (tempBoard.gameStatus() == playerSymbol) {
                    x = i;
                    y = j;
                    return;
                } else {
                    continue;
                }
            }

            double utility = simulation(tempBoard);

            Cell c(i, j, utility);
            moves.push(c);
        }

        if (moves.size() > 0) {
            x = moves.top().x;
            y = moves.top().y;

            cout << moves.size() << " Monte Carlo Utility = " << moves.top().heuristic << " at ("
                    << x << "," << y << ")" << endl;
        }

        return;
    }

    double simulation(TicTacToe board) {

        int winning = 0;

        for (int i = 0; i < simulation_times; i++) {
            TicTacToe tempBoard(board);
            winning += expansion(tempBoard);
        }

        return ((double) winning / (double) simulation_times);
    }

    int expansion(TicTacToe board) {
        char gameStatus = board.gameStatus();
        if (gameStatus != 0) {
            if ( gameStatus == playerSymbol)
                return  1; //score 1 if wins
            else if (board.check_full())
                return 0; //score 0 if tie
            else
                return -1; //score -1 if lose
        }

        int x, y;
        board.getaRandomMove(x, y);
        board.addMove(x, y, playerSymbol);
        return expansion(board);
    }

};
#endif /* Player_h */
