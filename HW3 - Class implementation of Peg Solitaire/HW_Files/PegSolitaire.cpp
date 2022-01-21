//
// Created by baris on 4.11.2021.
//

#include "PegSolitaire.h"
#include <iostream>
#include <random>
#include <string>
#include <vector>
//#include<bits/stdc++.h> //This library is necessary for shuffling a vector
#include <algorithm> //This library is necessary for shuffling a vector
#include<fstream> //File read write library
#include<dirent.h> //To see files in the current directory
#include <sstream> //Converting string to integer

using namespace std;


vector<char> columnNames {'a','b','c','d','e','f','g','h','i','j','k','l','m','n'
                          ,'o','p','q','r','s','t','u','v','w','x','y','z'}; //This is list of english letters in order


/**
 * This is no parameter constructor
 * It starts the game with Board1
 */
PegSolitaire::PegSolitaire() {
    this->isDiagonal=false;
    this->fileName="board1.txt";
    readFile(this->fileName);
}

/**
 * This cosntructor starts the game by taking string fileName parameter
 * It reads the file and converts into a 2D vector
 * If hte board is smaller than 5x5, it automatically resizes the board
 * @param fileName file name
 * @param isDiagonal only true for Board6
 */

PegSolitaire::PegSolitaire(string fileName,bool isDiagonal) {
    this->fileName=fileName;
    this->isDiagonal=isDiagonal;
    readFile(fileName);

    int horizontalSize=currentBoard[0].size();
    int verticalSize=currentBoard.size();


    if(horizontalSize<5 || verticalSize<5) { //Only true if board is smaller than 5x5
        cout<<"Your board is smaller than 5x5"<<endl;
        showBoard(this->currentBoard);
        while (horizontalSize < 5) { //Expanding horizontal size
            for (auto row: currentBoard) {
                row.push_back(row[horizontalSize - 1]); //copying last column of every row to right direction
            }
            horizontalSize++;
        }

        while (verticalSize < 5) { //Expanding Vercical Size
            currentBoard.push_back(currentBoard[verticalSize - 1]); //copying last row of every column to down direction
            verticalSize++;
        }

        cout<<"Your board is resized to at least 5x5 standarts"<<endl;
        showBoard(currentBoard);
    }
}

/**
 * This constructor starts the game with integer board type for Board1-6
 * @param boardType
 * @param isDiagonal only true for board 6
 */

PegSolitaire::PegSolitaire(const int &boardType, bool isDiagonal) {
    this->isDiagonal=isDiagonal;
    switch (boardType) {
        case 1:
            this->fileName="board1.txt";
            readFile(this->fileName);
            break;
        case 2:
            this->fileName="board2.txt";
            readFile(this->fileName);
            break;
        case 3:
            this->fileName="board3.txt";
            readFile(this->fileName);
            break;
        case 4:
            this->fileName="board4.txt";
            readFile(this->fileName);
            break;
        case 5:
            this->fileName="board5.txt";
            readFile(this->fileName);
            break;
        case 6:
            this->fileName="board6.txt";
            readFile(this->fileName);
            break;
        default:
            cerr<<"Board Type should be between 1-6 !"<<endl;
    }
}



/**
 * Destructor of PegSolitaire class
 */

PegSolitaire::~PegSolitaire() {

}

/**
 * This constructor constructs a Cell class by using integer coordinates and cell state
 * @param x
 * @param y
 * @param cellState
 */

PegSolitaire::Cell::Cell(int x, int y, char cellState) : x(x), y(y), cellState(cellState) {}

/**
 * This is no parameter contructor of Cell class
 * x=0, y=0 and state is nonused
 */

PegSolitaire::Cell::Cell() {
    this->x=0;
    this->y=0;
    this->cellState=' ';
    this->currentCell=cell::nonUsed;
}

/**
 * Destructor of Cell class
 */

PegSolitaire::Cell::~Cell() {

}

/**
 * getter of x coordinate of Cell class
 * @return
 */

int PegSolitaire::Cell::getX() const {
    return x;
}
/**
 * setter of x coordinate of Cell class
 * @return
 */

void PegSolitaire::Cell::setX(int x) {
    Cell::x = x;
}


/**
 * getter of y coordinate of Cell class
 * @return
 */

int PegSolitaire::Cell::getY() const {
    return y;
}

/**
 * setter of y coordinate of Cell class
 * @return
 */

void PegSolitaire::Cell::setY(int y) {
    Cell::y = y;
}
/**
 * getter method of cell state of Cell class
 * @return
 */
char PegSolitaire::Cell::getCellState() const {
    return cellState;
}

/**
 * Setter method of cell state of Cell class
 * @param cellState
 */

void PegSolitaire::Cell::setCellState(char cellState) {
    if(cellState=='p'){
        Cell::cellState = cellState;
        Cell::currentCell=cell::Peg;
    }
    else if(cellState=='.'){
        Cell::cellState = cellState;
        Cell::currentCell=cell::Empty;
    }
    else if(cellState==' '){
        Cell::cellState = cellState;
        Cell::currentCell=cell::nonUsed;
    }
    else
        cout<<cellState<<" is such an invalid cell state!"<<endl;

}

/**
 * Getter method of Board
 * @return 2D vector
 */

const vector<vector<PegSolitaire::Cell>> &PegSolitaire::getCurrentBoard() const {
    return currentBoard;
}


/**
 * Setter method of Board
 * @param currentBoard
 */
void PegSolitaire::setCurrentBoard(const vector<vector<Cell>> &currentBoard) {
    PegSolitaire::currentBoard = currentBoard;
}

/**
 * getter method of filename
 * @return
 */
const string &PegSolitaire::getFileName() const {
    return fileName;
}

/**
 * Setter method of filename
 * @param fileName
 */
void PegSolitaire::setFileName(const string &fileName) {
    PegSolitaire::fileName = fileName;
}

/**
 * getter method of isDiagonal
 * @return
 */
bool PegSolitaire::isDiagonal1() const {
    return isDiagonal;
}

/**
 * Setter method of isDiagonal
 * @param isDiagonal
 */
void PegSolitaire::setIsDiagonal(bool isDiagonal) {
    PegSolitaire::isDiagonal = isDiagonal;
}

/**
 * getter method of int board type
 * @return
 */
int PegSolitaire::getBoardType() const {
    return boardType;
}

/**
 * setter method of int board type
 * @param boardType
 */
void PegSolitaire::setBoardType(int boardType) {
    PegSolitaire::boardType = boardType;
}

/**
 *  This method converts string column names to integer values (A=0,B=1,C=2...)
 * @param letter
 * @return
 */

int PegSolitaire::findIndexOfLetter(char letter) const {
    for (int i = 0; i < columnNames.size(); ++i) {
        if (columnNames[i] == letter)
            return i;
    }
    return -1;

}

/**
 * This function takes 2 inputs
 * First input is 2d vector
 * Second input is isDiagonal. It's true for only Board6 and it is false by default.
 * Second input is type of the Board(1,2,3,4,5,6)
 * It prints out a given Board by nested for loops
 * @param inputBoard
 * @param isDiagonal
 */

