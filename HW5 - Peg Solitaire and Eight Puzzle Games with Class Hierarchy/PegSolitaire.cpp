//
// Created by darkb on 12.12.2021.
//

#include "PegSolitaire.h"

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <algorithm> //This library is necessary for shuffling a vector
#include<fstream> //File read write library
#include <unistd.h>




using namespace std;


vector<char> columnNames {'a','b','c','d','e','f','g','h','i','j','k','l','m','n'
        ,'o','p','q','r','s','t','u','v','w','x','y','z'}; //This is list of english letters in order

/**
* This is no parameter constructor
* It starts the game with Board2
*/
baris::PegSolitaire::PegSolitaire() {
    initialize();
}

/**
 * This constructor starts the game by taking string fileName parameter
 * @param fileName file name
 */

baris::PegSolitaire::PegSolitaire(string fileName) {
    this->fileName=fileName;
    readFile(fileName);
}


const vector<vector<baris::PegSolitaire::Cell>> &baris::PegSolitaire::getCurrentBoard() const {
    return currentBoard;
}

void baris::PegSolitaire::setCurrentBoard(const vector<vector<Cell>> &currentBoard) {
    PegSolitaire::currentBoard = currentBoard;
}

const string &baris::PegSolitaire::getFileName() const {
    return fileName;
}

void baris::PegSolitaire::setFileName(const string &fileName) {
    PegSolitaire::fileName = fileName;
}



/**
 *  This method converts string column names to integer values (A=0,B=1,C=2...)
 * @param letter
 * @return
 */

