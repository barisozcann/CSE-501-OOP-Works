#include <iostream>
#include <string>
#include <vector>
#include<bits/stdc++.h> //This library is necessary for shuffling a vector
#include <algorithm> //This library is necessary for shuffling a vector


using namespace std;

enum class cell{Empty=0,Peg=1,nonUsed=2}; //This is strong enum type of cell representation
enum class column{A=0,B=1,C=2,D=3,E=4,F=5,G=6,H=7,I=8,W=-1}; ////This is strong enum type of column representation


/**
This function converts a string to a column (Strong enum type)
*/
column stringToColumns(string inputColumn){
    if(inputColumn=="a")
        return column::A;
    else if(inputColumn=="b")
        return column::B;
    else if(inputColumn=="c")
        return column::C;
    else if(inputColumn=="d")
        return column::D;
    else if(inputColumn=="e")
        return column::E;
    else if(inputColumn=="f")
        return column::F;
    else if(inputColumn=="g")
        return column::G;
    else if(inputColumn=="h")
        return column::H;
    else if(inputColumn=="i")
        return column::I;
    else{
        //cout<<"Invalid Column Name!"<<endl;
        return column::W; //Wrong column =-1
    }

}



vector<string> columnsNames={"a ","b ","c ","d ","e ","f ","g ", "h ", "i "}; //These are the string vector of all columns


/**
This function takes 2 inputs
First input is 2d vector
Second input is type of the Board(1,2,3,4,5,6)
It prints a given Board by nested for loops
*/
void showBoard(vector<vector<cell>> inputBoard, int boardType){
    int rowNumber=1;

    if(boardType==1){
        cout<<"\t";

        for(int i=0;i<7;i++){
            cout<<columnsNames[i];
        }
        cout<<endl;

        for(vector<vector<cell>>::iterator iter1=inputBoard.begin(); iter1!=inputBoard.end();++iter1){ //Iterator1
            cout<<rowNumber<<"\t";
            rowNumber++;

            for(vector<cell>::iterator iter2=iter1->begin(); iter2!=iter1->end();++iter2){ //Iterator2
                if(*iter2==cell::Peg)
                    cout<<"P";
                else if(*iter2==cell::Empty)
                    cout<<".";
                else if(*iter2==cell::nonUsed)
                    cout<<" ";
                else
                    continue;
                cout<<" ";
            }
            cout<<endl;
        }

    }
    else if(boardType==2){
        cout<<"\t";
        for(int i=0;i<9;i++){
            cout<<columnsNames[i];
        }
        cout<<endl;

        for(vector<vector<cell>>::iterator iter1=inputBoard.begin(); iter1!=inputBoard.end();++iter1){ //Iterator1
            cout<<rowNumber<<"\t";
            rowNumber++;
            for(vector<cell>::iterator iter2=iter1->begin(); iter2!=iter1->end();++iter2){ //Iterator 2
                if(*iter2==cell::Peg)
                    cout<<"P";
                else if(*iter2==cell::Empty)
                    cout<<".";
                else if(*iter2==cell::nonUsed)
                    cout<<" ";
                else
                    continue;
                cout<<" ";
            }
            cout<<endl;
        }

    }
    else if(boardType==3){
        cout<<"\t";

        for(int i=0;i<8;i++){
            cout<<columnsNames[i];
        }

        cout<<endl;

        for(vector<vector<cell>>::iterator iter1=inputBoard.begin(); iter1!=inputBoard.end();++iter1){ //Iterator1
            cout<<rowNumber<<"\t";
            rowNumber++;
            for(vector<cell>::iterator iter2=iter1->begin(); iter2!=iter1->end();++iter2){ //Iterator2
                if(*iter2==cell::Peg)
                    cout<<"P";
                else if(*iter2==cell::Empty)
                    cout<<".";
                else if(*iter2==cell::nonUsed)
                    cout<<" ";
                else
                    continue;
                cout<<" ";
            }
            cout<<endl;
        }

    }
    else if(boardType==4){
        cout<<"\t";
        for(int i=0;i<7;i++){
            cout<<columnsNames[i];
        }
        cout<<endl;

        for(vector<vector<cell>>::iterator iter1=inputBoard.begin(); iter1!=inputBoard.end();++iter1){ //Iterator1
            cout<<rowNumber<<"\t";
            rowNumber++;
            for(vector<cell>::iterator iter2=iter1->begin(); iter2!=iter1->end();++iter2){ //Iterator2
                if(*iter2==cell::Peg)
                    cout<<"P";
                else if(*iter2==cell::Empty)
                    cout<<".";
                else if(*iter2==cell::nonUsed)
                    cout<<" ";
                else
                    continue;
                cout<<" ";
            }
            cout<<endl;
        }
    }
    else if(boardType==5){
        cout<<"\t";
        for(int i=0;i<9;i++){
            cout<<columnsNames[i];
        }
        cout<<endl;

        for(vector<vector<cell>>::iterator iter1=inputBoard.begin(); iter1!=inputBoard.end();++iter1){ //Iterator1
            cout<<rowNumber<<"\t";
            rowNumber++;
            for(vector<cell>::iterator iter2=iter1->begin(); iter2!=iter1->end();++iter2){ //Iterator2
                if(*iter2==cell::Peg)
                    cout<<"P";
                else if(*iter2==cell::Empty)
                    cout<<".";
                else if(*iter2==cell::nonUsed)
                    cout<<" ";
                else
                    continue;
                cout<<" ";
            }
            cout<<endl;
        }
    }
    else if(boardType==6){
        cout<<"\t    ";
        for(int i=0;i<5;i++){
            cout<<columnsNames[i];
        }
        cout<<endl;

        for(vector<vector<cell>>::iterator iter1=inputBoard.begin(); iter1!=inputBoard.end();++iter1){ //Iterator1
            cout<<rowNumber<<"\t";
            rowNumber++;
            for(vector<cell>::iterator iter2=iter1->begin(); iter2!=iter1->end();++iter2){ //Iterator2
                if(*iter2==cell::Peg)
                    cout<<"P";
                else if(*iter2==cell::Empty)
                    cout<<".";
                else if(*iter2==cell::nonUsed)
                    cout<<" ";
                else
                    continue;
                cout<<" ";
            }
            cout<<endl;
        }
        cout<<"\n\t      a\n\t     a b\n\t    a b c\n\t   a b c d\n\t  a b c d e    <-- These are the columns in Board6\n"<<endl;
    }
    else
        cout<<"There is no "<<boardType<<". Type of board in this game!"<<endl;
}