void PegSolitaire::showBoard(vector<vector<Cell>> inputBoard, bool isDiagonal) {
    int rowNumber = 1; //it begins from 1
    if (isDiagonal == false) {
        cout << "\n\t";
        int columnNumbers = inputBoard[0].size();

        for (int i = 0; i < columnNumbers; i++) {
            cout << columnNames[i]<<" ";
        }
        cout << endl;

        for (auto & iter1 : inputBoard) { //Iterator1
            cout << rowNumber << "\t";
            rowNumber++;

            for (auto & iter2 : iter1) { //Iterator2
                cout<<iter2.getCellState()<<" ";
            }
            cout << endl;
        }
    }


    else {
        cout << "\t    ";
        for (int i = 0; i < 5; i++) { //Number of columns in Board6 is equal to 5
            cout << columnNames[i]<<" ";
        }
        cout << endl;

        for (auto & iter1 : inputBoard) { //Iterator1
            cout << rowNumber << "\t";
            rowNumber++;
            for (auto & iter2 : iter1) { //Iterator2
                cout<<iter2.getCellState()<<" ";
            }
            cout << endl;
        }
        cout << "\n\t      a\n\t     a b\n\t    a b c\n\t   a b c d\n\t  a b c d e    <-- These are the columns in Board6\n" << endl;
    }


}


/**
 * Delegation method of showBoard
 * @param isDiagonal
 */
void PegSolitaire::showBoard(bool isDiagonal) {
    showBoard(this->currentBoard,isDiagonal);
}


/**
 * This function checks whether the given command is legal for Board1,2,3,4,5
 * First Input is 2d Vector
 * Second input is string command
 * It returns true if the given command is legal
 * @param inputBoard
 * @param moveCommand
 * @return
 */

bool PegSolitaire::isLegal(vector<vector<Cell>> inputBoard, string moveCommand) {
    transform(moveCommand.begin(), moveCommand.end(), moveCommand.begin(), ::tolower); //It converts given string to lowercase
    string inputSourceRow, moveDirection;
    char inputSourceColumn;

    if(moveCommand.size()==4){
        inputSourceColumn = moveCommand[0];
        inputSourceRow = moveCommand[1];
        moveDirection = moveCommand[3];
    }

    else if(moveCommand.size()==5){ //Don mutlaka buraya
        inputSourceColumn = moveCommand[0];
        inputSourceRow = moveCommand[1]+moveCommand[2];
        moveDirection = moveCommand[4];
    }

    else{
        cerr<<"Wrong command type!"<<endl;
        return false;
    }


    int sourceRow = stoi(inputSourceRow); //It converts string row to integer type
    sourceRow--; //Because rows are starting with 1 not zero

    int sourceColumn = findIndexOfLetter(inputSourceColumn); //Convers char to integer type


    if (moveDirection == "u") { //"u" is stand for up command
        if (sourceRow < 2) //It returns false to prevent segmentation fault
            return false;

        char sourceCell = inputBoard[sourceRow][sourceColumn].getCellState(); //source cell
        char middleCell = inputBoard[sourceRow - 1][sourceColumn].getCellState(); //middle cell between source and target
        char targetCell = inputBoard[sourceRow - 2][sourceColumn].getCellState(); //target cell (upwards)

        if (sourceCell == 'p' && middleCell == 'p' && targetCell == '.')
            return true;
        else
            return false;

    }
    else if (moveDirection == "d") { //"d" is stand for down command
        if (sourceRow >= inputBoard.size() - 2) //It returns false to prevent segmentation fault
            return false;

        char sourceCell = inputBoard[sourceRow][sourceColumn].getCellState(); //source cell
        char middleCell = inputBoard[sourceRow + 1][sourceColumn].getCellState(); //middle cell between source and target
        char targetCell = inputBoard[sourceRow + 2][sourceColumn].getCellState(); //target cell (downwards)

        if (sourceCell == 'p'&& middleCell == 'p' && targetCell =='.')
            return true;
        else
            return false;

    }

    else if (moveDirection == "l") { //"l" is stand for left command
        if (sourceColumn < 2) //It returns false to prevent segmentation fault
            return false;
        char sourceCell = inputBoard[sourceRow][sourceColumn].getCellState(); //source cell
        char middleCell = inputBoard[sourceRow][sourceColumn - 1].getCellState(); //middle cell between source and target
        char targetCell = inputBoard[sourceRow][sourceColumn - 2].getCellState(); //target cell (leftwards)

        if (sourceCell == 'p'&& middleCell == 'p' && targetCell =='.')
            return true;
        else
            return false;


    }

    else if (moveDirection == "r") { //"r" is stand for right command
        if (sourceColumn >= inputBoard[0].size() - 2) //It returns false to prevent segmentation fault
            return false;

        char sourceCell = inputBoard[sourceRow][sourceColumn].getCellState(); //source cell
        char middleCell = inputBoard[sourceRow][sourceColumn + 1].getCellState(); //middle cell between source and target
        char targetCell = inputBoard[sourceRow][sourceColumn + 2].getCellState(); //target cell (reftwards)

        if (sourceCell == 'p'&& middleCell == 'p' && targetCell =='.')
            return true;
        else
            return false;

    }

    else
        return false;
}


/**
 * Delegation method of isLegal
 * @param moveCommand
 * @return
 */
bool PegSolitaire::isLegal(string moveCommand) {
    bool x= isLegal(this->currentBoard, moveCommand);
    return x;
}

/**
 * This functions reads a text file and converts into a 2d vector
 * Only input parameter is string name of specific txt file
 * @param fileName
 * @return
 */

vector<vector<PegSolitaire::Cell>> PegSolitaire::textToVectors(string fileName) {
    string str; //String buffer to save each lines in text file
    vector<vector<Cell>> board; //2d vector which keeps Board
    vector<Cell> boardLine; //1d vector which keeps each line in a given board

    ifstream file(fileName); // Read from the text file

    int x=0;
    int y=0;
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(file, str)) {
        // Output the text from the file
        //cout << str;
        y=0;
        for (auto& ch : str) {
            if (ch == 'p' || ch=='.'|| ch==' '){ //p means peg in txt file
                //cout<<x<<","<<y<<endl;
                boardLine.push_back(Cell(x,y,ch));
            }
            else
                continue;
            y++;
        }
        if(!boardLine.empty()){
            board.push_back(boardLine);
            x++;
        }


        boardLine.clear();
    }
    // Close the file
    file.close();
    return board;
}


/**
 * This method uses textToVectors method and saves the output in 2D vector type of class(currentBoard)
 * @param fileName
 */
inline void PegSolitaire::readFile(string fileName) {
    this->currentBoard= textToVectors(fileName);
}
/**
 * This is move function of person inputs for Board1,2,3,4,5
 * First Input is 2d Vector Reference
 * Second input is string command
 * It makes a move if the given command is legal
 * @param inputBoard
 * @param moveCommand
 */
