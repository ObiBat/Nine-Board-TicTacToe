//
//  game.h
//  Practical 4.4
//
//  Created by Otgonbileg Batbileg on 25/8/2023.
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

#ifndef game_h
#define game_h



#include "Tictactoe.h"
#include "Player.h"
#include <ctime>




class NBTicTacToe {
    
public:
    void play();
    void getXMove(char player, int&, int&);
    void getOMove(char player, int&, int&);
    
    NBTicTacToe(Player& xPlayer, Player& oPlayer): playerX(xPlayer), playerO(oPlayer){
        
        srand(static_cast<unsigned int>(std::time(nullptr)));

        
        currentBoard.x = rand() % 3;
        currentBoard.y = rand() % 3;
        }
    
    void displayBoards();

    
//    ..
//    ..
    
private:
    TicTacToe grid[3][3];//nine TicTacToe board
    Coordinate currentBoard;
    Player& playerX;
    Player& playerO;
    
};





void NBTicTacToe::displayBoards() {
    cout << endl;
    
    if (currentBoard.x==0 && currentBoard.y==0) {
        cout << "*******************------------------------------------" << endl;
    } else if (currentBoard.x==0 && currentBoard.y==1) {
        cout << "-------------------*******************-----------------" << endl;
    } else if (currentBoard.x==0 && currentBoard.y==2) {
        cout << "------------------------------------*******************" << endl;
    } else
        cout << "-------------------------------------------------------" << endl;
    
//    ------------------------------------
    
            
    for (int e = 0; e < 3; ++e) {
        for (int i = 0; i < 3; ++i) {
            for (int c = 0; c < 3; ++c) {
                for (int j = 0; j < 3; ++j) {
                    char playerSymbol = ' ';
                    if (grid[e][c].getValue(i, j) == 1)
                        playerSymbol = 'X';
                    else if (grid[e][c].getValue(i, j) == -1)
                        playerSymbol = 'O';
                    
           
                    if (j==0 & c==0) {
                        cout << "||";
                    }
                    
//  Possible implementation of missing stars on the column prints will work if replace the if statment above with while loop above
//                  !!!  DISSCUSSED WITH THE TUTOR  !!!
                    
                    
                    
//                    int pi =0;
//                    while (pi<3) {
//
//                        if (currentBoard.x==pi && currentBoard.y==0) {
//                            if (j==0 & c==0 & e==pi) {
//                                cout << "**";
//                            }
//                        } else {
//                            if (j==0 & c==0 & e==pi) {
//                                cout << "||";
//                            }
//                        }
//                        pi++;
//                    }
                    
                    

                
                    cout << setw(3) << playerSymbol;
                    if (j != 2)
                        cout << "  |";
                    
                    
                    if (j==2 & c==2) {
                        cout << " ||";
                    }
 
//  Possible implementation of missing stars on the column prints will work if replace the if statment above with while loop above
//                  !!!  DISSCUSSED WITH THE TUTOR  !!!
                    
                    
//                    int pl =0;
//                    while (pl<3) {
//
//                        if (currentBoard.x==pl && currentBoard.y==2) {
//                            if (j==2 & c==2 & e==pl) {
//                                cout << " **";
//                            }
//                        } else {
//                            if (j==2 & c==2 & e==pl) {
//                                cout << " ||";
//                            }
//                        }
//                        pl++;
//                    }
                    
                    
                    
                    
                }
                if (c < 2) {
                    cout << " ||";

                }
                
                
            }
            cout << endl;
            
            
            
            
            if (i != 2) {
                
                int p =0;
                while (p<3) {
                    
                        if (currentBoard.x==p && currentBoard.y==0)  {
                            if (e==p) {
                            
                                cout << "**_____|_____|____**_____|_____|____||_____|_____|____|| " << endl;
                            }
                        } else if (currentBoard.x==p && currentBoard.y==1) {
                            if (e==p) {
                            
                                cout << "||_____|_____|____**_____|_____|____**_____|_____|____|| " << endl;
                            }
                        } else if (currentBoard.x==p && currentBoard.y==2) {
                            if (e==p) {
                            
                                cout << "||_____|_____|____||_____|_____|____**_____|_____|____** " << endl;
                            }
                        }  else {
                            if (e==p) {
                                cout << "||_____|_____|____||_____|_____|____||_____|_____|____|| " << endl;
                            }
                        }
                    p++;
                }
                
       
            
            }
            else {
                
                int l =0;
                while (l<3) {
                    
                    if (currentBoard.x==l && currentBoard.y==0) {
                        if (e==l) {
                        
                            cout << "**     |     |    **     |     |    ||     |     |    ||" << endl;
                        }
                    } else if (currentBoard.x==l && currentBoard.y==1) {
                        if (e==l) {
                        
                            cout << "||     |     |    **     |     |    **     |     |    ||" << endl;
                        }
                    } else if (currentBoard.x==l && currentBoard.y==2) {
                        if (e==l) {
                        
                            cout << "||     |     |    ||     |     |    **     |     |    **" << endl;
                        }
                    } else {
                        if (e==l) {
                            cout << "||     |     |    ||     |     |    ||     |     |    ||" << endl;
                        }
                    }
                    l++;
                }
                
                
                }
          }
        

        
        
        
        
        
        if (e < 2) {
            
            if (e == 0 ) {
                if ((currentBoard.x==0 && currentBoard.y==0) || (currentBoard.x==1 && currentBoard.y==0)) {
                    cout << "*******************------------------------------------" << endl;
                } else if ((currentBoard.x==0 && currentBoard.y==1) || (currentBoard.x==1 && currentBoard.y==1)) {
                    cout << "-------------------*******************-----------------" << endl;
                } else if ((currentBoard.x==0 && currentBoard.y==2) || (currentBoard.x==1 && currentBoard.y==2)) {
                    cout << "------------------------------------*******************" << endl;
                } else
                    cout << "-------------------------------------------------------" << endl;
            }
            
            if (e==1) {
                if ((currentBoard.x==1 && currentBoard.y==0) || (currentBoard.x==2 && currentBoard.y==0)) {
                    cout << "*******************------------------------------------" << endl;
                } else if ((currentBoard.x==1 && currentBoard.y==1) || (currentBoard.x==2 && currentBoard.y==1)) {
                    cout << "-------------------*******************-----------------" << endl;
                } else if ((currentBoard.x==1 && currentBoard.y==2) || (currentBoard.x==2 && currentBoard.y==2)) {
                    cout << "------------------------------------*******************" << endl;
                } else
                    cout << "-------------------------------------------------------" << endl;
            }
            
        }
        
        
        
    }
    if (currentBoard.x==2 && currentBoard.y==0) {
        cout << "*******************------------------------------------" << endl;
    } else if (currentBoard.x==2 && currentBoard.y==1) {
        cout << "------------------=*******************-----------------" << endl;
    } else if (currentBoard.x==2 && currentBoard.y==2) {
        cout << "------------------------------------*******************" << endl;
    } else
        cout << "-------------------------------------------------------" << endl;
}