/**
This function checks whether the given command is legal for Board1,2,3,4,5
First Input is 2d Vector
Second input is string command
It returns true if the given command is legal
*/
bool isLegal(vector<vector<cell>> inputBoard, string moveCommand){
    transform(moveCommand.begin(), moveCommand.end(), moveCommand.begin(), ::tolower); //It converts given string to lowercase
    string inputSourceRow,inputSourceColumn,moveDirection;
    inputSourceColumn=moveCommand[0];
    inputSourceRow=moveCommand[1];

    moveDirection=moveCommand[3];

    int sourceRow=stoi(inputSourceRow); //It converts string row to integer type
    sourceRow--; //Because rows are starting with 1 not zero

    int sourceColumn=static_cast<int>(stringToColumns(inputSourceColumn)); //First it converts string to enum column. Then it casts integer type.


    if(moveDirection=="u"){ //"u" is stand for up command
        if(sourceRow<2) //It returns false to prevent segmentation fault
            return false;

        cell sourceCell=inputBoard[sourceRow][sourceColumn]; //source cell
        cell middleCell=inputBoard[sourceRow-1][sourceColumn]; //middle cell between source and target
        cell targetCell=inputBoard[sourceRow-2][sourceColumn]; //target cell (upwards)

        if(sourceCell==cell::Peg && middleCell==cell::Peg && targetCell==cell::Empty)
            return true;
        else
            return false;

    }
    else if(moveDirection=="d"){ //"d" is stand for down command
        if(sourceRow>=inputBoard.size()-2) //It returns false to prevent segmentation fault
            return false;

        cell sourceCell=inputBoard[sourceRow][sourceColumn]; //source cell
        cell middleCell=inputBoard[sourceRow+1][sourceColumn]; //middle cell between source and target
        cell targetCell=inputBoard[sourceRow+2][sourceColumn]; //target cell (downwards)

        if(sourceCell==cell::Peg && middleCell==cell::Peg && targetCell==cell::Empty)
            return true;
        else
            return false;

    }

    else if(moveDirection=="l"){ //"l" is stand for left command
        if(sourceColumn<2) //It returns false to prevent segmentation fault
            return false;
        cell sourceCell=inputBoard[sourceRow][sourceColumn]; //source cell
        cell middleCell=inputBoard[sourceRow][sourceColumn-1]; //middle cell between source and target
        cell targetCell=inputBoard[sourceRow][sourceColumn-2]; //target cell (leftwards)

        if(sourceCell==cell::Peg && middleCell==cell::Peg && targetCell==cell::Empty)
            return true;
        else
            return false;


    }

    else if(moveDirection=="r"){ //"r" is stand for right command
        if(sourceColumn>=inputBoard[0].size()-2) //It returns false to prevent segmentation fault
            return false;

        cell sourceCell=inputBoard[sourceRow][sourceColumn]; //source cell
        cell middleCell=inputBoard[sourceRow][sourceColumn+1]; //middle cell between source and target
        cell targetCell=inputBoard[sourceRow][sourceColumn+2]; //target cell (reftwards)

        if(sourceCell==cell::Peg && middleCell==cell::Peg && targetCell==cell::Empty)
            return true;
        else
            return false;

    }

    else
        return false;

}

/**
This is move function of person inputs for Board1,2,3,4,5
First Input is 2d Vector Reference
Second input is string command
It makes a move if the given command is legal
*/