void PegSolitaire::play(vector<vector<Cell>> &inputBoard, string moveCommand) {

    if (isLegal(inputBoard, moveCommand)) { //It check is the given command is legal
        string inputSourceRow, moveDirection;
        char inputSourceColumn;
        transform(moveCommand.begin(), moveCommand.end(), moveCommand.begin(), ::tolower); //It converts given string to lowercase

        if(moveCommand.size()==4){
            inputSourceColumn = moveCommand[0];
            inputSourceRow = moveCommand[1];
            moveDirection = moveCommand[3];

        }
        else if(moveCommand.size()==5){
            inputSourceColumn = moveCommand[0];
            inputSourceRow = moveCommand[1]+moveCommand[2];
            moveDirection = moveCommand[4];
        }


        int sourceRow = stoi(inputSourceRow); //It converts string row to integer type
        sourceRow--; //Because rows are starting with 1 not zero

        int sourceColumn = findIndexOfLetter(inputSourceColumn);

        inputBoard[sourceRow][sourceColumn].setCellState('.'); //It makes the source cell empty

        if (moveDirection == "u") {
            inputBoard[sourceRow - 1][sourceColumn].setCellState('.'); //makes middle cell empty
            inputBoard[sourceRow - 2][sourceColumn].setCellState('p'); //makes target cell peg
        }
        else if (moveDirection == "d") {
            inputBoard[sourceRow + 1][sourceColumn].setCellState('.'); //makes middle cell empty
            inputBoard[sourceRow + 2][sourceColumn].setCellState('p'); //makes target cell peg
        }

        else if (moveDirection == "l") {
            inputBoard[sourceRow][sourceColumn - 1].setCellState('.'); //makes middle cell empty
            inputBoard[sourceRow][sourceColumn - 2].setCellState('p'); //makes target cell peg
        }

        else if (moveDirection == "r") {
            inputBoard[sourceRow][sourceColumn + 1].setCellState('.');//makes middle cell empty
            inputBoard[sourceRow][sourceColumn + 2].setCellState('p');//makes target cell peg
        }

    }
    else
        cout << moveCommand << " is illegal move!" << endl; //Warning for illegal moves

}

void PegSolitaire::play(string moveCommand) {
    play(this->currentBoard,moveCommand);
}


/**
 * This method returns number of pegs in given 2D vector (Board)
 * @param inputBoard
 * @return
 */
int PegSolitaire::numberOfPegs(const vector<vector<Cell>>& inputBoard) {
    int pegCounter = 0;
    for (const vector<Cell>& innerVector : inputBoard) //Nested ranged for loops
        for (Cell c : innerVector)
            if (c.getCellState() == 'p')
                pegCounter++;
    return pegCounter;
}
/**
 * Delegation method of numberOfPegs
 * @return
 */
int PegSolitaire::numberOfPegs() {
    return PegSolitaire::numberOfPegs(this->currentBoard);
}

/**
 * This method returns number of empty cells in a given board
 * @param inputBoard
 * @return
 */
int PegSolitaire::numberOfEmpty(const vector<vector<Cell>> &inputBoard) {
    int emptyCounter= 0;
    for (const vector<Cell>& innerVector : inputBoard) //Nested ranged for loops
        for (Cell c : innerVector)
            if (c.getCellState() == '.')
                emptyCounter++;
    return emptyCounter;
}

/**
 * Delagation method of numberOfEmpty method
 * @return
 */

int PegSolitaire::numberOfEmpty() {
    return PegSolitaire::numberOfEmpty(this->currentBoard);
}

/**
 * This functions is nearly same as movePegPerson.
 * Only difference is, it doesn't warn for illegal moves because computer needs to try so many illegal moves to find a legal move
 * This function is for Board1,2,3,4,5
 * First Input is 2d Vector Reference
 * Second input is string command
 * @param inputBoard
 * @param moveCommand
 */
void PegSolitaire::movePegComputerHelper(vector<vector<Cell>> &inputBoard, string moveCommand) {

    transform(moveCommand.begin(), moveCommand.end(), moveCommand.begin(), ::tolower); //It converts given string to lowercase
    string inputSourceRow, moveDirection;
    char inputSourceColumn;

    if(moveCommand.size()==4){
        inputSourceColumn = moveCommand[0];
        inputSourceRow = moveCommand[1];
        moveDirection = moveCommand[3];
    }

    else if(moveCommand.size()==5){ //Don mutlaka buraya
        inputSourceColumn = moveCommand[0];
        inputSourceRow = moveCommand[1]+moveCommand[2];
        moveDirection = moveCommand[4];
    }



    int sourceRow = stoi(inputSourceRow); //It converts string row to integer type
    sourceRow--; //Because rows are starting with 1 not zero

    int sourceColumn = findIndexOfLetter(inputSourceColumn); //Convers char to integer type

    inputBoard[sourceRow][sourceColumn].setCellState('.');

    if (moveDirection == "u") {
        inputBoard[sourceRow - 1][sourceColumn].setCellState('.');
        inputBoard[sourceRow - 2][sourceColumn].setCellState('p');
    }
    else if (moveDirection == "d") {
        inputBoard[sourceRow + 1][sourceColumn].setCellState('.');
        inputBoard[sourceRow + 2][sourceColumn].setCellState('p');
    }

    else if (moveDirection == "l") {
        inputBoard[sourceRow][sourceColumn - 1].setCellState('.');
        inputBoard[sourceRow][sourceColumn - 2].setCellState('p');
    }

    else if (moveDirection == "r") {
        inputBoard[sourceRow][sourceColumn + 1].setCellState('.');
        inputBoard[sourceRow][sourceColumn + 2].setCellState('p');
    }

}


/**
 * This function is for non- dioganal Boards like Board1,2,3,4,5
 * This functions iterates throughs a given Board and returns number of pegs
 * Input is a 2d Vector
 * @param inputBoard
 * @return
 */
vector<vector<int>> PegSolitaire::returnPegCoordinates(vector<vector<Cell>> inputBoard) {
    vector<vector<int>> pegCoordinateList; //2d vector that collects the list of peg coordinates
    vector<int> pegCoordinates; //1d vector that collects a given peg coordinate

    for (vector<Cell> innerVector: inputBoard) { //Nested for loop
        for (Cell c: innerVector)
        {
            if (c.getCellState()=='p') {

                pegCoordinates.push_back(c.getX()); //Collecting the row information of a peg cell
                pegCoordinates.push_back(c.getY()); //Collecting the column information of a peg cell
                //cout<<c.getX()<<"***"<<c.getY()<<endl;

                pegCoordinateList.push_back(pegCoordinates); //Collect 1d vector in a 2d vector to collect pairs
                pegCoordinates.clear(); //Clear 1d vector after saving
            }

        }
    }
    return pegCoordinateList;
}


