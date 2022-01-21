//
// Created by baris on 2.12.2021.
//

#ifndef DAYOFYEARSET_H
#define DAYOFYEARSET_H

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


namespace baris{

    /**
     * DayofYearSet Class
     */
    class DayofYearSet {
    public:
        /**
         * DayofYear innerclass
         */
        class DayofYear{
        public:
            DayofYear(int day, int month); //Two parameter constructor
            DayofYear(); //Default constructor

            virtual ~DayofYear(); //Destructor

            int getDay() const; //getter of integer day

            int getMonth() const; //getter of integer month

            static int getTotalDayofYearObjects(); //getter of static integer totalDayofYearObjects

            bool operator==(const DayofYear& d2) const; //returns true if two classes have the same date


        private:
            int day,month; //day and month values to represent a day of a year
            static int totalDayofYearObjects; //It keeps total number of DayofYear objects

        };

        explicit DayofYearSet(); //No parameter contructor of DayofYearSet

        explicit DayofYearSet(int day, int month); //Two parameter contructor of DayofYearSet

        explicit DayofYearSet(const vector<DayofYear *> &dateSet); //Vector contructor of DayofYearSet


        const vector<DayofYear *> &getdateSet() const; //getter method of vector of DayofYearSet

        void add(int day, int month); //This method adds a new DayofYear* pointer to vector

        void remove(int day,int month); //This method removes a new DayofYear* pointer to vector

        int size() const; //This method returns size of DayofYearSet

        bool operator==(const DayofYearSet& ds2) const; //This operator checks if two DayofYear classes are equal

        bool operator!=(const DayofYearSet& ds2) const; //This operator checks if two DayofYear classes are not equal

        const DayofYearSet operator+(const DayofYearSet& ds2) const; //This operator returns union set class of two classes

        const DayofYearSet operator-(const DayofYearSet& ds2) const; //This operator returns difference set class of two classes

        const DayofYearSet operator^(const DayofYearSet& ds2) const; //This operator returns intersection set class of two classes

        const DayofYearSet operator!() const; //This operator returns complement set class of a class

        friend ostream& operator<<(ostream& outputStream, const DayofYearSet& ds1); //This operator prints out properties about class

        DayofYear* operator[](int index); //This operator returns i th index of vector of DayofYearSet object




    private:
        vector<DayofYear*> dateSet; //Vector that keeps DayofYear* pointer

        bool search(DayofYear* d1) const; //This method searches a DayofYear object by its pointer in the vector

        int findIndex(DayofYear* d1) const; //This method returns index of DayofYear object in the vector by its pointer in the vector

        void removeDuplicates(vector<DayofYear*>& daysVector) const; //This method removes duplicates elements in vector in + operation

    };

}


#endif DAYOFYEARSET_H