void movePegPerson(vector<vector<cell>> &inputBoard, string moveCommand){

    if(isLegal(inputBoard,moveCommand)){ //It check is the given command is legal
    string inputSourceRow,inputSourceColumn,moveDirection;
    transform(moveCommand.begin(), moveCommand.end(), moveCommand.begin(), ::tolower); //It converts given string to lowercase

    inputSourceColumn=moveCommand[0];
    inputSourceRow=moveCommand[1];

    moveDirection=moveCommand[3];

    int sourceRow=stoi(inputSourceRow); //It converts string row to integer type
    sourceRow--; //Because rows are starting with 1 not zero

    int sourceColumn=static_cast<int>(stringToColumns(inputSourceColumn)); //First it converts string to enum column. Then it casts integer type.

    inputBoard[sourceRow][sourceColumn]=cell::Empty; //It makes the source cell empty

    if(moveDirection=="u"){
        inputBoard[sourceRow-1][sourceColumn]=cell::Empty; //makes middle cell empty
        inputBoard[sourceRow-2][sourceColumn]=cell::Peg; //makes target cell peg
    }
    else if(moveDirection=="d"){
        inputBoard[sourceRow+1][sourceColumn]=cell::Empty; //makes middle cell empty
        inputBoard[sourceRow+2][sourceColumn]=cell::Peg; //makes target cell peg
    }

    else if(moveDirection=="l"){
        inputBoard[sourceRow][sourceColumn-1]=cell::Empty; //makes middle cell empty
        inputBoard[sourceRow][sourceColumn-2]=cell::Peg; //makes target cell peg
    }

    else if(moveDirection=="r"){
        inputBoard[sourceRow][sourceColumn+1]=cell::Empty; //makes middle cell empty
        inputBoard[sourceRow][sourceColumn+2]=cell::Peg; //makes target cell peg
    }

    }
    else
        cout<<moveCommand<<" is illegal move!"<<endl; //Warning for illegal moves


}

/**
This returns number of pegs of given Board
Input is a constant 2d Vector reference
*/
int numberOfPegs(const vector<vector<cell>> &inputBoard){
    int pegCounter=0;
    for(vector<cell> innerVector: inputBoard) //Nested ranged for loops
        for(cell c: innerVector)
            if(c==cell::Peg)
                pegCounter++;
    return pegCounter;
}

/**
It returns a given integer to string column name
Input is an integer
*/

string numberToColumnName(int inputColumn){
    if(inputColumn==0)
        return "a";
    else if(inputColumn==1)
        return "b";
    else if(inputColumn==2)
        return "c";
    else if(inputColumn==3)
        return "d";
    else if(inputColumn==4)
        return "e";
    else if(inputColumn==5)
        return "f";
    else if(inputColumn==6)
        return "g";
    else if(inputColumn==7)
        return "h";
    else if(inputColumn==8)
        return "i";
    else
        return "-1";

}

/**
This functions is nearly same as movePegPerson.
Only difference is, it doesn't warn for illegal moves because computer needs to try so many illegal moves to find a legal move
This function is for Board1,2,3,4,5
First Input is 2d Vector Reference
Second input is string command
*/
void movePegComputerHelper(vector<vector<cell>> &inputBoard, string moveCommand){

    string inputSourceRow,inputSourceColumn,moveDirection;
    transform(moveCommand.begin(), moveCommand.end(), moveCommand.begin(), ::tolower);

    inputSourceColumn=moveCommand[0];
    inputSourceRow=moveCommand[1];

    moveDirection=moveCommand[3];

    int sourceRow=stoi(inputSourceRow);
    sourceRow--; //Because rows are starting with 1 not zero

    int sourceColumn=static_cast<int>(stringToColumns(inputSourceColumn));

    inputBoard[sourceRow][sourceColumn]=cell::Empty;

    if(moveDirection=="u"){
        inputBoard[sourceRow-1][sourceColumn]=cell::Empty;
        inputBoard[sourceRow-2][sourceColumn]=cell::Peg;
    }
    else if(moveDirection=="d"){
        inputBoard[sourceRow+1][sourceColumn]=cell::Empty;
        inputBoard[sourceRow+2][sourceColumn]=cell::Peg;
    }

    else if(moveDirection=="l"){
        inputBoard[sourceRow][sourceColumn-1]=cell::Empty;
        inputBoard[sourceRow][sourceColumn-2]=cell::Peg;
    }

    else if(moveDirection=="r"){
        inputBoard[sourceRow][sourceColumn+1]=cell::Empty;
        inputBoard[sourceRow][sourceColumn+2]=cell::Peg;
    }




}


/**
This function is for Board1,2,3,4,5
This functions iterates throughs a given Board and returns number of pegs
Input is a 2d Vector
*/
vector<vector<int>> returnPegCoordinates(vector<vector<cell>> inputBoard){

    vector<vector<int>> pegCoordinateList; //2d vector that collects the list of peg coordinates
    vector<int> pegCoordinates; //1d vector that collects a given peg coordinate

    for (int i = 0; i < inputBoard.size(); i++){ //Nested for loop
        for (int j = 0; j < inputBoard[i].size(); j++)
        {
            if(inputBoard[i][j]==cell::Peg){

                pegCoordinates.push_back(i); //Collecting the row information of a peg cell
                pegCoordinates.push_back(j); //Collecting the column information of a peg cell

                pegCoordinateList.push_back(pegCoordinates); //Collect 1d vector in a 2d vector to collect pairs
                pegCoordinates.clear(); //Clear 1d vector after saving
            }

        }
    }
    return pegCoordinateList;

}

/**
This function works for Board1,2,3,4,5
Input is a 2d Vector reference
It takes a Board and tries to make a random computer move
It can't make any move if the game is over
It shuffles all peg coordinates and takes the last peg in the vector to make a move every time.
*/

