//
// Created by darkb on 12.12.2021.
//

#include "BoardGame2D.h"

/**
     * ostream operator overloading
     * @param os
     * @param boardGame2D
     * @return
     */
ostream &operator<<(ostream &os, const BoardGame2D &boardGame2D) {
    cout << "\x1b[2J";
    cout << "\033[0;0H"; //ANSI escape code
    boardGame2D.print(os);
    return os;
}

/**
 * This function delegates print function of each derived class to print out classes
 * @param vector
 */
void BoardGame2D::playVector(vector<BoardGame2D *> vector) {
    cout<<"**********************************"<<endl;
    cout<<"***********************"<<endl;
    cout<<"*****************"<<endl;
    cout<<"Static playVector function is called"<<endl;
    sleep(2);
    for(auto boardPtr:vector)
        boardPtr->playAutoAll();

}

