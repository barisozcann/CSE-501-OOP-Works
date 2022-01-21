//
// Created by baris2 on 12.12.2021.
//

#include "EightPuzzle.h"
#include <algorithm> //This library is necessary for shuffling a vector
#include <random>

using namespace std;




/**
 * Default constructor calls initialize method for every time
 */
baris2::EightPuzzle::EightPuzzle() {
    initialize();

}



const vector<vector<int>> &baris2::EightPuzzle::getPuzzleBoard() const {
    return puzzleBoard;
}

void baris2::EightPuzzle::setPuzzleBoard(const vector<vector<int>> &puzzleBoard) {
    EightPuzzle::puzzleBoard = puzzleBoard;
}

/**
 * This method calculates inversions for a given 1D Vector
 * If number of inversions are an even number, it returns true
 * @param vector
 * @return
 */
bool baris2::EightPuzzle::isSolvable(vector<int> vector) const {
    int inversions = 0;
    for (int i = 0; i < vector.size()-1; i++)
        for (int j = i+1; j < vector.size(); j++)
            if (vector[i]>vector[j] && vector[j]!=0)
                inversions++;
    return (inversions%2==0);
}

/**
 * This function returns 2D coordinates of a given number in the puzzle board
 * @param number
 * @return
 */
vector<int> baris2::EightPuzzle::getCoordinates(int number) const {
    int x=0;
    int y=0;
    vector<int> coordinates;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(this->puzzleBoard[i][j]==number)
                coordinates={i,j};


    return coordinates;
}

/**
 * This function returns true if given string command is legal
 * @param command
 * @return
 */
bool baris2::EightPuzzle::isLegal(string command) const {
    transform(command.begin(), command.end(), command.begin(), ::tolower); //It converts given string to lowercase
    char firstChar,thirdChar;
    firstChar=command[0];
    thirdChar=command[2];


    if(command.size()!=3 || isdigit(firstChar)==false){
        cout<<command<<" is such an invalid command!"<<endl;
		return false;
    }

    if(endGame())
        cout<<"Game is over you can't make any move"<<endl;

    int number= firstChar-48;
    vector<int> coordinates= getCoordinates(number);
    int x=coordinates[0];
    int y=coordinates[1];

    if(thirdChar=='l'){
        if(y==0)
            return false;
        if(this->puzzleBoard[x][y-1]!=0)
            return false;
    }
    else if(thirdChar=='r'){
        if(y==2)
            return false;
        if(this->puzzleBoard[x][y+1]!=0)
            return false;
    }

    else if(thirdChar=='u'){
        if(x==0)
            return false;
        if(this->puzzleBoard[x-1][y]!=0)
            return false;
    }

    else if(thirdChar=='d'){
        if(x==2)
            return false;
        if(this->puzzleBoard[x+1][y]!=0)
            return false;
    }

    return true;

}


/**
 * This function first check if the given string command is legal
 * If given string command is legal, it moves given number towards to given direction(like 7-u or 8-l)
 * @param command
 */
void baris2::EightPuzzle::playUser(string command) {
    if(isLegal(command)){
        transform(command.begin(), command.end(), command.begin(), ::tolower); //It converts given string to lowercase
        int number=command[0]-48;
        char direction=command[2];

        vector<int> sourceCoordinates= getCoordinates(number);
        int sourceX=sourceCoordinates[0];
        int sourceY=sourceCoordinates[1];
        vector<int> targetCoordinates= getCoordinates(0);
        int targetX=targetCoordinates[0];
        int targetY=targetCoordinates[1];


        this->puzzleBoard[targetX][targetY]=number;
        this->puzzleBoard[sourceX][sourceY]=0;

        cout<<*this<<endl;
    }
    else{
        cout<<command<<" is an illegal move command!"<<endl;
    }



}

/**
 * This function first creates 1D version of puzzle Board
 * If every number in the puzzle board is sequential it returns true
 * @return
 */
bool baris2::EightPuzzle::endGame() const {
    vector<int> vector1D;
    for(const auto& line:puzzleBoard)
        for(auto number:line)
            vector1D.push_back(number);


    if(vector1D.back()!=0)
        return false;

    for(int i=0;i<vector1D.size()-1;i++)
        for(int j=i+1;j<vector1D.size();j++)
            if(vector1D[i]>vector1D[j] && vector1D[j]!=0)
                return false;

    return true;
}

/**
 * This function first finds the location of empty place (location of 0)
 * Then It finds adjacents of empty space to create legal string commands
 * @return list of legal commands
 */