void movePegComputer(vector<vector<cell>> &inputBoard){

    vector<vector<int>> pegCoordinateList; //2d vector for Peg Coordinates
    vector<int> pegCoordinates; //1d vector contains only 1 peg's coordinate
    pegCoordinateList=returnPegCoordinates(inputBoard);

    random_shuffle (pegCoordinateList.begin(), pegCoordinateList.end()); //It shuffles all vectors' coordinates for randomization

    int column,row;
    string columnName,rowName,moveCommand;
    vector<string> directions={"l","r","u","d"}; //String list of directions
    int counter=0;

    while(true){
        if(counter!=0 || pegCoordinateList.empty()) //It stops the loop if it makes a move or coordinate list becomes empty
            break;
        pegCoordinates=pegCoordinateList.back(); //turns last element in peg coordinate list
        pegCoordinateList.pop_back(); //pops the last element in peg coordinate list

        column=pegCoordinates[1]; //column of a random peg
        row=pegCoordinates[0]+1; //Row of a random peg. Adding +1 because rows begin at 1 not 0.
        //cout<<row<<"**"<<column<<endl;
        rowName=to_string(row); //converts integer row to string type
        columnName=numberToColumnName(column); //converts integer column information to string column name
        random_shuffle (directions.begin(), directions.end()); //It shuffles all directions in the direction list
        for(int i=0;i<directions.size();i++){
            moveCommand=columnName+rowName+"-"+directions[i]; //It builds a command for given random peg and adds a random direction
            //cout<<moveCommand<<"*******"<<endl;
            if(isLegal(inputBoard,moveCommand)){ //If the command is legal, It moves the peg
                movePegComputerHelper(inputBoard,moveCommand); //It calls helper method to make a move
                cout<<"Computer move: "<<moveCommand<<endl<<endl; //prints out the computer move
                counter++;
                break;
            }
        }

    }
    if(counter==0) //Warns user that game is over if computer can't make any move
        cout<<"Computer can't make any move because game is over!!"<<endl;

}


/**
This function works for Board1,2,3,4,5
This function is nearly the same as movePegComputer function.
Only difference is, it doesn't make move instead returns true if any move is able in the game
It takes 2d Vector as input
*/
bool isOver(vector<vector<cell>> inputBoard){

    vector<vector<int>> pegCoordinateList;
    vector<int> pegCoordinates;

    int column,row;
    string columnName,rowName,moveCommand;
    vector<string> directions={"l","r","u","d"};
    int counter=0;
    pegCoordinateList=returnPegCoordinates(inputBoard);
    random_shuffle ( pegCoordinateList.begin(), pegCoordinateList.end());
    while(true){
        if(counter!=0 || pegCoordinateList.empty())
            break;
        pegCoordinates=pegCoordinateList.back();
        pegCoordinateList.pop_back();

        column=pegCoordinates[1];
        row=pegCoordinates[0]+1; //Adding +1 because rows begin at 1 not 0
        //cout<<row<<"**"<<column<<endl;
        rowName=to_string(row);
        columnName=numberToColumnName(column);
        random_shuffle (directions.begin(), directions.end());
        for(int i=0;i<directions.size();i++){
            moveCommand=columnName+rowName+"-"+directions[i];
            //cout<<moveCommand<<"*******"<<endl;
            if(isLegal(inputBoard,moveCommand)){
                return false;
                counter++;
                break;
            }
        }

    }
    if(counter==0)
        return true;

}


/**
This function returns columns names with respect to their rows.
In Board6, every row stars with A for first peg in that specific column
This function takes 2d vector, sourceRow and source column as input
So in converts the given column to real column for the specific row by counting pegs
For ex: to reach 3rd column in a row, function must count 3 pegs in that column
*/

int relativeToRealColumnBoard6(vector<vector<cell>> inputBoard, int sourceRow, int sourceColumnRelative){
    sourceColumnRelative++; //Incrementing because first column stars with 1 peg not zero peg
    int pegColumnCounter=0;
    int sourceColumn;
    for(int i=0;i<inputBoard[sourceRow].size();i++){
        if(inputBoard[sourceRow][i]==cell::Peg)
            pegColumnCounter++; //Increment counter for every peg in given column
        if(pegColumnCounter==sourceColumnRelative){ //Stop if counted pegs are equal to given column
            sourceColumn=i;
            break;
        }
    }
    return sourceColumn; //return real column value of specific row in Board6
}


/**
This method is for Board6
It takes 2d vector, integer row and integer column as inputs
It returns string column name for specific row in Board6
*/
string numberToColumnName6(vector<vector<cell>> inputBoard,int row,int inputColumn){
    int pegColumnCounter=0;
    for(int i=0;i<=inputColumn;i++){ //Stops counting when it reaches the given column
        if(inputBoard[row][i]==cell::Peg)
            pegColumnCounter++; //Increment counter for each peg
        }
    if(pegColumnCounter==1)
        return "a";
    else if(pegColumnCounter==2)
        return "b";
    else if(pegColumnCounter==3)
        return "c";
    else if(pegColumnCounter==4)
        return "d";
    else if(pegColumnCounter==5)
        return "e";
    else
        return "-1";

}



/**
This method is for Board6
It takes 2d vector, string command as input
For Board6, there are default empty cells for true representation
For ex: For moving left, the peg should go to 4 columns left but we see this as 2 columns lefter change in Board6
For ex: For moving up, The peg should go to 2 columns up and 2 columns left or right but we see this as 2 columns upper change in Board6
*/