/**
 * This function works for non diogonal Boards like Board1,2,3,4,5
 * Input is a 2d Vector reference
 * It takes a Board and tries to make a random computer move
 * It can't make any move if the game is over
 * It shuffles all peg coordinates and takes the last peg in the vector to make a move every time.
 * @param inputBoard
 */
void PegSolitaire::play(vector<vector<Cell>>& inputBoard) {
    vector<vector<int>> pegCoordinateList; //2d vector for Peg Coordinates
    vector<int> pegCoordinates; //1d vector contains only 1 peg's coordinate
    pegCoordinateList = returnPegCoordinates(inputBoard);

    shuffle(pegCoordinateList.begin(), pegCoordinateList.end(), std::mt19937(std::random_device()())); //It shuffles all vectors' coordinates for randomization

    int column, row;
    string columnName, rowName, moveCommand;
    vector<string> directions = { "l","r","u","d" }; //String list of directions
    int counter = 0;

    while (true) {
        if (counter != 0 || pegCoordinateList.empty()) //It stops the loop if it makes a move or coordinate list becomes empty
            break;
        pegCoordinates = pegCoordinateList.back(); //turns last element in peg coordinate list
        pegCoordinateList.pop_back(); //pops the last element in peg coordinate list

        column = pegCoordinates[1]; //column of a random peg
        row = pegCoordinates[0] + 1; //Row of a random peg. Adding +1 because rows begin at 1 not 0.
        //cout<<row<<"**"<<column<<endl;
        rowName = to_string(row); //converts integer row to string type
        columnName = columnNames[column]; //converts integer column information to string column name
        shuffle(directions.begin(), directions.end(), std::mt19937(std::random_device()())); //It shuffles all directions in the direction list
        for (int i = 0; i < directions.size(); i++) {
            moveCommand = columnName + rowName + "-" + directions[i]; //It builds a command for given random peg and adds a random direction
            //cout<<moveCommand<<"*******"<<endl;
            if (isLegal(inputBoard, moveCommand)) { //If the command is legal, It moves the peg
                movePegComputerHelper(inputBoard, moveCommand); //It calls helper method to make a move
                cout << "Computer move: " << moveCommand << endl << endl; //prints out the computer move
                counter++;
                break;
            }
        }

    }
    if (counter == 0) //Warns user that game is over if computer can't make any move
        cout << "Computer can't make any move because game is over!!" << endl;

}

/**
 * delegation method of play
 */

void PegSolitaire::play() {
    PegSolitaire::play(this->currentBoard);
}


/**
 * This function works for Board1,2,3,4,5
 * This function is nearly the same as movePegComputer function.
 * Only difference is, it doesn't make move instead returns true if any move is able in the game
 * It takes 2d Vector as input
 * @param inputBoard
 * @return
 */
bool PegSolitaire::isOver(vector<vector<Cell>> inputBoard) {
    vector<vector<int>> pegCoordinateList;
    vector<int> pegCoordinates;

    int column, row;
    string columnName, rowName, moveCommand;
    vector<string> directions = { "l","r","u","d" };
    int counter = 0;
    pegCoordinateList = returnPegCoordinates(inputBoard);
    shuffle(pegCoordinateList.begin(), pegCoordinateList.end(), std::mt19937(std::random_device()()));
    while (true) {
        if (counter != 0 || pegCoordinateList.empty())
            break;
        pegCoordinates = pegCoordinateList.back();
        pegCoordinateList.pop_back();

        column = pegCoordinates[1];
        row = pegCoordinates[0] + 1; //Adding +1 because rows begin at 1 not 0
        //cout<<row<<"**"<<column<<endl;
        rowName = to_string(row);
        columnName = columnNames[column];
        shuffle(directions.begin(), directions.end(), std::mt19937(std::random_device()()));
        for (int i = 0; i < directions.size(); i++) {
            moveCommand = columnName + rowName + "-" + directions[i];
            //cout<<moveCommand<<"*******"<<endl;
            if (isLegal(inputBoard, moveCommand)) {
                return false;
                counter++;
                break;
            }
        }

    }
    if (counter == 0)
        return true;

}

/**
 * Delegation method of isOver
 * @return
 */
bool PegSolitaire::isOver() {
    return PegSolitaire::isOver(this->currentBoard);
}

/**
 * This method plays the given board automatically until it finishes
 * This method is also recursive method
 * This method uses play() method for every single move
 * @param inputBoard
 */

void PegSolitaire::playGame(vector<vector<Cell>> &inputBoard) {
    if(isOver()) //base case for recursion
        cout<<"Computer finished the game"<<endl;
    else{ //general case for recursion
        play(inputBoard); //It makes a single computer move
        showBoard(inputBoard); //Shows the board
        playGame(inputBoard); //method calls itself until reaches the base case
    }
}

/**
 * Delegation method of playGame
 */
void PegSolitaire::playGame() {
    playGame(this->currentBoard);
}


/**
 * This function returns columns names with respect to their rows.
 * In Board6, every row stars with A for first peg in that specific column
 * This function takes 2d vector, sourceRow and source column as input
 * So in converts the given column to real column for the specific row by counting pegs
 * For ex: to reach 3rd column in a row, function must count 3 pegs in that column
 * @param inputBoard
 * @param sourceRow
 * @param sourceColumnRelative
 * @return
 */

int PegSolitaire::relativeToRealColumnBoard6(vector<vector<Cell>> inputBoard, int sourceRow, int sourceColumnRelative) {
    sourceColumnRelative++; //Incrementing because first column stars with 1 peg not zero peg
    int pegColumnCounter = 0;
    int sourceColumn = 0;
    for (int i = 0; i < inputBoard[sourceRow].size(); i++) {
        if (inputBoard[sourceRow][i].getCellState() == 'p')
            pegColumnCounter++; //Increment counter for every peg in given column
        if (pegColumnCounter == sourceColumnRelative) { //Stop if counted pegs are equal to given column
            sourceColumn = i;
            break;
        }
    }
    return sourceColumn; //return real column value of specific row in Board6
}

/**
 * Delegation method of relativeToRealColumnBoard6
 * @param sourceRow
 * @param sourceColumnRelative
 * @return
 */
int PegSolitaire::relativeToRealColumnBoard6(int sourceRow, int sourceColumnRelative) {
    return PegSolitaire::relativeToRealColumnBoard6(this->currentBoard,sourceRow,sourceColumnRelative);
}

/**
 * This method is for Board6
 * It takes 2d vector, integer row and integer column as inputs
 * It returns string column name for specific row in Board6
 * @param inputBoard
 * @param row
 * @param inputColumn
 * @return
 */
string PegSolitaire::numberToColumnName6(vector<vector<Cell>> inputBoard, int row, int inputColumn) {
    int pegColumnCounter = 0;
    for (int i = 0; i <= inputColumn; i++) { //Stops counting when it reaches the given column
        if (inputBoard[row][i].getCellState()== 'p')
            pegColumnCounter++; //Increment counter for each peg
    }
    if (pegColumnCounter == 1)
        return "a";
    else if (pegColumnCounter == 2)
        return "b";
    else if (pegColumnCounter == 3)
        return "c";
    else if (pegColumnCounter == 4)
        return "d";
    else if (pegColumnCounter == 5)
        return "e";
    else
        return "-1";
}