vector<string> baris2::EightPuzzle::availableMoves() const {

    vector<string> adjacentCoordinates;
    vector<int> zeroCoordinates = getCoordinates(0);
    int zeroX = zeroCoordinates[0];
    int zeroY = zeroCoordinates[1];

    if (zeroX < 1) { //x is at top level
        if (zeroY < 1) {
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX + 1][zeroY]) + "-u");
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX][zeroY + 1]) + "-l");


        } else if (zeroY > 1) {

            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX + 1][zeroY]) + "-u");
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX][zeroY - 1]) + "-r");


        } else {
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX + 1][zeroY]) + "-u");
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX][zeroY - 1]) + "-r");
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX][zeroY + 1]) + "-l");


        }
    } else if (zeroX > 1) { //x is at botton level
        if (zeroY < 1) {
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX - 1][zeroY]) + "-d");
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX][zeroY + 1]) + "-l");


        } else if (zeroY > 1) {
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX - 1][zeroY]) + "-d");
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX][zeroY - 1]) + "-r");


        } else {
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX - 1][zeroY]) + "-d");
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX][zeroY - 1]) + "-r");
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX][zeroY + 1]) + "-l");


        }

    } else { //x is at middle level

        if (zeroY < 1) {

            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX - 1][zeroY]) + "-d");
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX + 1][zeroY]) + "-u");
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX][zeroY + 1]) + "-l");


        } else if (zeroY > 1) {

            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX - 1][zeroY]) + "-d");
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX + 1][zeroY]) + "-u");
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX][zeroY - 1]) + "-r");


        } else {
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX - 1][zeroY]) + "-d");
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX + 1][zeroY]) + "-u");
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX][zeroY + 1]) + "-l");
            adjacentCoordinates.push_back(to_string(puzzleBoard[zeroX][zeroY - 1]) + "-r");

        }

    }

    return adjacentCoordinates;

}

/**
 * This function makes a single computer move
 */
void baris2::EightPuzzle::playAuto(){

    if(!endGame()){
        vector<string> moveList=availableMoves();
        shuffle(moveList.begin(), moveList.end(), std::mt19937(std::random_device()())); //It shuffles move commands in the direction list
        playUser(moveList[0]);
        cout<<"Computer move: "<<moveList[0]<<endl;
    }
    else
        cout<<"Computer can't make a move because game is over"<<endl;

}

/**
 * This functions prints 8 Puzzle Board into given ostream object
 * @param os
 */
void baris2::EightPuzzle::print(ostream &os) const {
    os<<"\n";
    for(const auto &line: puzzleBoard){
        for(const auto &number:line)
            if(number!=0)
                os<<"|"<<number<<"\t";
            else
                os<<"|X\t";
        os<<"\n--\t--\t--\n\n";
    }
    //os<<"hello im am here from eight class";
}

/**
 * This functions retuns score of the game according to inversions
 * @return
 */
int baris2::EightPuzzle::boardScore() const {
    vector<int> numbers;
    int inversions=0;
    for(const auto &line:puzzleBoard)
        for(const auto& number:line)
            numbers.push_back(number);

    for(int i=0;i<numbers.size()-1;i++)
        for(int j=i+1;j<numbers.size();j++)
            if(numbers[i]>numbers[j] && numbers[j]!=0)
                inversions++;

    return inversions;

}

/**
 * This function initializes 8 Puzzle Board every time randomly
 * It shuffles 1D vector until it creates a solveble 8 Puzzle Board
 * It uses random.h library in c++
 */
void baris2::EightPuzzle::initialize() {
    vector<int> tempVector;
    for(int i=0;i<9;i++)
        tempVector.push_back(i);

    shuffle(tempVector.begin(), tempVector.end(), std::mt19937(std::random_device()())); //It shuffles numbers directions in the direction list
    while(!isSolvable(tempVector))
        shuffle(tempVector.begin(), tempVector.end(), std::mt19937(std::random_device()())); //It shuffles numbers directions in the direction list


    vector<int> line0;
    vector<int> line1;
    vector<int> line2;

    for(int i=0;i<3;i++)
        line0.push_back(tempVector[i]);
    for(int i=3;i<6;i++)
        line1.push_back(tempVector[i]);
    for(int i=6;i<9;i++)
        line2.push_back(tempVector[i]);

    this->puzzleBoard={line0,line1,line2};
    cout<<"Eight Puzzle Initialized"<<endl<<*this<<endl;
    cout<<"********************"<<endl;

}








