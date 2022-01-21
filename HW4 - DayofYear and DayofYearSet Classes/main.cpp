#include <iostream>
#include "DayofYearSet.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

using namespace baris;

void saveObject(const string& testTitle, const DayofYearSet &ds1,const string& fileName="testResults.txt");

void saveBoolResult(const string& testTitle,const bool& result,const string& fileName="testResults.txt");

void addRandomNumbers(int month, DayofYearSet& ds1);

int main() {

    srand((unsigned)time(0)); //seeding


    cout<<"***************************"<<endl;
    cout<<"Testing constructors: "<<endl;
    DayofYearSet ds1;
    cout<<"No parameter constructor result of DayofYearSet(Object:ds1):"<<endl;
    cout<<"ds1:"<<ds1<<endl;

    cout<<"Total Number of DayofYear Objects="<<ds1[0]->getTotalDayofYearObjects()<<endl;

    DayofYearSet ds2(17,9);
    cout<<"Testing 2 parameters constructor of DayofYearSet(Date:9.17 and Object:ds2)"<<endl;
    cout<<ds2;

    DayofYearSet::DayofYear d1(1,10),d2(2,11),d3(3,12);
    vector<DayofYearSet::DayofYear*> vectorInput={&d1,&d2,&d3};
    DayofYearSet ds3(vectorInput);
    cout<<"Testing constructor of DayofYearSet with vector<DayofYear*>"<<endl;
    cout<<"Dates: 1/10 2/11 3/12 Object: ds3"<<endl;
    cout<<ds3;

    DayofYearSet ds4(vectorInput);
    cout<<"***************************"<<endl;
    cout<<"Testing == operator"<<endl;
    cout<<"Testing == operator. ds3 and ds4 are the object that uses the same vector"
    <<" for construction"<<endl;
    cout<<"ds3 and ds4 have the same dates: 1/10 2/11 3/12"<<endl;
    cout<<"ds3==ds4:"<<boolalpha<<(ds3==ds4)<<endl;
    cout<<"ds1=1/1 and ds3=1/10 2/11 3/12"<<endl;
    cout<<"ds1==ds3:"<<boolalpha<<(ds1==ds3)<<endl;

    saveObject("********************\nTesting == Operator\n***ds1:",ds1);
    saveObject("***ds3:",ds3);
    saveBoolResult("***ds1==ds3:",(ds1==ds3));


    cout<<"***************************"<<endl;
    cout<<"Testing != operator"<<endl;
    cout<<"Testing != operator. ds3 and ds4 are the object that uses the same vector"
        <<" for construction"<<endl;
    cout<<"ds3 and ds4 have the same dates: 1/10 2/11 3/12"<<endl;
    cout<<"ds3!=ds4:"<<boolalpha<<(ds3!=ds4)<<endl;
    cout<<"ds1=1/1 and ds3=1/10 2/11 3/12"<<endl;
    cout<<"ds1!=ds3:"<<boolalpha<<(ds1!=ds3)<<endl;


    saveObject("********************\nTesting != Operator\n***ds1:",ds1);
    saveObject("***ds3:",ds3);
    saveBoolResult("***ds1!=ds3:",(ds1!=ds3));

    cout<<"***************************"<<endl;
    cout<<"Testing add method."<<endl;
    cout<<"Adding all days of 1.Month to ds1 object"<<endl;
    for(int i=1;i<=31;i++)
        ds1.add(i,1);
    cout<<"ds1: "<<endl;
    cout<<ds1<<endl;

    cout<<"Adding all days of 2.Month to ds1 object"<<endl;
    for(int i=1;i<=28;i++)
        ds1.add(i,2);
    cout<<"ds1: "<<endl;
    cout<<ds1<<endl;


    cout<<"***************************"<<endl;
    cout<<"Testing removing method."<<endl;
    cout<<"Removing first 15 days of 1.Month of ds1 object"<<endl;
    for(int i=1;i<=15;i++)
        ds1.remove(i,1);
    cout<<"ds1: "<<endl;
    cout<<ds1<<endl;

    cout<<"Removing first 15 days of 2.Month of ds1 object"<<endl;
    for(int i=1;i<=15;i++)
        ds1.remove(i,2);
    cout<<"ds1: "<<endl;
    cout<<ds1<<endl;

    cout<<"***************************"<<endl;
    cout<<"Testing size method."<<endl;
    cout<<"ds1: "<<endl;
    cout<<ds1<<endl;
    cout<<"Size of ds1="<<ds1.size()<<endl;
    cout<<"ds3:"<<endl<<ds3;
    cout<<"Size of ds3="<<ds3.size()<<endl;

    cout<<"***************************"<<endl;
    cout<<"Testing + operator"<<endl;
    cout<<"Constructing ds5"<<endl;
    DayofYearSet ds5;
    addRandomNumbers(1,ds5);
    cout<<"ds5: "<<ds5<<endl;

    cout<<"Constructing ds6"<<endl;
    DayofYearSet ds6;
    addRandomNumbers(1,ds6);
    cout<<"ds6: "<<ds6<<endl;


    cout<<"Constructing ds7"<<endl;
    DayofYearSet ds7;
    cout<<"ds7=ds5+ds6"<<endl;
    ds7=ds5+ds6;
    cout<<"ds7:"<<ds7<<endl;


    cout<<"Constructing ds8"<<endl;
    DayofYearSet ds8(1,2);
    addRandomNumbers(2,ds8);
    cout<<"ds8: "<<ds8<<endl;

    cout<<"Constructing ds9"<<endl;
    DayofYearSet ds9(1,2);
    addRandomNumbers(2,ds9);
    cout<<"ds9: "<<ds9<<endl;


    cout<<"ds7=ds8+ds9"<<endl;
    ds7=ds8+ds9;
    cout<<"ds7:"<<ds7<<endl;

    saveObject("********************\nTesting + Operator\n***ds8:",ds8);
    saveObject("***ds9:",ds9);
    saveObject("***ds8+ds9=:",ds8+ds9);



    cout<<"***************************"<<endl;
    cout<<"Testing - operator"<<endl;
    cout<<"ds5: "<<ds5<<endl;

    cout<<"ds6: "<<ds6<<endl;


    cout<<"ds7=ds5-ds6"<<endl;
    ds7=ds5-ds6;
    cout<<"ds7:"<<ds7<<endl;




    cout<<"ds8: "<<ds8<<endl;

    cout<<"ds9: "<<ds9<<endl;

    cout<<"ds7=ds8-ds9"<<endl;
    ds7=ds8-ds9;

    cout<<"ds7:"<<ds7<<endl;

    saveObject("********************\nTesting - Operator\n***ds8:",ds8);
    saveObject("***ds9:",ds9);
    saveObject("***ds8-ds9=:",ds8-ds9);


    cout<<"***************************"<<endl;
    cout<<"Testing ^ operator"<<endl;
    cout<<"ds5: "<<ds5<<endl;

    cout<<"ds6: "<<ds6<<endl;


    cout<<"ds7=ds5^ds6"<<endl;
    ds7=ds5^ds6;
    cout<<"ds7:"<<ds7<<endl;


    cout<<"ds8: "<<ds8<<endl;

    cout<<"ds9: "<<ds9<<endl;

    cout<<"ds7=ds8^ds9"<<endl;
    ds7=ds8^ds9;

    cout<<"ds7:"<<ds7<<endl;

    saveObject("********************\nTesting ^ Operator\n***ds8:",ds8);
    saveObject("***ds9:",ds9);
    saveObject("***ds8^ds9=:",ds8^ds9);


    cout<<"***************************"<<endl;
    cout<<"Testing ! operator"<<endl;
    cout<<"ds5: "<<ds5<<endl;

    cout<<"ds6: "<<ds6<<endl;


    cout<<"ds7=!(ds5+ds6)"<<endl;
    ds7=!(ds5+ds6);
    cout<<"ds7:"<<ds7<<endl;


    cout<<"ds8: "<<ds8<<endl;

    cout<<"ds9: "<<ds9<<endl;

    cout<<"ds7=!(ds8+ds9)"<<endl;
    ds7=!(ds8+ds9);

    cout<<"ds7:"<<ds7<<endl;

    saveObject("********************\nTesting ! Operator\n***ds8:",ds8);
    saveObject("***ds9:",ds9);
    saveObject("***!(ds8+ds9)=:",!(ds8+ds9));


    cout<<"***************************"<<endl;
    cout<<"Testing De Morgan Rule"<<endl;



    cout<<"Constructing ds10"<<endl;
    DayofYearSet ds10(1,4);
    addRandomNumbers(4,ds10);
    addRandomNumbers(5,ds10);
    cout<<"Constructing ds11"<<endl;
    DayofYearSet ds11(1,4);
    addRandomNumbers(4,ds11);
    addRandomNumbers(5,ds11);



    cout<<"ds10:"<<ds10<<endl<<"ds11:"<<ds11;

    cout<<"!(ds10+ds11)="<<!(ds10+ds11)<<endl;

    cout<<"!ds10+!ds11="<<(!(ds10)+!(ds11))<<endl;


    cout<<"!(ds10+ds11)==!ds10^!ds11: "<<boolalpha<<((!(ds10)^!(ds11))==(!(ds10+ds11)))<<endl;

    saveObject("********************\nTesting De Morgan Rules\nds10:",ds10,"testResultsDeMorgan.txt");
    saveObject("***ds11:",ds11,"testResultsDeMorgan");
    saveObject("***!(ds10+ds11)=",!(ds10+ds11),"testResultsDeMorgan");
    saveObject("***!ds10+!ds11=",(!(ds10)+!(ds11)),"testResultsDeMorgan");
    saveBoolResult("******!(ds10+ds11)==!ds10^!ds11: ",((!(ds10)^!(ds11))==(!(ds10+ds11))),"testResultsDeMorgan");


    cout<<"Constructing ds12"<<endl;
    DayofYearSet ds12(1,5);
    addRandomNumbers(5,ds12);
    addRandomNumbers(6,ds12);
    cout<<"Constructing ds13"<<endl;
    DayofYearSet ds13(1,4);
    addRandomNumbers(5,ds13);
    addRandomNumbers(6,ds13);

    /*cout<<"!ds12^!ds13==!(ds12+ds13):"<<
        boolalpha<<((!(ds12)^!(ds13))==(!(ds12+ds13)))<<endl;*/

    cout<<"ds12:"<<ds12<<endl<<"ds13:"<<ds13;

    cout<<"!(ds12+ds13)="<<!(ds12+ds13)<<endl;

    cout<<"!ds12+!ds13="<<(!(ds12)+!(ds13))<<endl;


    cout<<"!(ds12+ds13)==!ds12^!ds13: "<<boolalpha<<((!(ds12)^!(ds13))==(!(ds12+ds13)))<<endl;


    saveObject("********************\nTesting De Morgan Rules\nds12:",ds12,"testResultsDeMorgan.txt");
    saveObject("***ds13:",ds13,"testResultsDeMorgan");
    saveObject("***!(ds12+ds13)=",!(ds12+ds13),"testResultsDeMorgan");
    saveObject("!***ds12+!ds13=",(!(ds12)+!(ds13)),"testResultsDeMorgan");
    saveBoolResult("******!(ds12+ds13)==!ds12^!ds13: ",((!(ds12)^!(ds13))==(!(ds12+ds13))),"testResultsDeMorgan");


    cout<<"Constructing ds14"<<endl;
    DayofYearSet ds14(1,6);
    addRandomNumbers(6,ds14);
    addRandomNumbers(7,ds14);
    cout<<"Constructing ds15"<<endl;
    DayofYearSet ds15(1,6);
    addRandomNumbers(6,ds15);
    addRandomNumbers(7,ds15);



    cout<<"ds14:"<<ds14<<endl<<"ds15:"<<ds15;

    cout<<"!(ds14+ds15)="<<!(ds14+ds15)<<endl;

    cout<<"!ds14+!ds15="<<(!(ds14)+!(ds15))<<endl;


    cout<<"!(ds14+ds15)==!ds14^!ds15: "<<boolalpha<<((!(ds14)^!(ds15))==(!(ds14+ds15)))<<endl;



    cout<<"Constructing ds16"<<endl;
    DayofYearSet ds16(1,7);
    addRandomNumbers(7,ds16);
    addRandomNumbers(8,ds16);
    cout<<"Constructing ds17"<<endl;
    DayofYearSet ds17(1,7);
    addRandomNumbers(7,ds17);
    addRandomNumbers(8,ds17);


    cout<<"ds16:"<<ds16<<endl<<"ds17:"<<ds17;

    cout<<"!(ds16+ds17)="<<!(ds16+ds17)<<endl;

    cout<<"!ds16+!ds17="<<(!(ds16)+!(ds17))<<endl;


    cout<<"!(ds16+ds17)==!ds16^!ds17: "<<boolalpha<<((!(ds16)^!(ds17))==(!(ds16+ds17)))<<endl;


    cout<<"Constructing ds18"<<endl;
    DayofYearSet ds18(1,7);
    addRandomNumbers(7,ds18);
    addRandomNumbers(8,ds18);
    cout<<"Constructing ds19"<<endl;
    DayofYearSet ds19(1,7);
    addRandomNumbers(7,ds19);
    addRandomNumbers(8,ds19);



    cout<<"ds18:"<<ds18<<endl<<"ds19:"<<ds19;

    cout<<"!(ds18+ds19)="<<!(ds18+ds19)<<endl;

    cout<<"!ds18+!ds19="<<(!(ds18)+!(ds19))<<endl;


    cout<<"!(ds18+ds19)==!ds18^!ds19: "<<boolalpha<<((!(ds18)^!(ds19))==(!(ds18+ds19)))<<endl;


    cout<<"***************************"<<endl;
    cout<<"Testing [] Operator"<<endl;
    DayofYearSet ds20(1,12);
    addRandomNumbers(12,ds20);
    cout<<"ds20:"<<ds20<<endl;

    cout<<"ds20[0]="<<ds20[0]->getDay()<<"/"<<ds20[0]->getMonth()<<endl;

    cout<<"ds20[1]="<<ds20[1]->getDay()<<"/"<<ds20[1]->getMonth()<<endl;

    cout<<"Total Number of DayofYear Objects="<<ds1[0]->getTotalDayofYearObjects()<<endl;


    cout<<"***************************"<<endl;
    cout<<"All tests are succesfully ended"<<endl;


    return 0;
}

