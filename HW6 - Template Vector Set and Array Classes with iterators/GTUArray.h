//
// Created by darkb on 25.12.2021.
//

#ifndef CSE241_HW6_GTUARRAY_H
#define CSE241_HW6_GTUARRAY_H

#include <iostream>
#include "Iterable.h"
#include "GTUVector.h"
#include "GTUIteratorConst.h"
#include <memory>
using namespace  std;



namespace baris3{


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


template< typename T,size_t SIZE> //SIZE declares the size of array of shared_ptr. It can't be changed after it declared.
class GTUArray: public Iterable<T>{
private:
    shared_ptr<T> container; //shared_ptr container
    int lastIndex; //Integer value of lastIndex that shows the place for new elements
public:
    GTUArray(); //Default Constructor

    explicit GTUArray(const T& singleElement); //Constructor with single T element

    GTUArray(GTUArray<T,SIZE> &&rhs); //Move constructor of GTUVector class

    int findIndex(const T& element); //This function returns index of given T element in array of shared_ptr

    void add(const T& newElement);  //This function adds new element at the end of array of shared_ptr

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

    GTUArray<T,SIZE>& operator=(GTUArray<T,SIZE> &&rhs); //Move assingment operator



};

template<typename T, size_t SIZE>
GTUArray<T, SIZE>::GTUArray() {
    this->lastIndex=0;
    shared_ptr<T> temp(new T[SIZE+1],custom_deleter<T>());
    this->container=temp;

}

template<typename T, size_t SIZE>
GTUArray<T, SIZE>::GTUArray(const T &singleElement) {
    this->lastIndex=0;
    shared_ptr<T> temp(new T[SIZE+1],custom_deleter<T>());
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
template<typename T, size_t SIZE>
GTUArray<T, SIZE>::GTUArray(GTUArray<T, SIZE> &&rhs) {
    container=rhs.container;
    T* othersPtr=rhs.container.get();
    othersPtr= nullptr;
}

template<typename T, size_t SIZE>
int GTUArray<T, SIZE>::findIndex(const T &element) {
    T* classArray=container.get();
    for(int i=0;i<lastIndex;i++){
        if(classArray[i]==element)
            return i;
    }
    return -1;
}

template<typename T, size_t SIZE>
void GTUArray<T, SIZE>::add(const T &newElement) {
    if(lastIndex==SIZE+1)
        cout<<"Array  full you can't add any new element ot it!"<<endl;
    else{
        T* classArray=this->container.get();
        classArray[lastIndex]=newElement;
        lastIndex++;
    }
}

template<typename T, size_t SIZE>
bool GTUArray<T, SIZE>::empty() const {
    return this->lastIndex==0;
}

template<typename T, size_t SIZE>
int GTUArray<T, SIZE>::size() const {
    return this->lastIndex;
}

/**
 * This method creates a new shared_ptr which does not contain the element of given iterator
 * Then it moves this created shared_ptr to container(data member of this class)
 * @tparam T
 * @param iter
 */
template<typename T, size_t SIZE>
void GTUArray<T, SIZE>::erase(GTUIterator<T> iter) {
    T tempElement=*iter;
    int index=findIndex(tempElement);
    if(index!=-1){
        shared_ptr<T> newContainer(new T[SIZE],custom_deleter<T>());
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
        cout<<tempElement<<" has erased from the array"<<endl;
    }
    else{
        cout<<"Element: "<<*iter<<" does not exist in this array!"<<endl;
    }

}

/**
 * This method creates a new shared_ptr which does not contain the element of given iterator
 * Then it moves this created shared_ptr to container(data member of this class)
 * @tparam T
 * @param iter
 */
template<typename T, size_t SIZE>
void GTUArray<T, SIZE>::erase(GTUIteratorConst<T> constIter) {
    T tempElement=*constIter;
    int index=findIndex(tempElement);
    if(index!=-1){
        shared_ptr<T> newContainer(new T[SIZE],custom_deleter<T>());
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
        cout<<tempElement<<" has erased from the array"<<endl;
    }
    else{
        cout<<"Element: "<<*constIter<<" does not exist in this vector!"<<endl;
    }

}

template<typename T, size_t SIZE>
void GTUArray<T, SIZE>::clear() {
    shared_ptr<T> newContainer(new T[SIZE],custom_deleter<T>());
    this->container=newContainer;
    this->lastIndex=0;

}

template<typename T, size_t SIZE>
GTUIterator<T> GTUArray<T, SIZE>::begin() {
    GTUIterator<T> tempIter(container.get());
    return tempIter;
}

template<typename T, size_t SIZE>
GTUIterator<T> GTUArray<T, SIZE>::end() {
    GTUIterator<T> tempIter(&container.get()[lastIndex-1]);
    return tempIter;
}

template<typename T, size_t SIZE>
const GTUIteratorConst<T> GTUArray<T, SIZE>::cbegin() const {
    GTUIteratorConst<T> tempConstIter(container.get());
    return tempConstIter;
}

template<typename T, size_t SIZE>
const GTUIteratorConst<T> GTUArray<T, SIZE>::cend() const {
    GTUIteratorConst<T> tempConstIter(&container.get()[lastIndex-1]);
    return tempConstIter;
}

template<typename T, size_t SIZE>
T &GTUArray<T, SIZE>::operator[](int index) {
    try{
        T* classPtr=this->container.get();
        return classPtr[index];
    }
    catch (exception& e)
    {
        cout << "Invalid Index Exception!\n" << e.what() << endl;
    }
}


    template<typename T, size_t SIZE>
    GTUArray<T, SIZE> &GTUArray<T, SIZE>::operator=(GTUArray<T, SIZE> &&rhs) {
        if(this==&rhs)
            return *this;
        container=rhs.container;
        T* othersPtr=rhs.container.get();
        othersPtr= nullptr;
        return *this;
    }


}
#endif //CSE241_HW6_GTUARRAY_H
