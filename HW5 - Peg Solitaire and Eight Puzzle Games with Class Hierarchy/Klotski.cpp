//
// Created by baris on 12.12.2021.
//

#include "Klotski.h"


baris3::Klotski::Shape::Shape(int length, int width, const vector<int> &bottomLeftCoordinates, const string &name)
        : length(length), width(width), bottomLeftCoordinates(bottomLeftCoordinates), name(name) {}

baris3::Klotski::Shape::Shape(int length, int width, const string &name) : length(length), width(width), name(name) {}

baris3::Klotski::Shape::Shape() {}

int baris3::Klotski::Shape::getLength() const {
    return length;
}

int baris3::Klotski::Shape::getWidth() const {
    return width;
}

const vector<int> &baris3::Klotski::Shape::getBottomLeftCoordinates() const {
    return bottomLeftCoordinates;
}

const string &baris3::Klotski::Shape::getName() const {
    return name;
}

void baris3::Klotski::Shape::setBottomLeftCoordinates(const vector<int> &bottomLeftCoordinates) {
    Shape::bottomLeftCoordinates = bottomLeftCoordinates;
}




baris3::Klotski::Klotski(const vector<Shape> &currentBoard) : currentBoard(currentBoard) {}

baris3::Klotski::Klotski() {}

const vector<baris3::Klotski::Shape> &baris3::Klotski::getCurrentBoard() const {
    return currentBoard;
}

void baris3::Klotski::setCurrentBoard(const vector<Shape> &currentBoard) {
    Klotski::currentBoard = currentBoard;
}

const baris3::Klotski::Shape &baris3::Klotski::getBigSquare() const {
    return bigSquare;
}

void baris3::Klotski::setBigSquare(const baris3::Klotski::Shape &bigSquare) {
    Klotski::bigSquare = bigSquare;
}

const baris3::Klotski::Shape &baris3::Klotski::getSmallSquare1() const {
    return smallSquare1;
}

void baris3::Klotski::setSmallSquare1(const baris3::Klotski::Shape &smallSquare1) {
    Klotski::smallSquare1 = smallSquare1;
}

const baris3::Klotski::Shape &baris3::Klotski::getSmallSquare2() const {
    return smallSquare2;
}

void baris3::Klotski::setSmallSquare2(const baris3::Klotski::Shape &smallSquare2) {
    Klotski::smallSquare2 = smallSquare2;
}

const baris3::Klotski::Shape &baris3::Klotski::getSmallSquare3() const {
    return smallSquare3;
}

void baris3::Klotski::setSmallSquare3(const baris3::Klotski::Shape &smallSquare3) {
    Klotski::smallSquare3 = smallSquare3;
}

const baris3::Klotski::Shape &baris3::Klotski::getSmallSquare4() const {
    return smallSquare4;
}

void baris3::Klotski::setSmallSquare4(const baris3::Klotski::Shape &smallSquare4) {
    Klotski::smallSquare4 = smallSquare4;
}

const baris3::Klotski::Shape &baris3::Klotski::getRectangle1() const {
    return rectangle1;
}

void baris3::Klotski::setRectangle1(const baris3::Klotski::Shape &rectangle1) {
    Klotski::rectangle1 = rectangle1;
}

const baris3::Klotski::Shape &baris3::Klotski::getRectangle2() const {
    return rectangle2;
}

void baris3::Klotski::setRectangle2(const baris3::Klotski::Shape &rectangle2) {
    Klotski::rectangle2 = rectangle2;
}

const baris3::Klotski::Shape &baris3::Klotski::getRectangle3() const {
    return rectangle3;
}

void baris3::Klotski::setRectangle3(const baris3::Klotski::Shape &rectangle3) {
    Klotski::rectangle3 = rectangle3;
}

const baris3::Klotski::Shape &baris3::Klotski::getRectangle4() const {
    return rectangle4;
}

void baris3::Klotski::setRectangle4(const baris3::Klotski::Shape &rectangle4) {
    Klotski::rectangle4 = rectangle4;
}

const baris3::Klotski::Shape &baris3::Klotski::getEmpty1() const {
    return empty1;
}

void baris3::Klotski::setEmpty1(const baris3::Klotski::Shape &empty1) {
    Klotski::empty1 = empty1;
}

const baris3::Klotski::Shape &baris3::Klotski::getEmpty2() const {
    return empty2;
}

void baris3::Klotski::setEmpty2(const baris3::Klotski::Shape &empty2) {
    Klotski::empty2 = empty2;
}

bool baris3::Klotski::isLegal(string command) const {
    return true;
}

void baris3::Klotski::playUser(string command) {

}

bool baris3::Klotski::endGame() const {
    cout<<"endGame() function of Klotski is called"<<endl;
    return true;
}

void baris3::Klotski::playAuto() {
    cout<<"playAuto() function of Klotski is called"<<endl;

}

void baris3::Klotski::print(ostream &os) const {

}

int baris3::Klotski::boardScore() const {
    return 0;
}

void baris3::Klotski::initialize() {

}