/**
 * Delegation method of numberToColumnName6
 * @param row
 * @param inputColumn
 * @return
 */
string PegSolitaire::numberToColumnName6(int row, int inputColumn) {
    return PegSolitaire::numberToColumnName6(this->currentBoard,row,inputColumn);
}

/**
 * This method is for Board6
 * It takes 2d vector, string command as input
 * For Board6, there are default empty cells for true representation
 * For ex: For moving left, the peg should go to 4 columns left but we see this as 2 columns lefter change in Board6
 * For ex: For moving up, The peg should go to 2 columns up and 2 columns left or right but we see this as 2 columns upper change in Board6
 * @param inputBoard
 * @param moveCommand
 * @return
 */
bool PegSolitaire::isLegalBoard6(vector<vector<Cell>> inputBoard, string moveCommand) {
    transform(moveCommand.begin(), moveCommand.end(), moveCommand.begin(), ::tolower); //It converts given string to lowercase
    string inputSourceRow, moveDirection;
    char inputSourceColumn;

    if(moveCommand.size()==4){
        inputSourceColumn = moveCommand[0];
        inputSourceRow = moveCommand[1];
        moveDirection = moveCommand[3];
    }

    else if(moveCommand.size()==5){ //Don mutlaka buraya
        inputSourceColumn = moveCommand[0];
        inputSourceRow = moveCommand[1]+moveCommand[2];
        moveDirection = moveCommand[4];
    }

    else{
        cerr<<"Wrong command type!"<<endl;
        return false;
    }


    int sourceRow = stoi(inputSourceRow); //It converts string row to integer type
    sourceRow--; //Because rows are starting with 1 not zero

    int sourceColumnRelative = findIndexOfLetter(inputSourceColumn); //This  location is relative for every row.
    int sourceColumn = relativeToRealColumnBoard6(inputBoard, sourceRow, sourceColumnRelative); //It converts relative column to real column in the Board6

    if (moveDirection == "u") {
        if (sourceRow < 2) //This if state prevents segmantation fault
            return false;
        Cell sourceCell;
        Cell middleCell;
        Cell middleCell2;
        Cell targetCell;
        Cell targetCell2;
        if (sourceColumn <= 2) {//Peg can't go left in this situation
            sourceCell = inputBoard[sourceRow][sourceColumn];
            middleCell = inputBoard[sourceRow - 1][sourceColumn + 1];
            targetCell = inputBoard[sourceRow - 2][sourceColumn + 2]; //Goes to right direction
        }

        else if (inputBoard[0].size() - sourceColumn <= 2) { //Peg can't go right in this situation
            sourceCell = inputBoard[sourceRow][sourceColumn];
            middleCell = inputBoard[sourceRow - 1][sourceColumn - 1];
            targetCell = inputBoard[sourceRow - 2][sourceColumn - 2]; //Goes to upper left direction
        }
        else { //If there is no left or right resctriction for the cell, It tries to go both direction in order.
            sourceCell = inputBoard[sourceRow][sourceColumn];
            middleCell = inputBoard[sourceRow - 1][sourceColumn - 1]; //Middle of Left
            middleCell2 = inputBoard[sourceRow - 1][sourceColumn + 1]; // Middle of Right
            targetCell = inputBoard[sourceRow - 2][sourceColumn - 2]; //Target of Left
            targetCell2 = inputBoard[sourceRow - 2][sourceColumn + 2]; //Target of Right

            if (sourceCell.getCellState() =='p' && middleCell.getCellState() == 'p'&& targetCell.getCellState() == '.') {
               // cout<<"hello1"<<endl;
                return true;
            }//It first tries to check upper right

            else if (sourceCell.getCellState()== 'p' && middleCell2.getCellState() == 'p' && targetCell2.getCellState() == '.') {
                //cout<<"hello2"<<endl;
                return true;
            }//Then it tries to check upper right

            else{
                //cout<<"hello3"<<endl;
                return false;
            }//Peg can't go anywhere towards upper direction

        }

        if (sourceCell.getCellState() == 'p' && middleCell.getCellState() == 'p' && targetCell.getCellState() == '.')
            return true;
        else
            return false;

    }
    else if (moveDirection == "d") {
        if (sourceRow >= inputBoard.size() - 2) //This if state prevents segmantation fault
            return false;

        Cell sourceCell;
        Cell middleCell;
        Cell middleCell2;
        Cell targetCell;
        Cell targetCell2;
        if (sourceColumn <= 2) {//Peg can't go left in this situation. It can go to only right direction
            sourceCell = inputBoard[sourceRow][sourceColumn];
            middleCell = inputBoard[sourceRow + 1][sourceColumn + 1];
            targetCell = inputBoard[sourceRow + 2][sourceColumn + 2];
        }

        else if (inputBoard[0].size() - sourceColumn <= 2) { //Peg can't go right in this situation. It can go to only left direction.
            sourceCell = inputBoard[sourceRow][sourceColumn];
            middleCell = inputBoard[sourceRow + 1][sourceColumn - 1];
            targetCell = inputBoard[sourceRow + 2][sourceColumn - 2];
        }
        else { //If there is no left or right resctriction for the cell, It tries to go both direction in order.
            sourceCell = inputBoard[sourceRow][sourceColumn];
            middleCell = inputBoard[sourceRow + 1][sourceColumn - 1]; //Middle of Left
            middleCell2 = inputBoard[sourceRow + 1][sourceColumn + 1]; // Middle of Right
            targetCell = inputBoard[sourceRow + 2][sourceColumn - 2]; //Target of Left
            targetCell2 = inputBoard[sourceRow + 2][sourceColumn + 2]; //Target of Right

            if (sourceCell.getCellState() == 'p'&& middleCell.getCellState() == 'p' && targetCell.getCellState() == '.') //It first tries to check upper right
                return true;
            else if (sourceCell.getCellState() == 'p' && middleCell2.getCellState() == 'p' && targetCell2.getCellState() == '.') //Then it tries to check upper right
                return true;
            else //Peg can't go anywhere towards downer direction
                return false;
        }

        if (sourceCell.getCellState() == 'p'&& middleCell.getCellState() == 'p' && targetCell.getCellState() == '.')
            return true;
        else
            return false;

    }

    else if (moveDirection == "l") {
        if (sourceColumn < 3) //This if state prevents segmantation fault
            return false;

        Cell sourceCell = inputBoard[sourceRow][sourceColumn]; //source cell
        Cell middleCell = inputBoard[sourceRow][sourceColumn - 2]; //middle cell
        Cell targetCell = inputBoard[sourceRow][sourceColumn - 4]; //target cell

        //cout<<sourceCell.getCellState()<<" "<<middleCell.getCellState()<<" "<<targetCell.getCellState()<<endl;

        if (sourceCell.getCellState() == 'p' && middleCell.getCellState() == 'p' && targetCell.getCellState() == '.')
            return true;
        else
            return false;


    }

    else if (moveDirection == "r") {
        if (sourceColumn >= inputBoard[0].size() - 3) //This if state prevents segmantation fault
            return false;

        Cell sourceCell = inputBoard[sourceRow][sourceColumn]; //source cell
        Cell middleCell = inputBoard[sourceRow][sourceColumn + 1]; //middle cell
        Cell targetCell = inputBoard[sourceRow][sourceColumn + 2]; //target cell

        if (sourceCell.getCellState() == 'p' && middleCell.getCellState() == 'p'&& targetCell.getCellState() == '.')
            return true;
        else
            return false;
    }

    else
        return false;
}


