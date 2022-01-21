//
// Created by baris on 12.12.2021.
//

#ifndef CSE241_HW5_KLOTSKI_H
#define CSE241_HW5_KLOTSKI_H

#include <ostream>
#include "BoardGame2D.h"

using namespace std;


namespace baris3{



class Klotski: public BoardGame2D {

public:
    class Shape{
    public:
        Shape(int length, int width, const vector<int> &bottomLeftCoordinates, const string &name);

        Shape(int length, int width, const string &name);

        Shape();

        virtual ~Shape()=default;

        int getLength() const;

        int getWidth() const;

        const vector<int> &getBottomLeftCoordinates() const;

        const string &getName() const;

        void setBottomLeftCoordinates(const vector<int> &bottomLeftCoordinates);


    private:
        int length,width;
        vector<int> bottomLeftCoordinates;
        string name;
    };

    Klotski(const vector<Shape> &currentBoard);

    Klotski();

    virtual ~Klotski()=default;

    const vector<Shape> &getCurrentBoard() const;

    void setCurrentBoard(const vector<Shape> &currentBoard);

    const Shape &getBigSquare() const;

    void setBigSquare(const Shape &bigSquare);

    const Shape &getSmallSquare1() const;

    void setSmallSquare1(const Shape &smallSquare1);

    const Shape &getSmallSquare2() const;

    void setSmallSquare2(const Shape &smallSquare2);

    const Shape &getSmallSquare3() const;

    void setSmallSquare3(const Shape &smallSquare3);

    const Shape &getSmallSquare4() const;

    void setSmallSquare4(const Shape &smallSquare4);

    const Shape &getRectangle1() const;

    void setRectangle1(const Shape &rectangle1);

    const Shape &getRectangle2() const;

    void setRectangle2(const Shape &rectangle2);

    const Shape &getRectangle3() const;

    void setRectangle3(const Shape &rectangle3);

    const Shape &getRectangle4() const;

    void setRectangle4(const Shape &rectangle4);

    const Shape &getEmpty1() const;

    void setEmpty1(const Shape &empty1);

    const Shape &getEmpty2() const;

    void setEmpty2(const Shape &empty2);

    bool isLegal(string command) const override;

    void playUser(string command) override;

    bool endGame() const override;

    void playAuto() override;

    void print(ostream &os) const override;

    int boardScore() const override;

    void initialize() override;

private:
    Shape bigSquare,smallSquare1,smallSquare2,smallSquare3,smallSquare4;
    Shape rectangle1,rectangle2,rectangle3,rectangle4;
    Shape empty1,empty2;

    vector<Shape> currentBoard;
    



};

}

#endif //CSE241_HW5_KLOTSKI_H
