//
// Created by darkb on 12.12.2021.
//

#ifndef  CSE241_HW5_BOARDGAME2D_H
#define  CSE241_HW5_BOARDGAME2D_H

#include<iostream>
#include<string>
#include <vector>
#include <unistd.h>

using namespace std;


class BoardGame2D {

    //ostream overloading
    friend ostream &operator<<(ostream &os, const BoardGame2D &boardGame2D);

public:

    //Function to detect illegal moves
    virtual bool isLegal(string command) const=0;

    //This function makes a move by a string user command
    virtual void playUser(string command)=0;

    //This function retuns true if a game is ended
    virtual bool endGame() const=0;

    //This function plays a game until it ends
    virtual void playUser() final{
        string command=" ";
        cout<<*this<<endl;
        int move=0;
        while(!endGame() && command!="0"){
            cout<<"Please enter a valid command (PegSolitaire: b4-r \t Eight Puzzle:7-u):";
            cout<<"\nPress c to make one move computer one move\nPress f to let computer play until the end\n";
            cout<<"Press 0 to end the game\n";
            cin>>command;
            if(command=="c")
                playAuto();
            else if(command=="f")
                playAutoAll();
            else
                playUser(command);
        }
        cout<<"You end the game with "<<boardScore()<<" points"<<endl;
        sleep(2);
    }


    //This function makes one computer move
    virtual void playAuto()=0;

    //This functions plays the game until the end
    virtual void playAutoAll() final{
        while(!endGame())
            playAuto();
        cout<<"You end the game with "<<boardScore()<<" points"<<endl;
        cout<<"Sleeping for 3 seconds..."<<endl;
        sleep(3);

    }

    //This print function manipulates an ostream object to print out a class
    virtual void print(ostream &os) const = 0;

    //This function returns score of the game
    virtual int boardScore() const=0;

    //This function initializes the game
    virtual void initialize()=0;

    //This function plays every game until it ends
    static void playVector(vector<BoardGame2D *> vector);

    //virtual base class desctructor
    virtual ~BoardGame2D()=default;




};


#endif //CSE241_HW5_BOARDGAME2D_H
