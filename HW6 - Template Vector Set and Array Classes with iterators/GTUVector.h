//
// Created by darkb on 25.12.2021.
//

#ifndef CSE241_HW6_GTUVECTOR_H
#define CSE241_HW6_GTUVECTOR_H

#include <iostream>
#include "Iterable.h"
#include "GTUVector.h"
#include "GTUIteratorConst.h"
#include <memory>
using namespace  std;

namespace baris1{

/**
 * Custom deleter that deletes the raw pointer of shared_ptr
 * @tparam T
 */
template< typename T >
struct custom_deleter
{
    void operator ()( T const * p)
    {
        delete[] p;
    }
};


/**
 * GTUVector class, which is extended for iterable class
 * @tparam T
 */
template <typename T>
class GTUVector: public Iterable<T> {
private:
    shared_ptr<T> container; //shared_ptr container
    int lastIndex; //Integer value of lastIndex that shows the place for new elements
    int capacity; //capacity of array, which is kept in shared_ptr

public:
    GTUVector<T>(); //Default Constructor

    explicit GTUVector<T>(const T& singleElement); //Constructor with single T element

    GTUVector<T>(GTUVector<T> &&rhs); //Move constructor of GTUVector class

    void resize(); //Resize function to increase capacity of array of shared_ptr

    int findIndex(const T& element); //This function returns index of given T element in array of shared_ptr

    void push_back(const T& newElement); //This function adds new element at the end of array of shared_ptr

    T& pop_back(); //This function pops the last element of array of shared_ptr

    bool empty() const override; //This function returns true if there is no element in the array of shared_ptr

    int size() const override; //Returns number of element in the array of shared_ptr

    void erase(GTUIterator<T> iter) override; //erases the element of given iterator

    void erase(GTUIteratorConst<T> constIter) override; //erases the element of given constant iterator

    void clear() override; //Creates a new shared_ptr and saves into container data member

    GTUIterator<T> begin() override; //Returns a iterator to beginning

    GTUIterator<T> end() override; //Returns iterator to end

    const GTUIteratorConst<T> cbegin() const override; //Returns a constant iterator to beginning

    const GTUIteratorConst<T> cend() const override; //Returnsa constant iterator to end

    T& operator[](int index); //Returns the element of array of shared_ptr by using given index