/**
 * Delegation method of isLegalBoard6
 * @param moveCommand
 * @return
 */
bool PegSolitaire::isLegalBoard6(string moveCommand) {
    return PegSolitaire::isLegalBoard6(this->currentBoard,moveCommand);
}

/**
 * This method is for Board6 to make move
 * It takes 2d vector reference and string command as input
 * For Board6, there are default empty cells for true representation
 * For ex: For moving left, the peg should go to 4 columns left but we see this as 2 columns lefter change in Board6
 * For ex: For moving up, The peg should go to 2 columns up and 2 columns left or right but we see this as 2 columns upper change in Board6
 * It makes moves if only the given command is legal
 * @param inputBoard
 * @param moveCommand
 */
void PegSolitaire::play6(vector<vector<Cell>> &inputBoard, string moveCommand) {
    if (isLegalBoard6(inputBoard, moveCommand)) { //It first check if the given command is legal
        transform(moveCommand.begin(), moveCommand.end(), moveCommand.begin(), ::tolower); //It converts given string to lowercase
        string inputSourceRow, moveDirection;
        char inputSourceColumn;

        if(moveCommand.size()==4){
            inputSourceColumn = moveCommand[0];
            inputSourceRow = moveCommand[1];
            moveDirection = moveCommand[3];
        }

        else if(moveCommand.size()==5){ //Don mutlaka buraya
            inputSourceColumn = moveCommand[0];
            inputSourceRow = moveCommand[1]+moveCommand[2];
            moveDirection = moveCommand[4];
        }

        int sourceRow = stoi(inputSourceRow); //It converts string row to integer type
        sourceRow--; //Because rows are starting with 1 not zero

        int sourceColumnRelative = findIndexOfLetter(inputSourceColumn); //This  location is relative for every row.
        int sourceColumn = relativeToRealColumnBoard6(inputBoard, sourceRow, sourceColumnRelative); //It converts relative column to real column in the Board6

        inputBoard[sourceRow][sourceColumn].setCellState('.');//It makes the source cell empty first

        if (moveDirection == "u") {

            if (sourceColumn <= 2) {//Peg can't go left in this situation
                inputBoard[sourceRow - 1][sourceColumn + 1].setCellState('.');
                inputBoard[sourceRow - 2][sourceColumn + 2].setCellState('p');
            }

            else if (inputBoard[0].size() - sourceColumn <= 2) { //Peg can't go right in this situation
                inputBoard[sourceRow - 1][sourceColumn - 1].setCellState('.');
                inputBoard[sourceRow - 2][sourceColumn - 2].setCellState('p');
            }
            else {
                Cell middleCell = inputBoard[sourceRow - 1][sourceColumn - 1]; //Middle of Left
                Cell targetCell = inputBoard[sourceRow - 2][sourceColumn - 2]; //Target of Left

                if (middleCell.getCellState() == 'p' && targetCell.getCellState() == '.') { //It tries to go upper left
                    inputBoard[sourceRow - 1][sourceColumn - 1].setCellState('.');
                    inputBoard[sourceRow - 2][sourceColumn - 2].setCellState('p');
                }

                else { //Else it definitely goes up right direction
                    inputBoard[sourceRow - 1][sourceColumn + 1].setCellState('.');
                    inputBoard[sourceRow - 2][sourceColumn + 2].setCellState('p');
                }
            }
        }


        else if (moveDirection == "d") {
            if (sourceColumn <= 2) {//Peg can't go left in this situation
                inputBoard[sourceRow + 1][sourceColumn + 1].setCellState('.');
                inputBoard[sourceRow + 2][sourceColumn + 2].setCellState('p');
            }

            else if (inputBoard[0].size() - sourceColumn <= 2) { //Peg can't go right in this situation
                inputBoard[sourceRow + 1][sourceColumn - 1].setCellState('.');
                inputBoard[sourceRow + 2][sourceColumn - 2].setCellState('p');
            }
            else {
                Cell middleCell = inputBoard[sourceRow + 1][sourceColumn - 1]; //Middle of Left
                Cell targetCell = inputBoard[sourceRow + 1][sourceColumn - 2]; //Target of Left

                if (middleCell.getCellState() == 'p' && targetCell.getCellState() == '.') { //It tries to go upper left
                    inputBoard[sourceRow + 1][sourceColumn - 1].setCellState('.');
                    inputBoard[sourceRow + 2][sourceColumn - 2].setCellState('p');
                }

                else { //Else it definitely go down-right direction
                    inputBoard[sourceRow + 1][sourceColumn + 1].setCellState('.');
                    inputBoard[sourceRow + 2][sourceColumn + 2].setCellState('p');
                }
            }
        }

        else if (moveDirection == "l") { //left direction
            inputBoard[sourceRow][sourceColumn - 2].setCellState('.');
            inputBoard[sourceRow][sourceColumn - 4].setCellState('p');
        }

        else if (moveDirection == "r") { //right direction
            inputBoard[sourceRow][sourceColumn + 2].setCellState('.');
            inputBoard[sourceRow][sourceColumn + 4].setCellState('p');
        }

    }
    else
        cout << moveCommand << " is illegal move!" << endl; //Warning for illegal moves

}


/**
 * Delegation method of play6
 * @param moveCommand
 */
void PegSolitaire::play6(string moveCommand) {
    PegSolitaire::play6(this->currentBoard,moveCommand);
}

/**
 * This function works for just Board6
 * Input is a 2d Vector reference
 * It takes a Board and tries to make a random computer move
 * It can't make any move if the game is over
 * It shuffles all peg coordinates and takes the last peg in the vector to make a move every time.
 * @param inputBoard
 */