ostream& baris::operator<<(ostream &outputStream, const DayofYearSet &ds1) {
    outputStream<<"Total Elements of Current DayofYearSet: \n";
    outputStream<<"day/month\n";

    for(DayofYearSet::DayofYear* d1: ds1.getdateSet()){
        outputStream<<d1->getDay();
        outputStream<<"/";
        outputStream<<d1->getMonth();
        outputStream<<"\n";
    }

    return outputStream;
}


void addRandomNumbers(int month,DayofYearSet& d1){
    for(int i=0;i<15;i++)
        d1.add(rand()%28+1,month);
}

void saveObject(const string& testTitle, const DayofYearSet &ds1,const string& fileName) {
    ofstream myfile; //fstream library to create a text file
    myfile.open(fileName,ios_base::app);
    myfile<<testTitle<<"\n";

    for (DayofYearSet::DayofYear* d1 : ds1.getdateSet()) { //Saving the board at that moment
        myfile<<d1->getDay()<<"/"<<d1->getMonth();
        myfile << "\n";
    }



    cout << "Object is succesfully saved in " << fileName << endl;
    myfile.close();
}

void saveBoolResult(const string& testTitle,const bool& result,const string& fileName){
    ofstream myfile; //fstream library to create a text file
    myfile.open(fileName,ios_base::app);
    myfile<<testTitle<<":";

    if(result)
        myfile<<"true\n";
    else
        myfile<<"false\n";


    cout << "Result is succesfully saved in " << fileName << endl;
    myfile.close();
}





