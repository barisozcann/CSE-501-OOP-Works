//
// Created by darkb on 12.12.2021.
//

#ifndef CSE241_HW5_PEGSOLITAIRE_H
#define CSE241_HW5_PEGSOLITAIRE_H
#include <vector>
#include <string>
#include "BoardGame2D.h"


using namespace std;

namespace baris {


    enum class cell {
        Empty = 0, Peg = 1, nonUsed = 2
    }; //This is strong enum type of cell representation


    class PegSolitaire : public BoardGame2D {
    public:
        PegSolitaire(); //No parameter constructor

        explicit PegSolitaire(string fileName); //string file name constructor

        ~PegSolitaire() override = default;

        class Cell { //inner class Cell
        public:
            Cell(); //no parameter constructor of Cell class

            Cell(int x, int y, char cellState); //location and state constructor of Cell class

            virtual ~Cell() = default; //Deconstructor of Cell class

            int getX() const; //x getter method

            void setX(int x); //x setter method

            int getY() const; //y getter method

            void setY(int y); //y setter method

            char getCellState() const; //cellState getter method

            void setCellState(char cellState); //cellState setter method



        private:
            int x, y; //x and y coordinates of Cell class
            char cellState; //char value of Cell class
            cell currentCell; //strong enum type of Cell class
        };

        //getter method of currentBoard
        const vector<vector<Cell>> &getCurrentBoard() const;

        //setter method of currentBoard
        void setCurrentBoard(const vector<vector<Cell>> &currentBoard);

        //getter method of filename
        const string &getFileName() const;

        //setter method of filename
        void setFileName(const string &fileName);

        //returns false for illegal moves
        bool isLegal(string command) const override;

        //Makes a move by a string command
        void playUser(string command) override;

        //Returns true if the game is ended
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
        vector<vector<Cell>> currentBoard; //2D vector (Board)
        string fileName; //string filename

        inline void readFile(string fileName); //This method reads the file

        int findIndexOfLetter(
                char letter) const; //This method converts string column names to integer values (A=0,B=1,C=2...)

        bool isLegal(vector<vector<Cell>> inputBoard,
                     string moveCommand) const; //This method says if the move is legal for board1-5

        void playUser(vector<vector<Cell>> &inputBoard,
                      string moveCommand); //This method makes move by taking string command

        bool
        endGame(vector<vector<Cell>> inputBoard) const; //This method returns true only if there is no available move

        vector<vector<int>> returnPegCoordinates(
                vector<vector<Cell>> inputBoard) const; //This method returns all coordinates of pegs in a board

        int numberOfPegs(const vector<vector<Cell>> &inputBoard) const; //This method returns number of pegs

        vector<vector<Cell>> textToVectors(string fileName); //This method converts txt file into 2D vector(Board)

        void
        movePegComputerHelper(vector<vector<Cell>> &inputBoard, string moveCommand); //Helper method of computer move

        void playAuto(vector<vector<Cell>> &inputBoard); //This method makes a single computer move

    };

}

#endif //CSE241_HW5_PEGSOLITAIRE_H
