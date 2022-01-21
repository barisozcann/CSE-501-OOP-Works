#include <iostream>
#include "BoardGame2D.h"
#include "PegSolitaire.h"
#include "EightPuzzle.h"
#include "Klotski.h"
using namespace std;

using namespace baris;

using namespace baris2;

using namespace baris3;

int main() {

    srand(unsigned(time(0)));
    BoardGame2D *p1=new PegSolitaire;

    //cout<<*p1;

//    p1->playUser("e3-d");
    p1->playUser();

    //p1->playAuto();
   // p1->playAutoAll();

  BoardGame2D *p2=new EightPuzzle;
  p2->playUser();


  BoardGame2D *p3=new Klotski;

  p3->playAutoAll();

  BoardGame2D *p4=new Klotski;

  BoardGame2D *p5=new PegSolitaire;

  BoardGame2D *p6=new PegSolitaire;

  BoardGame2D *p7=new EightPuzzle;

  BoardGame2D *p8=new EightPuzzle;

  vector<BoardGame2D *> gameVector{p3,p4,p5,p6,p7,p8};

  BoardGame2D::playVector(gameVector);

  delete p1,p2,p3,p4,p5,p6,p7,p8;



    return 0;
}
