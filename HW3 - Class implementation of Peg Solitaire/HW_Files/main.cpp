#include <iostream>
#include "PegSolitaire.h"

using namespace std;

int main() {
    srand(unsigned(time(0)));

    /*PegSolitaire p1(6);
    p1.showBoard();
    cout<<endl<<endl;

    cout<<p1.isLegalBoard6("b4-u")<<endl;*/


    /*vector<vector<PegSolitaire::Cell>> myVector=p1.textToVectors("board1.txt");*/
    /*for(int i=0;i<myVector.size();i++)
        for(int j=0;j<myVector[0].size();j++)
            cout<<myVector[i][j].getX()<<","<<myVector[i][j].getX()<<","<<myVector[i][j].getCellState()<<endl;

    vector<vector<int>> coordinates=p1.returnPegCoordinates(p1.getCurrentBoard());
    for(auto v: coordinates)
        cout<<v[0]<<"," <<v[1]<< endl;*/



    /*cout<< p1.isLegal("b4-r")<<endl;
    p1.movePegPerson("d2-d");
    p1.showBoard();
    p1.movePegPerson("d5-u");
    p1.showBoard();

    cout<<endl<<endl;
    cout<<p1.numberOfPegs()<<"\t"<<p1.numberOfEmpty()<<endl;

    cout<<endl<<endl;
    p1.movePegComputer();
    p1.showBoard();
    p1.movePegComputer();
    p1.showBoard();
    p1.movePegComputer();
    p1.showBoard();
    p1.movePegComputer();
    p1.showBoard();*/

    int userInput, pegNumber,personMove,computerMove;
    bool isDiagonal;
    vector<int>stats; //stats vector in main loop
    vector<vector<cell>> copyBoard; //copy board for main loop
    string userCommand,fileName;

    PegSolitaire defaultBoard;

    while (true) {
        cout << "****************************" << endl;
        cout << "********************" << endl;
        cout << "********" << endl;
        cout << "Welcome to the Peg Solitaire Game\n\n" << endl;

        cout << "Enter 1 to choose Board 1" << endl;
        cout << "Enter 2 to choose Board 2" << endl;
        cout << "Enter 3 to choose Board 3" << endl;
        cout << "Enter 4 to choose Board 4" << endl;
        cout << "Enter 5 to choose Board 5" << endl;
        cout << "Enter 6 to choose Board 6" << endl;
        cout << "Enter 7 to load a Board from a Saved File" << endl;
        cout << "Enter 8 to load a Board from a Load File (Arbitrary Boards)" << endl;
        cout<<"Enter 9 to see how many total pegs stand for all active games"<<endl;
        cout<<"Enter 10 to compare peg numbers of Board 1 and Board 3"<<endl;
        cout << "Enter -1 to exit" << endl;
        cin >> userInput;

        switch (userInput) {
            case 1:
            {
                PegSolitaire p1(1);
                p1.playMenu();
            }
                break;
            case 2:
            {
                PegSolitaire p2(2);
                p2.playMenu();
            }
                break;
            case 3:
            {
                PegSolitaire p3(3);
                p3.playMenu();
            }
                break;
            case 4:
            {
                PegSolitaire p4(4);
                p4.playMenu();
            }
                break;
            case 5:
            {
                PegSolitaire p5(5);
                p5.playMenu();
            }
                break;
            case 6:
            {
                PegSolitaire p6(6, true);
                p6.playMenu(0,0, true); //isDiagonal is true for this time
            }
                break;
            case 7:
            {
                PegSolitaire pSaved;
                pSaved.showFiles();
                cout<<"Please enter the name of the saved file that you want to continue"<<endl;
                cin>>fileName;
                pSaved.setFileName(fileName);
                pSaved.readFile(fileName);//copying board from txt file
                stats=pSaved.getStats(fileName); //getting stats from txt file
                isDiagonal=(bool)stats[0];
                pSaved.setIsDiagonal(isDiagonal);
                personMove=stats[1];
                computerMove=stats[2];
                cout<<personMove<<" "<<computerMove<<endl;
                //showBoard(copyBoard);
                pSaved.playMenu(personMove,computerMove,isDiagonal);
            }
                break;
            case 8:
            {
                defaultBoard.showFiles();
                cout<<"Please enter the name of the txt Load File that you want to play"<<endl;
                cin>>fileName;
                PegSolitaire pLoad(fileName);
                //pLoad.setFileName(fileName);
                //pLoad.readFile(fileName);
                //stats=pLoad.getStats(fileName);//getting stats from txt file
                //isDiagonal=(bool)stats[0];
                //pLoad.setIsDiagonal(isDiagonal);
                //cout<<personMove<<" "<<computerMove<<endl;
                //showBoard(copyBoard);
                pLoad.playMenu(0,0);
            }
                break;
            case 9:
            {
                cout<<"There are "<<defaultBoard.totalActivePegs()<<" pegs in active games"<<endl;
            }
                break;
            case 10:
            {
                PegSolitaire p11(1);
                PegSolitaire p33(3);
                cout<<"Board 1 has "<<p11.numberOfPegs(p11.getCurrentBoard())<<" pegs"<<endl
                <<"Board 3 has "<<p33.numberOfPegs(p33.getCurrentBoard())<<" pegs"<<endl;
                cout<<"Statement: Board 1 has more pegs than Board 3.\t"<<boolalpha<<
                "Result: "<<p11.hasMore(p33)<<endl;
                cout<<"Statement: Board 3 has more pegs than Board 1.\t"<<boolalpha<<
                    "Result: "<<p33.hasMore(p11)<<endl;
            }
                break;
            default:
                if(userInput!=-1)
                    cerr <<userInput<<" is a wrong command" << endl; //Error message for wrong inputs
        }
        if (userInput == -1)
            break; //Break the loop if input is -1
    }


    return 0;
}