    GTUVector<T>& operator=(GTUVector<T> &&rhs); //Move assingment operator


};

template<typename T>
GTUVector<T>::GTUVector(const T& singleElement) {
    this->lastIndex=0;
    this->capacity=10;
    shared_ptr<T> temp(new T[capacity],custom_deleter<T>());
    T* tempPtr=temp.get();
    tempPtr[lastIndex]=singleElement;
    lastIndex++;
    this->container=temp;
}

/**
 * Move constructor steals data members of given class
 * @tparam T
 * @param rhs
 */
    template<typename T>
    GTUVector<T>::GTUVector(GTUVector<T> &&rhs) {
        container=rhs.container;
        T* ptr=rhs.container.get();
        ptr=nullptr;
    }

template<typename T>
GTUVector<T>::GTUVector() {
    this->lastIndex=0;
    this->capacity=10;
    shared_ptr<T> temp(new T[capacity],custom_deleter<T>());
    this->container=temp;
}

template<typename T>
void GTUVector<T>::resize() {
    capacity*=2;
    shared_ptr<T> newContainer(new T[capacity],custom_deleter<T>());

    T* oldArray=this->container.get();
    T* newArray=newContainer.get();

    for(int i=0; i<lastIndex;i++)
        newArray[i]=oldArray[i];

    this->container=newContainer;


}


template<typename T>
int GTUVector<T>::findIndex(const T& element) {
    T* classArray=container.get();
    for(int i=0;i<lastIndex;i++){
        if(classArray[i]==element)
            return i;
    }
    return -1;
}



template<typename T>
void GTUVector<T>::push_back(const T& newElement) {
    if(lastIndex==capacity)
        resize();
    T* classArray=this->container.get();
    classArray[lastIndex]=newElement;
    lastIndex++;
}


template<typename T>
T& GTUVector<T>::pop_back() {
    //cout<<"Last Index:"<<lastIndex<<endl;
    try{
        T* classPtr=this->container.get();
        classPtr=classPtr+(lastIndex-1);
        cout<<"last element: "<<*classPtr<<endl;
        lastIndex--;
        return *classPtr;
    }
    catch (exception& e)
    {
        cout << "No element exception!" << e.what() << endl;
    }

}



template<typename T>
bool GTUVector<T>::empty() const {
    return this->lastIndex==0;
}

template<typename T>
int GTUVector<T>::size() const {
    return this->lastIndex;
}


/**
 * This method creates a new shared_ptr which does not contain the element of given iterator
 * Then it moves this created shared_ptr to container(data member of this class)
 * @tparam T
 * @param iter
 */
template<typename T>
void GTUVector<T>::erase(GTUIterator<T> iter) {
    T tempElement=*iter;
    int index=findIndex(tempElement);
    if(index!=-1){
        shared_ptr<T> newContainer(new T[capacity],custom_deleter<T>());
        T* newArray=newContainer.get();
        T* oldArray=this->container.get();
        int tempIndex=0;
        while(tempIndex!=index){
            newArray[tempIndex]=oldArray[tempIndex];
            tempIndex++;
        }

        while(tempIndex+1<lastIndex){
            newArray[tempIndex]=oldArray[tempIndex+1];
            tempIndex++;
        }

        this->container=newContainer;
        lastIndex--;
        cout<<tempElement<<" has erased from the vector"<<endl;
    }
    else{
        cout<<"Element: "<<*iter<<" does not exist in this vector!"<<endl;
    }
}

/**
 * This method creates a new shared_ptr which does not contain the element of given iterator
 * Then it moves this created shared_ptr to container(data member of this class)
 * @tparam T
 * @param iter
 */
template<typename T>
void GTUVector<T>::erase(GTUIteratorConst<T> constIter) {
    T tempElement=*constIter;
    int index=findIndex(tempElement);
    if(index!=-1){
        shared_ptr<T> newContainer(new T[capacity],custom_deleter<T>());
        T* newArray=newContainer.get();
        T* oldArray=this->container.get();
        int tempIndex=0;
        while(tempIndex!=index){
            newArray[tempIndex]=oldArray[tempIndex];
            tempIndex++;
        }

        while(tempIndex+1<lastIndex){
            newArray[tempIndex]=oldArray[tempIndex+1];
            tempIndex++;
        }

        container=newContainer;
        lastIndex--;
        cout<<tempElement<<" has erased from the vector"<<endl;
    }
    else{
        cout<<"Element: "<<*constIter<<" does not exist in this vector!"<<endl;
    }

}

template<typename T>
void GTUVector<T>::clear() {
    shared_ptr<T> newContainer(new T[capacity],custom_deleter<T>());
    this->container=newContainer;
    this->lastIndex=0;
}


template<typename T>
GTUIterator<T> GTUVector<T>::begin() {
   GTUIterator<T> tempIter(container.get());
   return tempIter;
}

//template<typename T>
//GTUIterator<T> GTUVector<T>::end() {
//    GTUIterator<T> tempIter(&container.get()[lastIndex-1]);
//    return tempIter;
//}

template<typename T>
GTUIterator<T> GTUVector<T>::end() {
    T* ptr=container.get();
    ptr=ptr+lastIndex;
    GTUIterator<T> tempIter(ptr);
    return tempIter;

}

template<typename T>
const GTUIteratorConst<T> GTUVector<T>::cbegin() const {
    GTUIteratorConst<T> tempConstIter(container.get());
    return tempConstIter;
}

template<typename T>
const GTUIteratorConst<T> GTUVector<T>::cend() const {
    GTUIteratorConst<T> tempConstIter(&container.get()[lastIndex-1]);
    return tempConstIter;
}

template<typename T>
T &GTUVector<T>::operator[](int index) {
    try{
        T* classPtr=this->container.get();
//        classPtr=classPtr+(index);
//        cout<<"Indexed element "<<*classPtr<<endl;
        return classPtr[index];
    }
    catch (exception& e)
    {
        cout << "Invalid Index Exception!" << e.what() << endl;
    }
}

    template<typename T>
    GTUVector<T> &GTUVector<T>::operator=(GTUVector<T> &&rhs) {
        if(this==&rhs)
            return *this;
        container=rhs.container;
        T* othersPtr=rhs.container.get();
        othersPtr=nullptr;
        return *this;
    }


}
#endif //CSE241_HW6_GTUVECTOR_H
