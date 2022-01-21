//
// Created by darkb on 25.12.2021.
//

#ifndef CSE241_HW6_GTUSET_H
#define CSE241_HW6_GTUSET_H

#include <iostream>
#include "Iterable.h"
#include "GTUVector.h"
#include "GTUIteratorConst.h"
#include <memory>

using namespace  std;


namespace baris2{

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

template< typename T >
class GTUSet: public Iterable<T>{
private:
    shared_ptr<T> container; //shared_ptr container
    int lastIndex; //Integer value of lastIndex that shows the place for new elements
    int capacity; //capacity of array, which is kept in shared_ptr

public:
    GTUSet(); //Default Constructor

    explicit GTUSet(const T& singleElement); //Constructor with single T element

    GTUSet(GTUSet<T> &&rhs); //Move constructor of GTUVector class

    void resize(); //Resize function to increase capacity of array of shared_ptr

    int findIndex(const T& element); //This function returns index of given T element in array of shared_ptr

    void add(const T& newElement); //This function adds new element at the end of array of shared_ptr

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

    GTUSet<T>& operator=(GTUSet<T> &&rhs); //Move assingment operator



};

    template<typename T>
    GTUSet<T>::GTUSet() {
        this->lastIndex=0;
        this->capacity=10;
        shared_ptr<T> temp(new T[capacity],custom_deleter<T>());
        this->container=temp;
    }

    template<typename T>
    GTUSet<T>::GTUSet(const T &singleElement) {
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
    GTUSet<T>::GTUSet(GTUSet<T> &&rhs) {
        container=rhs.container;
        T* othersPtr=rhs.container.get();
        othersPtr= nullptr;

    }

    template<typename T>
    void GTUSet<T>::resize() {
        capacity*=2;
        shared_ptr<T> newContainer(new T[capacity],custom_deleter<T>());

        T* oldArray=this->container.get();
        T* newArray=newContainer.get();

        for(int i=0; i<lastIndex;i++)
            newArray[i]=oldArray[i];

        this->container=newContainer;
    }

    template<typename T>
    int GTUSet<T>::findIndex(const T &element) {
        T* classArray=container.get();
        for(int i=0;i<lastIndex;i++){
            if(classArray[i]==element)
                return i;
        }
        return -1;
    }

    template<typename T>
    void GTUSet<T>::add(const T &newElement) {
        int index= findIndex(newElement);
        if(index==-1){
            if(lastIndex==capacity)
                resize();
            T* classArray=this->container.get();
            classArray[lastIndex]=newElement;
            lastIndex++;
        }
        else
            cout<<newElement<<" is already element of the set. You can't add duplicate element!"<<endl;
    }

    template<typename T>
    bool GTUSet<T>::empty() const {
        return this->lastIndex==0;
    }

    template<typename T>
    int GTUSet<T>::size() const {
        return this->lastIndex;
    }

    /**
 * This method creates a new shared_ptr which does not contain the element of given iterator
 * Then it moves this created shared_ptr to container(data member of this class)
 * @tparam T
 * @param iter
 */
    template<typename T>
    void GTUSet<T>::erase(GTUIterator<T> iter) {
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
            cout<<tempElement<<" has erased from the set"<<endl;
        }
        else{
            cout<<"Element: "<<*iter<<" does not exist in this set!"<<endl;
        }
    }

    /**
 * This method creates a new shared_ptr which does not contain the element of given iterator
 * Then it moves this created shared_ptr to container(data member of this class)
 * @tparam T
 * @param iter
 */
    template<typename T>
    void GTUSet<T>::erase(GTUIteratorConst<T> constIter) {
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
            cout<<tempElement<<" has erased from the set"<<endl;
        }
        else{
            cout<<"Element: "<<*constIter<<" does not exist in this set!"<<endl;
        }
    }

    template<typename T>
    void GTUSet<T>::clear() {
        shared_ptr<T> newContainer(new T[capacity],custom_deleter<T>());
        this->container=newContainer;
        this->lastIndex=0;
    }

    template<typename T>
    GTUIterator<T> GTUSet<T>::begin() {
        GTUIterator<T> tempIter(container.get());
        return tempIter;
    }

    template<typename T>
    GTUIterator<T> GTUSet<T>::end() {
        GTUIterator<T> tempIter(&container.get()[lastIndex-1]);
        return tempIter;
    }

    template<typename T>
    const GTUIteratorConst<T> GTUSet<T>::cbegin() const {
        GTUIteratorConst<T> tempConstIter(container.get());
        return tempConstIter;
    }

    template<typename T>
    const GTUIteratorConst<T> GTUSet<T>::cend() const {
        GTUIteratorConst<T> tempConstIter(&container.get()[lastIndex-1]);
        return tempConstIter;
    }

    template<typename T>
    T &GTUSet<T>::operator[](int index) {
        try{
            T* classPtr=this->container.get();
            return classPtr[index];
        }
        catch (exception& e)
        {
            cout << "Invalid Index Exception!\n" << e.what() << endl;
        }
    }

    template<typename T>
    GTUSet<T> &GTUSet<T>::operator=(GTUSet<T> &&rhs) {
        if(this==&rhs)
            return *this;
        container=rhs.container;
        T* othersPtr=rhs.container.get();
        othersPtr= nullptr;
        return *this;
    }


}


#endif //CSE241_HW6_GTUSET_H