void NBTicTacToe::play() {//What is the counterpart of this function in the original code

    int player = 1;
    int noOfMoves = 0;

    displayBoards();
    int done = 0;
    while (done == 0) {
        char playerSymbol = (player == 1) ? 'X' : 'O';
        cout << "Player " << playerSymbol << " enter move: ";
        int x, y;

        //getXOMove(x, y);


        
        do {
            if (player == 1) {
                playerX.getMove(x, y, grid[currentBoard.x][currentBoard.y]);  // computer
            } else {
                playerO.getMove(x, y, grid[currentBoard.x][currentBoard.y]);  //player
            }
        } while (!grid[currentBoard.x][currentBoard.y].isValidMove(x, y));

        grid[currentBoard.x][currentBoard.y].addMove(x, y, player);
        noOfMoves++;
        
        
        currentBoard.x = x;
        currentBoard.y = y;
        
        if(grid[currentBoard.x][currentBoard.y].check_full()) {
            
            srand(static_cast<unsigned int>(std::time(nullptr)));
            currentBoard.x = rand() % 3;
            currentBoard.y = rand() % 3;
        }
            
        
        
        displayBoards();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                done = grid[i][j].gameStatus();
                if(done!=0){
                    break;
                }
            }
            if(done!=0){
                break;
            }
        }
        
        
        
        if (noOfMoves >= 81) {
            done = 2;
        }

        if (done == 1) {
            cout << "Player X wins!" << endl;
//            return 1;
        } else if (done == -1) {
            cout << "Player O wins!" << endl;
//            return -1;
        } else if (done == 2) {
            cout << "Draw game!" << endl;
//            return 0;
        }

        if (player == 1)
            player = -1;
        else
            player = 1;
    }

}




#endif /* game_h */