bool isLegalBoard6(vector<vector<cell>> inputBoard, string moveCommand){
    transform(moveCommand.begin(), moveCommand.end(), moveCommand.begin(), ::tolower); //Converts string command to lowercase
    string inputSourceRow,inputSourceColumn,moveDirection;
    inputSourceColumn=moveCommand[0];
    inputSourceRow=moveCommand[1];
    moveDirection=moveCommand[3];

    int sourceRow=stoi(inputSourceRow);
    sourceRow--; //Because rows are starting with 1 not zero

    int sourceColumnRelative=static_cast<int>(stringToColumns(inputSourceColumn)); //This  location is relative for every row.
    int sourceColumn=relativeToRealColumnBoard6(inputBoard,sourceRow,sourceColumnRelative); //It converts relative column to real column in the Board6


    if(moveDirection=="u"){
        if(sourceRow<2) //This if state prevents segmantation fault
            return false;
        cell sourceCell;
        cell middleCell;
        cell middleCell2;
        cell targetCell;
        cell targetCell2;
        if(sourceColumn<=2){//Peg can't go left in this situation
            sourceCell=inputBoard[sourceRow][sourceColumn];
            middleCell=inputBoard[sourceRow-1][sourceColumn+1];
            targetCell=inputBoard[sourceRow-2][sourceColumn+2]; //Goes to right direction
        }

        else if(inputBoard[0].size()-sourceColumn<=2){ //Peg can't go right in this situation
            sourceCell=inputBoard[sourceRow][sourceColumn];
            middleCell=inputBoard[sourceRow-1][sourceColumn-1];
            targetCell=inputBoard[sourceRow-2][sourceColumn-2]; //Goes to upper left direction
        }
        else{ //If there is no left or right resctriction for the cell, It tries to go both direction in order.
            sourceCell=inputBoard[sourceRow][sourceColumn];
            middleCell=inputBoard[sourceRow-1][sourceColumn-1]; //Middle of Left
            middleCell2=inputBoard[sourceRow-1][sourceColumn+1]; // Middle of Right
            targetCell=inputBoard[sourceRow-2][sourceColumn-2]; //Target of Left
            targetCell2=inputBoard[sourceRow-2][sourceColumn+2]; //Target of Right

            if(sourceCell==cell::Peg && middleCell==cell::Peg && targetCell==cell::Empty) //It first tries to check upper right
                return true;
            else if(sourceCell==cell::Peg && middleCell2==cell::Peg && targetCell2==cell::Empty) //Then it tries to check upper right
                return true;
            else //Peg can't go anywhere towards upper direction
                return false;
        }

        if(sourceCell==cell::Peg && middleCell==cell::Peg && targetCell==cell::Empty)
            return true;
        else
            return false;

    }
    else if(moveDirection=="d"){
        if(sourceRow>=inputBoard.size()-2) //This if state prevents segmantation fault
            return false;

        cell sourceCell;
        cell middleCell;
        cell middleCell2;
        cell targetCell;
        cell targetCell2;
        if(sourceColumn<=2){//Peg can't go left in this situation. It can go to only right direction
            sourceCell=inputBoard[sourceRow][sourceColumn];
            middleCell=inputBoard[sourceRow+1][sourceColumn+1];
            targetCell=inputBoard[sourceRow+2][sourceColumn+2];
        }

        else if(inputBoard[0].size()-sourceColumn<=2){ //Peg can't go right in this situation. It can go to only left direction.
            sourceCell=inputBoard[sourceRow][sourceColumn];
            middleCell=inputBoard[sourceRow+1][sourceColumn-1];
            targetCell=inputBoard[sourceRow+2][sourceColumn-2];
        }
        else{ //If there is no left or right resctriction for the cell, It tries to go both direction in order.
            sourceCell=inputBoard[sourceRow][sourceColumn];
            middleCell=inputBoard[sourceRow+1][sourceColumn-1]; //Middle of Left
            middleCell2=inputBoard[sourceRow+1][sourceColumn+1]; // Middle of Right
            targetCell=inputBoard[sourceRow+2][sourceColumn-2]; //Target of Left
            targetCell2=inputBoard[sourceRow+2][sourceColumn+2]; //Target of Right

            if(sourceCell==cell::Peg && middleCell==cell::Peg && targetCell==cell::Empty) //It first tries to check upper right
                return true;
            else if(sourceCell==cell::Peg && middleCell2==cell::Peg && targetCell2==cell::Empty) //Then it tries to check upper right
                return true;
            else //Peg can't go anywhere towards downer direction
                return false;
        }

        if(sourceCell==cell::Peg && middleCell==cell::Peg && targetCell==cell::Empty)
            return true;
        else
            return false;

    }

    else if(moveDirection=="l"){
        if(sourceColumn<4) //This if state prevents segmantation fault
            return false;

        cell sourceCell=inputBoard[sourceRow][sourceColumn]; //source cell
        cell middleCell=inputBoard[sourceRow][sourceColumn-2]; //middle cell
        cell targetCell=inputBoard[sourceRow][sourceColumn-4]; //target cell

        if(sourceCell==cell::Peg && middleCell==cell::Peg && targetCell==cell::Empty)
            return true;
        else
            return false;


    }

    else if(moveDirection=="r"){
        if(sourceColumn>=inputBoard[0].size()-4) //This if state prevents segmantation fault
            return false;

        cell sourceCell=inputBoard[sourceRow][sourceColumn]; //source cell
        cell middleCell=inputBoard[sourceRow][sourceColumn+1]; //middle cell
        cell targetCell=inputBoard[sourceRow][sourceColumn+2]; //target cell

        if(sourceCell==cell::Peg && middleCell==cell::Peg && targetCell==cell::Empty)
            return true;
        else
            return false;


    }

    else
        return false;

}



