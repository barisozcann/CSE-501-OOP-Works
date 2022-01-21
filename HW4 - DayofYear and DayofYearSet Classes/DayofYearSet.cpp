//
// Created by baris on 2.12.2021.
//

#include "DayofYearSet.h"


using namespace std;

/**
 * Initializing static integer totalDayofYearObjects
 */
int baris::DayofYearSet::DayofYear::totalDayofYearObjects=0;

/**
 * This constructor first checks given month and combines it
 * with the given day.
 * It exits if the date is illegal
 * @param day is day
 * @param month is month
 */
baris::DayofYearSet::DayofYear::DayofYear(int day, int month) {

    if(month==1 && day>0 && day<=31){
        this->day=day;
        this->month=month;
    }
    else if(month==2 && day>0 && day<=28){
        this->day=day;
        this->month=month;
    }
    else if(month==3 && day>0 && day<=31){
        this->day=day;
        this->month=month;
    }

    else if(month==4 && day>0 && day<=30){
        this->day=day;
        this->month=month;
    }

    else if(month==5 && day>0 && day<=31){
        this->day=day;
        this->month=month;
    }

    else if(month==6 && day>0 && day<=30){
        this->day=day;
        this->month=month;
    }

    else if(month==7 && day>0 && day<=31){
        this->day=day;
        this->month=month;
    }

    else if(month==8 && day>0 && day<=31){
        this->day=day;
        this->month=month;
    }
    else if(month==9 && day>0 && day<=30){
        this->day=day;
        this->month=month;
    }
    else if(month==10 && day>0 && day<=31){
        this->day=day;
        this->month=month;
    }
    else if(month==11 && day>0 && day<=30){
        this->day=day;
        this->month=month;
    }
    else if(month==12 && day>0 && day<=31){
        this->day=day;
        this->month=month;
    }

    else{
        cerr<<day<<"."<<month<<" is invalid date!"<<endl;
        exit(1);
    }

    totalDayofYearObjects++;
}
/**
 * This no parameter contructor creates DayofYear object with 01/01 date
 */
baris::DayofYearSet::DayofYear::DayofYear() {
    this->day=1;
    this->month=1;

    totalDayofYearObjects++;

}
/**
 * Desctructor of DayofYear object
 */
baris::DayofYearSet::DayofYear::~DayofYear() {

}

int baris::DayofYearSet::DayofYear::getDay() const {
    return day;
}



int baris::DayofYearSet::DayofYear::getMonth() const {
    return month;
}

int baris::DayofYearSet::DayofYear::getTotalDayofYearObjects() {
    return totalDayofYearObjects;
}


/**
 * This method compares two DayofYear classes
 * @param d2 DayofYear object
 * @return true if two objects have the same day and month
 */
bool baris::DayofYearSet::DayofYear::operator==(const baris::DayofYearSet::DayofYear &d2) const {
    return(getDay()==d2.getDay() && getMonth()==d2.getMonth());
}

/**
 * Default constructor of DayofYearSet class
 * It adds 01/01 date to vector of dateSet
 */
baris::DayofYearSet::DayofYearSet() {
    this->dateSet.push_back(new DayofYear(1,1));
}

/**
 * This constructor initialize the class witj given day and month
 * @param day
 * @param month
 */
baris::DayofYearSet::DayofYearSet(int day, int month) {
    this->dateSet.push_back(new DayofYear(day,month));
}
/**
 * This constructor constructs the class by given DayofYear* vector
 * @param dateSet
 */
baris::DayofYearSet::DayofYearSet(const vector<DayofYear *> &dateSet) : dateSet(dateSet) {}

/**
 * Getter method of DayofYear* vector that named dateSet
 * @return
 */
const vector<baris::DayofYearSet::DayofYear *> &baris::DayofYearSet::getdateSet() const {
    return dateSet;
}

/**
 * This method searches a DayofYear object in vector
 * by given DayofYear* pointer
 * @param d1
 * @return true if it finds the object in the vector of dateSet
 */
bool baris::DayofYearSet::search(baris::DayofYearSet::DayofYear* d1) const{
    for(DayofYear* d2 : dateSet)
        if(*d1==*d2)
            return true;
    return false;
}

/**
 * This method finds the index of specifix DayofYear* pointer
 * by given DayofYear* pointer
 * @param d1
 * @return index of given element in the vector
 */

