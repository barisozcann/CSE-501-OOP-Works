//
// Created by darkb on 25.12.2021.
//

#ifndef CSE241_HW6_GTUITERATOR_H
#define CSE241_HW6_GTUITERATOR_H

#include <iostream>



using namespace  std;
/**
 * This class is nearly the same as GTUIteratorConst class
 * There are only two diffences
 * 1-In this class raw pointer is not const
 * 2- in *operator you are able to change value that is addressed by pointer
 * @tparam T
 */
template <typename T>
class GTUIterator {
private:
    T* my_ptr;
public:

    //typedef iterator self_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef int difference_type;

    GTUIterator();
    explicit GTUIterator(T *myPtr);




    T& operator*();
    T& operator->();
    GTUIterator<T>& operator++();
    GTUIterator<T>& operator--();
    bool operator==(const GTUIterator<T> &rhs);
    bool operator!=(const GTUIterator<T> &rhs);
    GTUIterator<T>& operator=(const GTUIterator<T> &rhs);





};


template<typename T>
GTUIterator<T>::GTUIterator(T* myPtr) {
    this->my_ptr=myPtr;
}

template<typename T>
GTUIterator<T>::GTUIterator() {
    my_ptr= nullptr;
}

template<typename T>
T &GTUIterator<T>::operator*() {
    return *my_ptr;
}

template<typename T>
T &GTUIterator<T>::operator->() {
    return my_ptr;
}

template<typename T>
GTUIterator<T> &GTUIterator<T>::operator++(){
    my_ptr= my_ptr+1;
    return *this;
}


template<typename T>
GTUIterator<T> &GTUIterator<T>::operator--() {
    my_ptr=my_ptr-1;
    return *this;
}



template<typename T>
GTUIterator<T> &GTUIterator<T>::operator=(const GTUIterator<T> &rhs) {
    this->my_ptr=rhs.my_ptr;
    return *this;
}



template<typename T>
bool GTUIterator<T>::operator==(const GTUIterator<T> &rhs) {
    return my_ptr==rhs.my_ptr;
}

template<typename T>
bool GTUIterator<T>::operator!=(const GTUIterator<T> &rhs) {
    return !(*this==rhs);
}




#endif //CSE241_HW6_GTUITERATOR_H