int baris::PegSolitaire::findIndexOfLetter(char letter) const {
    for (int i = 0; i < columnNames.size(); ++i) {
        if (columnNames[i] == letter)
            return i;
    }
    return -1;

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

bool baris::PegSolitaire::isLegal(vector<vector<Cell>> inputBoard, string moveCommand) const {
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
 * This function works for Board1,2,3,4,5
 * This function is nearly the same as playAuto()
 * Only difference is, it doesn't make move instead returns true if any move is able in the game
 * It takes 2d Vector as input
 * @param inputBoard
 * @return
 */
bool baris::PegSolitaire::endGame(vector<vector<Cell>> inputBoard) const{
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
 * This method is delegator method of isLegal
 * @param command
 * @return
 */
bool baris::PegSolitaire::isLegal(string command) const {
    return isLegal(this->currentBoard,command);
}

/**
 * This method is delegator method of playUser
 * @param command
 */
void baris::PegSolitaire::playUser(string command) {
    playUser(this->currentBoard,command);
    cout<<*this<<endl;
}

/**
 * This method is delegator method of endGame
 * @return
 */
bool baris::PegSolitaire::endGame() const {
    return endGame(this->currentBoard);
}

/**
 * This method is delegator method of playAuto
 */
void baris::PegSolitaire::playAuto() {
    playAuto(this->currentBoard);
    cout<<*this<<endl;
    //usleep(200000);


}

/**
 * This function takes 1 input
 * Second input is type of the Board(1,2,3,4,5)
 * It prints out a given Board by nested for loops
 * @param &os is ostream object
 */

void baris::PegSolitaire::print(ostream &os) const {
    int rowNumber = 1; //it begins from 1

    os << "\n\t";
    int columnNumbers = currentBoard[0].size();

    for (int i = 0; i < columnNumbers; i++) {
        os << columnNames[i]<<" ";
    }
    os << endl;

    for (auto & iter1 : currentBoard) { //Iterator1
        os << rowNumber << "\t";
        rowNumber++;

        for (auto & iter2 : iter1) { //Iterator2
            os<<iter2.getCellState()<<" ";
        }
        os << endl;
    }




}

/**
 * This function returns score of the game
 * @return
 */
int baris::PegSolitaire::boardScore() const {
    return (numberOfPegs(this->currentBoard)-1)*50;
}

/**
 *
 */
void baris::PegSolitaire::initialize() {
    this->fileName="board2.txt";
    readFile(fileName);
    cout<<"Peg Solitaire is initialized"<<*this<<endl;
}

/**
 * This is move function of person inputs for Board1,2,3,4,5
 * First Input is 2d Vector Reference
 * Second input is string command
 * It makes a move if the given command is legal
 * @param inputBoard
 * @param moveCommand
 */
void baris::PegSolitaire::playUser(vector<vector<Cell>> &inputBoard, string moveCommand) {

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

        cout<<"Your move is: "<<moveCommand<<endl;
    }
    else
        cout << moveCommand << " is illegal move!" << endl; //Warning for illegal moves

}



/**
 * This function is for non-dioganal Boards like Board1,2,3,4,5
 * This functions iterates throughs a given Board and returns number of pegs
 * Input is a 2d Vector
 * @param inputBoard
 * @return
 */
vector<vector<int>> baris::PegSolitaire::returnPegCoordinates(vector<vector<Cell>> inputBoard) const{
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
 * This method uses textToVectors method and saves the output in 2D vector type of class(currentBoard)
 * @param fileName
 */
inline void baris::PegSolitaire::readFile(string fileName) {
    this->currentBoard= textToVectors(fileName);
}


/**
 * This functions reads a text file and converts into a 2d vector
 * Only input parameter is string name of specific txt file
 * @param fileName
 * @return
 */

vector<vector<baris::PegSolitaire::Cell>> baris::PegSolitaire::textToVectors(string fileName) {
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
 * Input is a 2d Vector reference
 * It takes a Board and tries to make a random computer move
 * It can't make any move if the game is over
 * It shuffles all peg coordinates and takes the last peg in the vector to make a move every time.
 * @param inputBoard
 */
void baris::PegSolitaire::playAuto(vector<vector<Cell>>& inputBoard) {
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
                usleep(200000);
                counter++;
                break;
            }
        }

    }
    if (counter == 0) //Warns user that game is over if computer can't make any move
        cout << "Computer can't make any move because game is over!!" << endl;

}

/**
 * This functions is nearly same as playUser
 * Only difference is, it doesn't warn for illegal moves because computer needs to try so many illegal moves to find a legal move
 * This function is for Board1,2,3,4,5
 * First Input is 2d Vector Reference
 * Second input is string command
 * @param inputBoard
 * @param moveCommand
 */
void baris::PegSolitaire::movePegComputerHelper(vector<vector<Cell>> &inputBoard, string moveCommand) {

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
 * This method returns number of pegs in given 2D vector (Board)
 * @param inputBoard
 * @return
 */
int baris::PegSolitaire::numberOfPegs(const vector<vector<Cell>>& inputBoard) const{
    int pegCounter = 0;
    for (const vector<Cell>& innerVector : inputBoard) //Nested ranged for loops
        for (Cell c : innerVector)
            if (c.getCellState() == 'p')
                pegCounter++;
    return pegCounter;
}


/**
 * This constructor constructs a Cell class by using integer coordinates and cell state
 * @param x
 * @param y
 * @param cellState
 */

baris::PegSolitaire::Cell::Cell(int x, int y, char cellState) : x(x), y(y), cellState(cellState) {}

/**
 * This is no parameter contructor of Cell class
 * x=0, y=0 and state is nonused
 */

baris::PegSolitaire::Cell::Cell() {
    this->x=0;
    this->y=0;
    this->cellState=' ';
    this->currentCell=cell::nonUsed;
}



/**
 * getter of x coordinate of Cell class
 * @return
 */

int baris::PegSolitaire::Cell::getX() const {
    return x;
}
/**
 * setter of x coordinate of Cell class
 * @return
 */

void baris::PegSolitaire::Cell::setX(int x) {
    Cell::x = x;
}


/**
 * getter of y coordinate of Cell class
 * @return
 */

int baris::PegSolitaire::Cell::getY() const {
    return y;
}

/**
 * setter of y coordinate of Cell class
 * @return
 */

void baris::PegSolitaire::Cell::setY(int y) {
    Cell::y = y;
}
/**
 * getter method of cell state of Cell class
 * @return
 */
char baris::PegSolitaire::Cell::getCellState() const {
    return cellState;
}

/**
 * Setter method of cell state of Cell class
 * @param cellState
 */

void baris::PegSolitaire::Cell::setCellState(char cellState) {
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