void PegSolitaire::play6(vector<vector<Cell>> &inputBoard) {

    vector<vector<int>> pegCoordinateList; //2d Peg coordinate list
    vector<int> pegCoordinates; //Peg coordinate vector

    int column, row;
    string columnName, rowName, moveCommand;
    vector<string> directions = { "l","r","u","d" }; //String list of directions
    int counter = 0;
    pegCoordinateList = returnPegCoordinates(inputBoard); //Takes peg coordinates in the board6 by the function
    shuffle(pegCoordinateList.begin(), pegCoordinateList.end(), std::mt19937(std::random_device()())); //It shuffles all coordinates of pegs in the board6
    while (true) {
        if (counter != 0 || pegCoordinateList.empty()) //It stops if it makes a move or peg coordinate list becomes empty
            break;
        pegCoordinates = pegCoordinateList.back(); //It returns last peg coordinate in the vector
        pegCoordinateList.pop_back(); //It pop last peg coordinate in the vector


        row = pegCoordinates[0] + 1; //Adding +1 because rows begin at 1 not 0
        column = pegCoordinates[1];

        rowName = to_string(row); //converts row name to string
        columnName = numberToColumnName6(inputBoard, row - 1, column); //It returns the column name of given relative column in Board6

        shuffle(directions.begin(), directions.end(), std::mt19937(std::random_device()())); //It shuffles all directions everytime
        for (int i = 0; i < directions.size(); i++) {
            moveCommand = columnName + rowName + "-" + directions[i];
            if (isLegalBoard6(inputBoard, moveCommand)) {
                play6(inputBoard, moveCommand);
                cout << "Computer move: " << moveCommand << endl << endl; //Prints out the computer move
                counter++; //Increment counter for any computer move
                break;
            }
        }

    }
    if (counter == 0)
        cout << "Computer can't make any move because game is over!!" << endl; //Warns the user if there is no available move in the Board6

}
/**
 * Delegation method of play6
 */
void PegSolitaire::play6() {
    PegSolitaire::play6(this->currentBoard);
}

/**
 * This function is almost the same as movePegComputer6.
 * Only difference is, it doesn't make any move, instead returns true if it detects any legal move available
 * @param inputBoard
 * @return
 */
bool PegSolitaire::isOverBoard6(vector<vector<Cell>> inputBoard) {
    vector<vector<int>> pegCoordinateList;
    vector<int> pegCoordinates;

    int column, row;
    string columnName, rowName, moveCommand;
    vector<string> directions = { "l","r","u","d" };
    int counter = 0;
    pegCoordinateList = returnPegCoordinates(inputBoard);
    shuffle(pegCoordinateList.begin(), pegCoordinateList.end(), std::mt19937(std::random_device()()));
    while (true) {
        if (counter != 0 || pegCoordinateList.empty())
            break;
        pegCoordinates = pegCoordinateList.back();
        pegCoordinateList.pop_back();


        row = pegCoordinates[0] + 1; //Adding +1 because rows begin at 1 not 0
        column = pegCoordinates[1];

        //cout<<row<<"**"<<relativeColumn<<endl;
        //cout<<row<<"***"<<column<<endl;

        rowName = to_string(row);
        columnName = numberToColumnName6(inputBoard, row - 1, column);
        shuffle(directions.begin(), directions.end(), std::mt19937(std::random_device()()));
        for (int i = 0; i < directions.size(); i++) {
            moveCommand = columnName + rowName + "-" + directions[i];
            //cout<<moveCommand<<"*******"<<endl;
            if (isLegalBoard6(inputBoard, moveCommand)) {
                return false;
                counter++;
                break;
            }
        }

    }
    if (counter == 0)
        return true;
    return false;
}
/**
 * Delegation method of isOVerBoard6
 * @return
 */
bool PegSolitaire::isOverBoard6() {
    return PegSolitaire::isOverBoard6(this->currentBoard);
}

/**
 * This method is only for Board6
 * This method plays the given board automatically until it finishes
 * This method is also recursive method
 * This method uses play6() method for every single move
 * @param inputBoard
 */

void PegSolitaire::playGame6(vector<vector<Cell>>& inputBoard) {
    if(isOverBoard6()) //Base case for recursion
        cout<<"Computer has finished the game"<<endl;
    else{ //General case
        play6(inputBoard); //MAkes a single computer move for Board6
        showBoard(inputBoard,true); //Shows board6
        playGame6(inputBoard); //Calls method itself until the game ends
    }
}


/**
 * Delegation method of playGame6
 */
void PegSolitaire::playGame6() {
    playGame6(this->currentBoard);
}


/**
* This function shows the score according to remainder pegs
*/
void PegSolitaire::showScore(int numberOfPegs) {
    cout << "Your score is " << 1000 - (numberOfPegs - 1) * 50 << " (Best Score is 1000)" << endl;
}

/**
 * This function saves the specific game at that specific moment into a text file
 * In the saved text file, first line declares if the board is diagonal (1 or 0)
 * Second line shows number of person moves
 * Third line shows number of computer moves
 * Fourth line shows number of pegs
 * The rest lines belong to the board itself
 * Input parameters are 2d Vector reference, integer number of person move, computer move, peg numbers,
 * and boolean value that shows whether the board is diagonal
 */
void PegSolitaire::saveGame(const vector<vector<Cell>> &inputBoard, int personMove, int computerMove, int pegNumbers,
                            bool isDiagonal) {
    string fileName;
    cout << "Please enter the name of txt file that you want to save in:"<<endl;
    cin >> fileName;
    //fileName += ".txt";
    ofstream myfile; //fstream library to create a text file
    myfile.open(fileName);
    myfile << to_string(isDiagonal) << "\n" << to_string(personMove) << "\n" << to_string(computerMove) << "\n" << to_string(pegNumbers) << "\n"; //Saving some stats of the given game
    for (vector<Cell> v : inputBoard) { //Saving the board at that moment
        for (Cell c : v) {
            if (c.getCellState() == 'p')
                myfile << "p";
            else if (c.getCellState() == '.')
                myfile << ".";
            else if (c.getCellState() == ' ')
                myfile << " ";
            else
                continue;
        }
        myfile << "\n";
    }
    cout << "Board and stats are succesfully saved in the text file of " << fileName << endl;
    myfile.close();

}
/**
 * Delegation method of saveGame
 * @param personMove
 * @param computerMove
 * @param pegNumbers
 * @param isDiagonal
 */
void PegSolitaire::saveGame(int personMove, int computerMove, int pegNumbers, bool isDiagonal) {
    PegSolitaire::saveGame(this->currentBoard,personMove,computerMove,pegNumbers,isDiagonal);
}
/**
 * This method returns number of  taken pegs
 * @param initialPegs is initial number of pegs
 * @param currentPegs is final number of pegs
 * @return
 */
int PegSolitaire::takenPegs(const int &initialPegs, const int &currentPegs) const {
    return initialPegs-currentPegs;
}

/**
 * This function is responsible for playing game in a while true loop
 * input parameter are 2d vector reference, integer person and computer moves,
 * and boolean isDiagonal value, which is true if the game moves are diagonal like Board6
 * @param inputBoard
 * @param personMove
 * @param computerMove
 * @param isDiagonal
 * */
