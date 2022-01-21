//
// Created by baris on 12.12.2021.
//

#ifndef CSE241_HW5_EIGHTPUZZLE_H
#define CSE241_HW5_EIGHTPUZZLE_H

#include "BoardGame2D.h"
#include <vector>

using namespace std;

namespace baris2{


class EightPuzzle: public BoardGame2D {
public:

    //Default constructor of EightPuzzle
    EightPuzzle();

    //Default destructor
    ~EightPuzzle() override =default;

    //getter method of puzzleBoard
    const vector<vector<int>> &getPuzzleBoard() const;

    //setter method of puzzleBoard
    void setPuzzleBoard(const vector<vector<int>> &puzzleBoard);


    //Returns false for not solvable EightPuzzle Boards
    bool isSolvable(vector<int> v) const;

    //Returns false for illegal moves
    bool isLegal(string command) const override;

    //This function makes a move by a string user command
    void playUser(string command) override;


    //This function retuns true if a game is ended
    bool endGame() const override;

    //This function makes one computer move
    void playAuto() override;

    //This print function manipulates an ostream object to print out a class
    void print(ostream &os) const override;

    //This function returns score of the game
    int boardScore() const override;

    //This function initializes the game
    void initialize() override;


private:
    //Board of 8 Puzzle Game
    vector<vector<int>> puzzleBoard;

    //Returns coordinates of a given number in Board
    vector<int> getCoordinates(int number) const;

    //Returns legal string commands for a 8 Puzzle Board
    vector<string> availableMoves() const;

    //void removePointers(vector<int *> vector) const;


};


}


#endif //CSE241_HW5_EIGHTPUZZLE_H
