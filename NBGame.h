//
//  NBGame.h
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

#ifndef NBGame_h
#define NBGame_h

#include "NBTictactoe.h"
#include "Player.h"

class NBGame {
    
public:
    NBGame()
    : playerX('X'), playerO('O'), gameBoard(playerX, playerO)  {
            srand(static_cast<unsigned int>(time(nullptr)));
                
                getType();
//                if (typenumber==2) {
//
//
//
//                }
        }
    
    void start();
    int getType();
    
    
private:
    
    NBTicTacToe gameBoard;
    HumanPlayer playerX;
//    HumanPlayer playerO;
    RandomPlayer playerO;
    int typenumber;

};


void NBGame::start() {
    gameBoard.play();
}



int NBGame::getType() {
    
    cout << endl;


    cout << " | Human Player vs Human Player is Available with the change of one line code at THIS current version of DEVELOPMENT |" << endl;
    
    cout << " TYPE -> | Human Player vs Random Player|" << endl;

//    cin >> typenumber;

    return typenumber;
}


#endif /* NBGame_h */