/**
This method is for Board6 to make move
It takes 2d vector reference and string command as input
For Board6, there are default empty cells for true representation
For ex: For moving left, the peg should go to 4 columns left but we see this as 2 columns lefter change in Board6
For ex: For moving up, The peg should go to 2 columns up and 2 columns left or right but we see this as 2 columns upper change in Board6
It makes moves if only the given command is legal
*/
void movePegPersonBoard6(vector<vector<cell>> &inputBoard, string moveCommand){

    if(isLegalBoard6(inputBoard,moveCommand)){ //It first check if the given command is legal
    transform(moveCommand.begin(), moveCommand.end(), moveCommand.begin(), ::tolower); //Converts given string command to lowercase
    string inputSourceRow,inputSourceColumn,moveDirection;
    inputSourceColumn=moveCommand[0];
    inputSourceRow=moveCommand[1];
    moveDirection=moveCommand[3];

    int sourceRow=stoi(inputSourceRow);
    sourceRow--; //Because rows are starting with 1 not zero

    int sourceColumnRelative=static_cast<int>(stringToColumns(inputSourceColumn)); //This location is relative for every row.
    int sourceColumn=relativeToRealColumnBoard6(inputBoard,sourceRow,sourceColumnRelative); //It converts relative column to real column in the Board6

    inputBoard[sourceRow][sourceColumn]=cell::Empty; //It makes the source cell empty first

    if(moveDirection=="u"){

        if(sourceColumn<=2){//Peg can't go left in this situation
            inputBoard[sourceRow-1][sourceColumn+1]=cell::Empty;
            inputBoard[sourceRow-2][sourceColumn+2]=cell::Peg;
        }

        else if(inputBoard[0].size()-sourceColumn<=2){ //Peg can't go right in this situation
            inputBoard[sourceRow-1][sourceColumn-1]=cell::Empty;
            inputBoard[sourceRow-2][sourceColumn-2]=cell::Peg;
        }
        else{
            cell middleCell=inputBoard[sourceRow-1][sourceColumn-1]; //Middle of Left
            cell targetCell=inputBoard[sourceRow-2][sourceColumn-2]; //Target of Left

            if(middleCell==cell::Peg && targetCell==cell::Empty){ //It tries to go upper left
                inputBoard[sourceRow-1][sourceColumn-1]=cell::Empty;
                inputBoard[sourceRow-2][sourceColumn-2]=cell::Peg;
            }

            else{ //Else it definitely goes up right direction
                inputBoard[sourceRow-1][sourceColumn+1]=cell::Empty;
                inputBoard[sourceRow-2][sourceColumn+2]=cell::Peg;
            }
        }
    }


    else if(moveDirection=="d"){
        if(sourceColumn<=2){//Peg can't go left in this situation
            inputBoard[sourceRow+1][sourceColumn+1]=cell::Empty;
            inputBoard[sourceRow+2][sourceColumn+2]=cell::Peg;
        }

        else if(inputBoard[0].size()-sourceColumn<=2){ //Peg can't go right in this situation
            inputBoard[sourceRow+1][sourceColumn-1]=cell::Empty;
            inputBoard[sourceRow+2][sourceColumn-2]=cell::Peg;
        }
        else{
            cell middleCell=inputBoard[sourceRow+1][sourceColumn-1]; //Middle of Left
            cell targetCell=inputBoard[sourceRow+1][sourceColumn-2]; //Target of Left

            if(middleCell==cell::Peg && targetCell==cell::Empty){ //It tries to go upper left
                inputBoard[sourceRow+1][sourceColumn-1]=cell::Empty;
                inputBoard[sourceRow+2][sourceColumn-2]=cell::Peg;
            }

            else { //Else it definitely go down-right direction
                inputBoard[sourceRow+1][sourceColumn+1]=cell::Empty;
                inputBoard[sourceRow+2][sourceColumn+2]=cell::Peg;
            }
        }
    }

    else if(moveDirection=="l"){ //left direction
        inputBoard[sourceRow][sourceColumn-2]=cell::Empty;
        inputBoard[sourceRow][sourceColumn-4]=cell::Peg;
    }

    else if(moveDirection=="r"){ //right direction
        inputBoard[sourceRow][sourceColumn+2]=cell::Empty;
        inputBoard[sourceRow][sourceColumn+4]=cell::Peg;
    }

    }
    else
        cout<<moveCommand<<" is illegal move!"<<endl; //Warning for illegal moves
}