void PegSolitaire::playMenu(vector<vector<Cell>> &inputBoard, int personMove, int computerMove, bool isDiagonal) {
    int pegNumber; //current number of pegs
    int initialPegs= numberOfPegs(inputBoard); //initial number of pegs
    string userCommand; //String user command
    string moveMessage = "Enter enter a command to make a move (ex:b4-r)\n";
    string exitMessage = "Enter 0 (zero) to end the game\n";
    string computerMessage = "Enter c to make computer a move\n";
    string saveMessage = "Enter s to save your game with current board and stats\n";
    string finishComputerMessage="Enter f to finish the game with computer moves\n";
    totalPegs.push_back(numberOfPegs(inputBoard)); //Pushes number of pegs information in a static vector
    if (isDiagonal == false) { //This if statement is for boards like board1,2,3,4,5
        while (true) {
            showBoard(inputBoard); //Prints out the given board
            cout << moveMessage << computerMessage << exitMessage << saveMessage<<finishComputerMessage<<endl; //Informs user about game and menu
            cin >> userCommand;
            if (userCommand == "0" || isOver(inputBoard)) { //It finishes the game if user enter 0 or there is no available move in the board
                showBoard(inputBoard);
                cout << "You end the game with " << numberOfPegs(inputBoard) << " Pegs" << endl;
                cout<<"Computer Move: "<<computerMove<<endl;
                cout<<"Person Move: "<<personMove<<endl;
                cout<<"Number of Pegs: "<<numberOfPegs(inputBoard)<<"\t"
                <<"Number of Empty cells: "<<numberOfEmpty(inputBoard)<<endl;
                cout<<"Taken pegs: "<<takenPegs(initialPegs, numberOfPegs(inputBoard))<<endl;
                showScore(numberOfPegs(inputBoard)); //shows score
                break;
            }
            else if (userCommand == "c") { //c commands make computer a new move
                play(inputBoard);
                computerMove++; //increment number of computer moves
                totalPegs.pop_back();
                totalPegs.push_back(numberOfPegs(inputBoard)); //Pushes number of pegs information in a static vector
            }

            else if (userCommand == "f") { //c commands make computer a new move
                playGame(inputBoard);
                totalPegs.pop_back();
                totalPegs.push_back(numberOfPegs(inputBoard)); //Pushes number of pegs information in a static vector
            }

            else if (userCommand == "s") { //s commands saves the game in a txt file
                saveGame(inputBoard, personMove, computerMove, numberOfPegs(inputBoard));
                break;
            }

            else if (4<=userCommand.size()<=5) { //if size=4, command should be a move command by a person
                if (isLegal(inputBoard, userCommand))
                    personMove++; //Increment number of person moves
                play(inputBoard, userCommand);
                totalPegs.pop_back();
                totalPegs.push_back(numberOfPegs(inputBoard)); //Pushes number of pegs information in a static vector
            }

            else
                cerr << "Please enter a valid command!" << endl;

        }
    }
    else { //This if statement is for boards like board6 (diagonal). Only difference is move functions.
        while (true) {
            showBoard(inputBoard, true);
            cout << moveMessage << computerMessage << exitMessage << saveMessage<<finishComputerMessage<<endl; //Informs user about game and menu
            cin >> userCommand;
            if (userCommand == "0" || isOverBoard6(inputBoard)) {
                showBoard(inputBoard, true);
                cout << "You end the game with " << numberOfPegs(inputBoard) << " Pegs" << endl;
                cout<<"Computer Move: "<<computerMove<<endl;
                cout<<"Person Move: "<<personMove<<endl;
                cout<<"Number of Pegs: "<<numberOfPegs(inputBoard)<<"\t"
                    <<"Number of Empty cells: "<<numberOfEmpty(inputBoard)<<endl;
                showScore(numberOfPegs(inputBoard));
                break;
            }
            else if (userCommand == "c") {
                play6(inputBoard);
                computerMove++;
                totalPegs.pop_back();
                totalPegs.push_back(numberOfPegs(inputBoard)); //Pushes number of pegs information in a static vector
            }

            else if (userCommand == "f") { //c commands make computer a new move
                playGame6(inputBoard);
                totalPegs.pop_back();
                totalPegs.push_back(numberOfPegs(inputBoard)); //Pushes number of pegs information in a static vector
            }

            else if (userCommand == "s") {
                saveGame(inputBoard, personMove, computerMove, numberOfPegs(inputBoard),true);
                break;
            }

            else if (4<=userCommand.size()<=5) {
                if (isLegalBoard6(inputBoard, userCommand))
                    personMove++;
                play6(inputBoard, userCommand);
                totalPegs.pop_back();
                totalPegs.push_back(numberOfPegs(inputBoard)); //Pushes number of pegs information in a static vector
            }

            else
                cerr << "Please enter a valid command!" << endl;
        }

    }
}

/**
 * Delegation method of playMenu
 * @param personMove
 * @param computerMove
 * @param isDiagonal
 */
void PegSolitaire::playMenu(int personMove, int computerMove, bool isDiagonal) {
    PegSolitaire::playMenu(this->currentBoard,personMove,computerMove,isDiagonal);
}
/**
 * This is a static method
 * This functios shows all files in current directory to inform user
 * Thanks to this function, user can select a load file or save file from current directory
 * It uses dirent.h library and works for linux enviroments
 */
void PegSolitaire::showFiles() {
    struct dirent *d; //This pointer is from dirent library
    DIR *dr;
    dr = opendir(".");
    if(dr!=NULL)
    {
        cout<<"List of Files and Folders:\n";
        while((d=readdir(dr))!=NULL)
            cout<<d->d_name<<endl;
        closedir(dr);
    }
    else
        cerr<<"\nError Occurred!"; //Error message
    cout<<endl;
}

/**
 *
 * @param fileName
 * @return
 */


/**
 * This functions gets stats like person move, computer move and is diagonal from a saved txt file
 * Only input is string file name
 * it returns 1d vector that stores stats
 * @param fileName
 * @return
 */


vector<int> PegSolitaire::getStats(string fileName) {
    string str;
    int computerMove, personMove,isDiagonal;
    vector<int> stats; //1d vector that stores stats

    ifstream file(fileName); // Read from the text file


    file>>isDiagonal; //Reading 1st line
    file>>personMove; //Reading 2nd line
    file>>computerMove; //Reading 3rd line

    stats.push_back(isDiagonal);
    stats.push_back(personMove);
    stats.push_back(computerMove);

    return stats; //return the vector
}

vector<int> PegSolitaire::totalPegs={0}; //Initializes the static totalPegs vector
int PegSolitaire::totalNumberOfPegs=0; //Initializes the static totalNumberOfPegs integer

/**
 * This method returns total number of pegs in active classes by using a static vector and integer values
 * @return
 */
int PegSolitaire::totalActivePegs() {
    for(int element: PegSolitaire::totalPegs)
        PegSolitaire::totalNumberOfPegs+=element;
    return PegSolitaire::totalNumberOfPegs;
}

/**
 * This method compares number of pegs with another class
 * @param otherClass
 * @return
 */

bool PegSolitaire::hasMore(const PegSolitaire& otherClass) {
    int myClassPegNumber= numberOfPegs(currentBoard);
    int otherClassPegNumber= numberOfPegs(otherClass.getCurrentBoard());
    bool hasMore=myClassPegNumber>otherClassPegNumber;

    return hasMore;
}


















