int baris::DayofYearSet::findIndex(baris::DayofYearSet::DayofYear* d1) const {
    for(int i=0;i<dateSet.size();i++)
        if(*d1==*dateSet[i])
            return i;
    return -1;
}

/**
 * This method adds a new DayofYear* pointer to the dateSet vector
 * If it detects a duplicate element, it warns user and doesn't add anything
 * to dateSet vector
 * @param day
 * @param month
 */
void baris::DayofYearSet::add(int day, int month) {
    DayofYear* d1=new DayofYear(day,month);
    if(search(d1))
        cout<<d1->getDay()<<"."<<d1->getMonth()<<" is already in the set."
        <<"You can't add a duplicate one!"<<endl;
    else{
        cout<<d1->getDay()<<"."<<d1->getMonth()<<" is added to the DayofYearSet"<<endl;
        dateSet.push_back(d1);
    }
}
/**
 * It removes a DayofYear* pointer by given day and month
 * @param day
 * @param month
 */
void baris::DayofYearSet::remove(int day,int month) {
    DayofYear* d1=new DayofYear(day,month);
    if(search(d1)){
        int elementIndex= findIndex(d1);
        DayofYear* realD1=dateSet[elementIndex];
        dateSet.erase(dateSet.begin()+elementIndex);
        delete realD1;
        realD1=nullptr;
        cout<<d1->getDay()<<"."<<d1->getMonth()<<
        " is removed from DayofYearSet"<<endl;
    }
    else{
        cout<<d1->getDay()<<"."<<d1->getMonth()<<" does not exist in DayofYearSet Class!"<<endl;
    }
    delete d1;
    d1= nullptr;

}

/**
 * This method returns size of dateSet vector
 * @return
 */

int baris::DayofYearSet::size() const {
    return dateSet.size();
}

/**
 * This overloaded operator == searches every element of given class in dateSet vector
 * It repeats operation by converse and returns false if it detects any different element
 * @param ds2
 * @return
 */
bool baris::DayofYearSet::operator==(const baris::DayofYearSet &ds2) const {
    for(DayofYear* d1: dateSet){
        if(ds2.search(d1)==false)
            return false;
    }

    for(DayofYear* d2: ds2.getdateSet()){
        if(search(d2)==false) //double controlling to prevent subset cases
            return false;
    }
    return true;
}
/**
 * This overloaded operator != returns just inverse version of == operator
 * @param ds2
 * @return
 */
bool baris::DayofYearSet::operator!=(const baris::DayofYearSet &ds2) const {
    return !(*this==ds2);
}


/**
 * This method removes duplicate elements in dateSet vector
 * It is called in + operator overloading to fix union set
 * @param daysVector
 */
void baris::DayofYearSet::removeDuplicates(vector<DayofYear*>& daysVector) const{
    for(int i=0;i<daysVector.size();i++)
        for(int j=i+1;j<daysVector.size();j++)
            if(*daysVector[i]==*daysVector[j]){
                DayofYear* duplicate=daysVector[j];
                delete duplicate;
                duplicate= nullptr;
                daysVector.erase(daysVector.begin()+j);
            }
}
/**
 * This overloaded operator + creates a new DayofYear* vector
 * It combines DayofYear elements of this class and given class in the vector
 * It removes duplicate elements in the vector and finally returns a new DayofYearSet class by using this vector
 * @param ds2
 * @return
 */
const baris::DayofYearSet baris::DayofYearSet::operator+(const baris::DayofYearSet &ds2) const {
    vector<DayofYear*> unionVector;
    for(DayofYear* d1: dateSet)
        unionVector.push_back(new DayofYear(d1->getDay(),d1->getMonth()));

    for(DayofYear* d2: ds2.getdateSet())
        unionVector.push_back(new DayofYear(d2->getDay(),d2->getMonth()));

    removeDuplicates(unionVector);

    return DayofYearSet(unionVector);
}

/**
 * This overloaded operator - creates a new DayofYear* vector
 * Then it searches all elements of this class in given class
 * Then it stores different elements in the vector and returns a new class by using this vector
 * @param ds2
 * @return
 */
const baris::DayofYearSet baris::DayofYearSet::operator-(const baris::DayofYearSet &ds2) const {
    vector<DayofYear*> differenceSet;
    for(DayofYear* d1: dateSet)
        if(!ds2.search(d1))
            differenceSet.push_back(d1);
    
    return DayofYearSet(differenceSet);    
}
/**
 * This overloaded operator ^ creates a new DayofYear* vector
 * It searches elements of given class in this class' vector
 * It stores common elements in the vector and returns a new class by using this vector
 * @param ds2
 * @return
 */