/**
This function works for just Board6
Input is a 2d Vector reference
It takes a Board and tries to make a random computer move
It can't make any move if the game is over
It shuffles all peg coordinates and takes the last peg in the vector to make a move every time.
*/
void movePegComputer6(vector<vector<cell>> &inputBoard){
    vector<vector<int>> pegCoordinateList; //2d Peg coordinate list
    vector<int> pegCoordinates; //Peg coordinate vector

    int column,row;
    string columnName,rowName,moveCommand;
    vector<string> directions={"l","r","u","d"}; //String list of directions
    int counter=0;
    pegCoordinateList=returnPegCoordinates(inputBoard); //Takes peg coordinates in the board6 by the function
    random_shuffle ( pegCoordinateList.begin(), pegCoordinateList.end()); //It shuffles all coordinates of pegs in the board6
    while(true){
        if(counter!=0 || pegCoordinateList.empty()) //It stops if it makes a move or peg coordinate list becomes empty
            break;
        pegCoordinates=pegCoordinateList.back(); //It returns last peg coordinate in the vector
        pegCoordinateList.pop_back(); //It pop last peg coordinate in the vector


        row=pegCoordinates[0]+1; //Adding +1 because rows begin at 1 not 0
        column=pegCoordinates[1];

        rowName=to_string(row); //converts row name to string
        columnName=numberToColumnName6(inputBoard,row-1,column); //It returns the column name of given relative column in Board6

        random_shuffle ( directions.begin(), directions.end()); //It shuffles all directions everytime
        for(int i=0;i<directions.size();i++){
            moveCommand=columnName+rowName+"-"+directions[i];
            if(isLegalBoard6(inputBoard,moveCommand)){
                movePegPersonBoard6(inputBoard,moveCommand);
                cout<<"Computer move: "<<moveCommand<<endl<<endl; //Prints out the computer move
                counter++; //Increment counter for any computer move
                break;
            }
        }

    }
    if(counter==0)
        cout<<"Computer can't make any move because game is over!!"<<endl; //Warns the user if there is no available move in the Board6

}


/**
This function is almost the same as movePegComputer6.
Only difference is, it doesn't make any move, instead returns true if it detects any legal move available
*/
bool isOverBoard6(vector<vector<cell>> inputBoard){
    vector<vector<int>> pegCoordinateList;
    vector<int> pegCoordinates;

    int column,row;
    string columnName,rowName,moveCommand;
    vector<string> directions={"l","r","u","d"};
    int counter=0;
    pegCoordinateList=returnPegCoordinates(inputBoard);
    random_shuffle ( pegCoordinateList.begin(), pegCoordinateList.end());
    while(true){
        if(counter!=0 || pegCoordinateList.empty())
            break;
        pegCoordinates=pegCoordinateList.back();
        pegCoordinateList.pop_back();


        row=pegCoordinates[0]+1; //Adding +1 because rows begin at 1 not 0
        column=pegCoordinates[1];

        //cout<<row<<"**"<<relativeColumn<<endl;
        //cout<<row<<"***"<<column<<endl;

        rowName=to_string(row);
        columnName=numberToColumnName6(inputBoard,row-1,column);
        random_shuffle ( directions.begin(), directions.end());
        for(int i=0;i<directions.size();i++){
            moveCommand=columnName+rowName+"-"+directions[i];
            //cout<<moveCommand<<"*******"<<endl;
            if(isLegalBoard6(inputBoard,moveCommand)){
                return false;
                counter++;
                break;
            }
        }

    }
    if(counter==0)
        true;

}


/**
This function shows the score according to remainder pegs
*/
void showScore(int numberOfPegs){
cout<<"Your score is "<<1000-(numberOfPegs-1)*50<<" (Best Score is 1000)"<<endl;
}

