#include <iostream>
#include "GTUIterator.h"
#include "GTUIteratorConst.h"
#include "GTUVector.h"
#include "GTUSet.h"
#include "GTUArray.h"
#include <string>
#include<algorithm>


using namespace std;

using namespace baris1;

using namespace baris2;

using namespace baris3;



// helper function 1
void printInt(int a){
    cout << a << " ";
}

void printStr(string a){
    cout << a << " ";
}

int main() {
    int m[5]={15,25,35,45,55};
    int *x=m;

//    cout<<*x<<endl;
//    x++;
//    cout<<*x<<endl;


    GTUIterator<int> i1(x);

    GTUIterator<int> i2;

    cout<<"i2=i1"<<endl;
    i2=i1;

    cout<<"*i1=105;"<<endl;
    *i1=105;

    cout<<"Testing ++ operator for GTUIterator"<<endl;
    cout<<*i2<<endl;
    ++i2;
    cout<<*i2<<endl;
    ++i2;
    cout<<*i2<<endl;

    cout<<"Testing -- operator for GTUIterator"<<endl;
    --i2;
    cout<<*i2<<endl;

    cout<<(i1==i2)<<endl;

    --i2;
    cout<<*i2<<endl;


    cout<<"Testing == operator for GTUIteratorConst"<<endl;
    cout<<"(i1==i2):"<<boolalpha<<(i1==i2)<<endl;

    cout<<"************** Constant iterator ***************"<<endl;
    GTUIteratorConst<int> ci1(x);

    cout<<"Testing ++ operator for GTUIteratorConst"<<endl;
    cout<<*ci1<<endl;
    ++ci1;
    cout<<*ci1<<endl;
    ++ci1;
    cout<<*ci1<<endl;

    cout<<"Testing -- operator for GTUIteratorConst"<<endl;
    --ci1;
    cout<<*ci1<<endl;

//    *ci1=99;

    cout<<*ci1<<endl;

    GTUIteratorConst<int> ci2(x);

    cout<<"Testing == operator for GTUIteratorConst"<<endl;
    cout<<"ci1==ci2:"<<boolalpha<<(ci1==ci2)<<endl;
    ++ci2;
    cout<<"++ci2"<<endl;
    cout<<"ci1==ci2:"<<boolalpha<<(ci1==ci2)<<endl;

    cout<<"**********Vector testing begins*********"<<endl;
    int y=111;
    GTUVector<int> vector1(y);
    vector1.push_back(222);
    vector1.push_back(333);
    vector1.push_back(777);
    vector1.push_back(666);
    vector1.push_back(555);
    vector1.push_back(444);
    int pop=vector1.pop_back();
    cout<<"Pop value:"<<pop<<endl;

   cout<<"Size:"<<vector1.size()<<endl;

   int z=333;
   int* z_ptr=&z;

   GTUIterator<int> eraseIter(z_ptr);

    cout<<"Size:"<<vector1.size()<<endl;
    vector1.erase(eraseIter);
    cout<<"Size:"<<vector1.size()<<endl;


    cout<<"Elements of vector1 with using for iterator(begin end) loop:"<<endl;
    for(auto it=vector1.begin();it!=vector1.end();++it){
        cout<<*it<<endl;
    }

    cout<<"Elements of vector1 with using for iterator(cbegin cend) loop:"<<endl;
    for(auto it=vector1.cbegin();it!=vector1.cend();++it){
        cout<<*it<<endl;
    }

    GTUIterator<int> beginIter=vector1.begin();

    cout<<"Begin Iter:"<<*beginIter<<endl;

    GTUIterator<int> endIter=vector1.end();
    cout<<"Last Element: "<<*(--endIter)<<endl;

    GTUIteratorConst<int> constBeginIter=vector1.cbegin();
    cout<<"Const Begin Iter:"<<*constBeginIter<<endl;

    GTUIteratorConst<int> constEndIter=vector1.cend();
    cout<<"Const End Iter:"<<*constEndIter<<endl;


    cout<<"Testing find method for vector"<<endl;


    int val=222;
    auto findIter=find(vector1.begin(),vector1.end(),val);
    if(findIter!=vector1.end())
        cout<<"Vector contains the element of "<<*findIter<<endl;
    else
        cout<<val<< " is not found in the vector"<<endl;


    val=1111;
    findIter=find(vector1.begin(),vector1.end(),val);
    if(findIter!=vector1.end())
        cout<<"Vector contains the element of "<<*findIter<<endl;
    else
        cout<<val<< " is not found in the vector"<<endl;




    cout<<"********** Testing for_each method for vector class ****************"<<endl;
    for_each(vector1.begin(),vector1.end(),printInt);

    cout<<endl;

    //    sort(vector1.begin(),vector1.end());

    cout<<"[] testing\t testing vector1[2]:"<<endl;
    cout<<"vector1[2]="<<vector1[2]<<endl;

    cout<<"**********Testing Clear method of Vector class***********\n";
    vector1.clear();
    cout<<"Size:"<<vector1.size()<<endl;

    cout<<"*************** Vector Class Testing is Over"<<endl;

    cout<<"*************** Set Class testing begins ***********"<<endl;

    GTUSet<string> set1;

    cout<<"Set size: "<<set1.size()<<endl;
    cout<<"Set empty: "<<boolalpha<<set1.empty()<<endl;

    set1.add("Apple");
    set1.add("Pine");
    set1.add("Coconut");
    set1.add("Kiwi");
    set1.add("Banana");
    set1.add("Banana");
    set1.add("Orange");

    cout<<"Set size: "<<set1.size()<<endl;
    cout<<"Set empty: "<<boolalpha<<set1.empty()<<endl;


    cout<<"Testing find method for Set"<<endl;

    string wordd="Coconut";
    auto findIterr=find(set1.begin(),set1.end(),wordd);
    if(findIterr!=set1.end())
        cout<<"Set contains the element of "<<*findIterr<<endl;
    else
        cout<<wordd<< " is not found in the Set"<<endl;

    wordd="Pineapple";
    findIterr=find(set1.begin(),set1.end(),wordd);
    if(findIterr!=set1.end())
        cout<<"Set contains the element of "<<*findIterr<<endl;
    else
        cout<<wordd<< " is not found in the vector"<<endl;

    string banana="Banana";
    string* bananaPtr=&banana;
    GTUIterator<string> setEraseIter(bananaPtr);
    set1.erase(setEraseIter);


    cout<<"Elements of set1 with using for iterator(begin end) loop:"<<endl;
    for(auto it=set1.begin();it!=set1.end();++it){
        cout<<*it<<endl;
    }

    cout<<"Elements of set1 with using for iterator(cbegin cend) loop:"<<endl;
    for(auto it=set1.begin();it!=set1.end();++it){
        cout<<*it<<endl;
    }

    cout<<"********** Testing for_each method for Set class ****************"<<endl;
    for_each(set1.begin(),set1.end(), printStr);
    cout<<endl;

    cout<<"**********Testing Clear method of Set class***********\n";
    set1.clear();
    cout<<"Size:"<<set1.size()<<endl;

    cout<<"*************GTU Set Testing Ends ****************"<<endl;

    cout<<"******************GTU Array Testing begins *******************"<<endl;
    GTUArray<int,5> myArray;
    cout<<"GTU Array size: "<<myArray.size()<<endl;
    cout<<"GTU Array empty: "<<boolalpha<<myArray.empty()<<endl;
    myArray.add(5);
    myArray.add(100);
    myArray.add(21);
    myArray.add(3);
    myArray.add(41);
    myArray.add(68);

    cout<<"GTU Array size: "<<myArray.size()<<endl;
    cout<<"GTU Array empty: "<<boolalpha<<myArray.empty()<<endl;

    int arrayTestInt=5;
    int* testIntPtr=&arrayTestInt;

    GTUIterator<int> arrayEraseIterator(testIntPtr);
    myArray.erase(arrayEraseIterator);

    cout<<"********** Testing for_each method for Array class ****************"<<endl;
    for_each(myArray.begin(),myArray.end(), printInt);
    cout<<endl;

    cout<<"Testing find method for Array"<<endl;


    int vall=100;
    auto findIterrr=find(myArray.begin(),myArray.end(),vall);
    if(findIterrr!=myArray.end())
        cout<<"Array contains the element of "<<*findIterrr<<endl;
    else
        cout<<vall<< " is not found in the vector"<<endl;

    vall=50;
    findIterrr=find(myArray.begin(),myArray.end(),vall);
    if(findIterrr!=myArray.end())
        cout<<"Array contains the element of "<<*findIterrr<<endl;
    else
        cout<<vall<< " is not found in the Array"<<endl;

    cout<<"**********Testing Clear method of Array class***********\n";
    myArray.clear();
    cout<<"Size:"<<myArray.size()<<endl;




    cout<<"*************GTU Array Testing Ends ****************"<<endl;



    return 0;
}