const baris::DayofYearSet baris::DayofYearSet::operator^(const baris::DayofYearSet &ds2) const {
    vector<DayofYear*> intersectionSet;
    for(DayofYear* d2: ds2.getdateSet())
        if(search(d2))
            intersectionSet.push_back(d2);

    return DayofYearSet(intersectionSet);
}


/**
 * This overloaded operator ! creates a new DayofYear* vector to store elements
 * It iterates through all 365 days in year
 * It calls search method for all 365 days and stores elements if search method returns false
 * Finally it returns a new DayofYearSet object by using this vector
 * @return
 */
const baris::DayofYearSet baris::DayofYearSet::operator!() const {
    vector<DayofYear*> complementSet;
    DayofYear* tempPointer;
    int month=1;
    for(int i=1;i<=31;i++){
        tempPointer=new DayofYear(i,month);
        if(!search(tempPointer))
            complementSet.push_back(tempPointer);
        //delete tempPointer;
        //tempPointer= nullptr;
    }

    month=2;
    for(int i=1;i<=28;i++){
        tempPointer=new DayofYear(i,month);
        if(!search(tempPointer))
            complementSet.push_back(tempPointer);
        //delete tempPointer;
        //tempPointer= nullptr;
    }

    month=3;
    for(int i=1;i<=31;i++){
        tempPointer=new DayofYear(i,month);
        if(!search(tempPointer))
            complementSet.push_back(tempPointer);
       // delete tempPointer;
        //tempPointer= nullptr;
    }

    month=4;
    for(int i=1;i<=30;i++){
        tempPointer=new DayofYear(i,month);
        if(!search(tempPointer))
            complementSet.push_back(tempPointer);
        //delete tempPointer;
        //tempPointer= nullptr;
    }

    month=5;
    for(int i=1;i<=31;i++){
        tempPointer=new DayofYear(i,month);
        if(!search(tempPointer))
            complementSet.push_back(tempPointer);
        //delete tempPointer;
        //tempPointer= nullptr;
    }

    month=6;
    for(int i=1;i<=30;i++){
        tempPointer=new DayofYear(i,month);
        if(!search(tempPointer))
            complementSet.push_back(tempPointer);
        //delete tempPointer;
        //tempPointer= nullptr;
    }

    month=7;
    for(int i=1;i<=31;i++){
        tempPointer=new DayofYear(i,month);
        if(!search(tempPointer))
            complementSet.push_back(tempPointer);
        //delete tempPointer;
        //tempPointer= nullptr;
    }

    month=8;
    for(int i=1;i<=31;i++){
        tempPointer=new DayofYear(i,month);
        if(!search(tempPointer))
            complementSet.push_back(tempPointer);
        //delete tempPointer;
        //tempPointer= nullptr;
    }

    month=9;
    for(int i=1;i<=30;i++){
        tempPointer=new DayofYear(i,month);
        if(!search(tempPointer))
            complementSet.push_back(tempPointer);
       // delete tempPointer;
        //tempPointer= nullptr;
    }

    month=10;
    for(int i=1;i<=31;i++){
        tempPointer=new DayofYear(i,month);
        if(!search(tempPointer))
            complementSet.push_back(tempPointer);
        //delete tempPointer;
        //tempPointer= nullptr;
    }

    month=11;
    for(int i=1;i<=30;i++){
        tempPointer=new DayofYear(i,month);
        if(!search(tempPointer))
            complementSet.push_back(tempPointer);
        //delete tempPointer;
        //tempPointer= nullptr;
    }

    month=12;
    for(int i=1;i<=31;i++){
        tempPointer=new DayofYear(i,month);
        if(!search(tempPointer))
            complementSet.push_back(tempPointer);
        //delete tempPointer;
        //tempPointer= nullptr;
    }

    //delete tempPointer;
    //tempPointer= nullptr;

    removeDuplicates(complementSet);

    return DayofYearSet(complementSet);
}
/**
 * This method returns i th element of dateSet vector
 * @param index
 * @return
 */
baris::DayofYearSet::DayofYear *baris::DayofYearSet::operator[](int index) {
    return dateSet[index];
}