int main()
{
   srand(unsigned(time(0))); //seed for random_shuffle function

   cell e,p,n; //Cell strong enums
   e=cell::Empty;
   p=cell::Peg;
   n=cell::nonUsed;


    /**
    Board1
    */
   vector<vector<cell>> board1={{n,n,p,p,p,n,n},
   {n,p,p,p,p,p,n},
   {p,p,p,e,p,p,p},
   {p,p,p,p,p,p,p},
   {n,p,p,p,p,p,n},
   {n,n,p,p,p,n,n}};


   /**
   Board2
   */
   vector<vector<cell>> board2={{n,n,n,p,p,p,n,n,n},
   {n,n,n,p,p,p,n,n,n},
   {n,n,n,p,p,p,n,n,n},
   {p,p,p,p,p,p,p,p,p},
   {p,p,p,p,e,p,p,p,p},
   {p,p,p,p,p,p,p,p,p},
   {n,n,n,p,p,p,n,n,n},
   {n,n,n,p,p,p,n,n,n},
   {n,n,n,p,p,p,n,n,n}};

   /**
   Board3
   */
   vector<vector<cell>> board3={{n,n,p,p,p,n,n,n},
   {n,n,p,p,p,n,n,n},
   {n,n,p,p,p,n,n,n},
   {p,p,p,p,p,p,p,p},
   {p,p,p,e,p,p,p,p},
   {p,p,p,p,p,p,p,p},
   {n,n,p,p,p,n,n,n},
   {n,n,p,p,p,n,n,n}};

   /**
   Board4
   */
   vector<vector<cell>> board4={{n,n,p,p,p,n,n},
   {n,n,p,p,p,n,n},
   {p,p,p,p,p,p,p},
   {p,p,p,e,p,p,p},
   {p,p,p,p,p,p,p},
   {n,n,p,p,p,n,n},
   {n,n,p,p,p,n,n}};

   /**
   Board5
   */
   vector<vector<cell>> board5={{n,n,n,n,p,n,n,n,n},
   {n,n,n,p,p,p,n,n,n},
   {n,n,p,p,p,p,p,n,n},
   {n,p,p,p,p,p,p,p,n},
   {p,p,p,p,e,p,p,p,p},
   {n,p,p,p,p,p,p,p,n},
   {n,n,p,p,p,p,p,n,n},
   {n,n,n,p,p,p,n,n,n},
   {n,n,n,n,p,n,n,n,n}};

   /**
   Board6
   */
   vector<vector<cell>> board6={{n,n,n,n,e,n,n,n,n},
   {n,n,n,p,n,p,n,n,n},
   {n,n,p,n,p,n,p,n,n},
   {n,p,n,p,n,p,n,p,n},
   {p,n,p,n,p,n,p,n,p}};




    int userInput,pegNumber;
    string userCommand;
    string moveMessage="Enter enter a command to make a move (ex:b4-r)\n";
    string exitMessage="Enter 0 (zero) to end the game\n";
    string computerMessage="Enter c to make computer a move\n";

    while(true){
        cout<<"****************************"<<endl;
        cout<<"********************"<<endl;
        cout<<"********"<<endl;
        cout<<"Welcome to the Peg Solitaire Game\n\n"<<endl;

        cout<<"Press 1 to choose Board 1"<<endl;
        cout<<"Press 2 to choose Board 2"<<endl;
        cout<<"Press 3 to choose Board 3"<<endl;
        cout<<"Press 4 to choose Board 4"<<endl;
        cout<<"Press 5 to choose Board 5"<<endl;
        cout<<"Press 6 to choose Board 6"<<endl;
        cin>>userInput;

        switch(userInput){
            case 1:
                while(true){
                    showBoard(board1,1);
                    cout<<moveMessage<<computerMessage<<exitMessage<<endl;
                    cin>>userCommand;
                    if(userCommand=="0" || isOver(board1)){
                        cout<<"You end the game with "<<numberOfPegs(board1)<<" Pegs"<<endl;
                        showScore(numberOfPegs(board1));
                        break;
                    }
                    else if(userCommand=="c")
                        movePegComputer(board1);
                    else if(userCommand.size()==4)
                        movePegPerson(board1,userCommand);
                    else
                        cout<<"Please enter a valid command!"<<endl;

                }
                break;
            case 2:
                while(true){
                    showBoard(board2,2);
                    cout<<moveMessage<<computerMessage<<exitMessage<<endl;
                    cin>>userCommand;
                    if(userCommand=="0" || isOver(board2)){
                        cout<<"You end the game with "<<numberOfPegs(board2)<<" Pegs"<<endl;
                        showScore(numberOfPegs(board2));
                        break;
                    }
                    else if(userCommand=="c")
                        movePegComputer(board2);
                    else if(userCommand.size()==4)
                        movePegPerson(board2,userCommand);
                    else
                        cout<<"Please enter a valid command!"<<endl;

                }
                break;

            case 3:
                while(true){
                    showBoard(board3,3);
                    cout<<moveMessage<<computerMessage<<exitMessage<<endl;
                    cin>>userCommand;
                    if(userCommand=="0" || isOver(board3)){
                        cout<<"You end the game with "<<numberOfPegs(board3)<<" Pegs"<<endl;
                        showScore(numberOfPegs(board3));
                        break;
                    }
                    else if(userCommand=="c")
                        movePegComputer(board3);
                    else if(userCommand.size()==4)
                        movePegPerson(board3,userCommand);
                    else
                        cout<<"Please enter a valid command!"<<endl;

                }
                break;
            case 4:
                while(true){
                    showBoard(board4,4);
                    cout<<moveMessage<<computerMessage<<exitMessage<<endl;
                    cin>>userCommand;
                    if(userCommand=="0" || isOver(board4)){
                        cout<<"You end the game with "<<numberOfPegs(board4)<<" Pegs"<<endl;
                        showScore(numberOfPegs(board4));
                        break;
                    }
                    else if(userCommand=="c")
                        movePegComputer(board4);
                    else if(userCommand.size()==4)
                        movePegPerson(board4,userCommand);
                    else
                        cout<<"Please enter a valid command!"<<endl;

                }
                break;

            case 5:
                while(true){
                    showBoard(board5,5);
                    cout<<moveMessage<<computerMessage<<exitMessage<<endl;
                    cin>>userCommand;
                    if(userCommand=="0" || isOver(board5)){
                        cout<<"You end the game with "<<numberOfPegs(board5)<<" Pegs"<<endl;
                        showScore(numberOfPegs(board5));
                        break;
                    }
                    else if(userCommand=="c")
                        movePegComputer(board5);
                    else if(userCommand.size()==4)
                        movePegPerson(board5,userCommand);
                    else
                        cout<<"Please enter a valid command!"<<endl;
                }
                break;

            case 6:
                while(true){
                    showBoard(board6,6);
                    cout<<moveMessage<<computerMessage<<exitMessage<<endl;
                    cin>>userCommand;
                    if(userCommand=="0" || isOverBoard6(board6)){
                        cout<<"You end the game with "<<numberOfPegs(board6)<<" Pegs"<<endl;
                        showScore(numberOfPegs(board6));
                        break;
                    }
                    else if(userCommand=="c")
                        movePegComputer6(board6);
                    else if(userCommand.size()==4)
                        movePegPersonBoard6(board6,userCommand);
                    else
                        cout<<"Please enter a valid command!"<<endl;
                }
                break;
            default:
                cout<<"There is no Board"<<userInput<<" In this game!"<<endl;

        }
        break;
    }
    return 0;
   }
