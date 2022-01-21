//
// Created by darkb on 25.12.2021.
//

#ifndef CSE241_HW6_GTUITERATORCONST_H
#define CSE241_HW6_GTUITERATORCONST_H

#include <iostream>

using namespace  std;

/**
 * Constant iterator class
 * @tparam T
 */
template <typename T>
class GTUIteratorConst {

private:
    const T* my_ptr; //Const pointer container

public:

    explicit GTUIteratorConst<T>(const T* myPtr); //Constructor with one given element

    GTUIteratorConst<T>(){ //Default constructor
        this->my_ptr= nullptr;
    }


    const T& operator*() const; //*operator
    T& operator->() const; //-> operator
    GTUIteratorConst<T> & operator++(); //increment operator
    GTUIteratorConst<T>& operator--(); //decrement operator
    bool operator==(GTUIteratorConst<T> rhs); //boolean == operator
    bool operator!=(GTUIteratorConst<T> rhs); //boolean != operator
    GTUIteratorConst<T>& operator=(const GTUIteratorConst<T> &rhs); //equalirty = operator

};


/**
 * It returns the raw pointer value of the class
 * @tparam T
 * @return
 */
template<typename T>
const T &GTUIteratorConst<T>::operator*() const {
    return *my_ptr;
}

/**
 * It returns the raw pointer of the class
 * @tparam T
 * @return
 */
template<typename T>
T &GTUIteratorConst<T>::operator->() const {
    return my_ptr;
}

/**
 * Increment operator increments address of raw pointer
 * @tparam T
 * @return
 */
template<typename T>
GTUIteratorConst<T> & GTUIteratorConst<T>::operator++() {
    my_ptr= my_ptr+1;
    return *this;
}


/**
 *
 * Decrement operator decrements the address of the raw pointer
 * @tparam T
 * @return
 */
template<typename T>
GTUIteratorConst<T> &GTUIteratorConst<T>::operator--() {
    my_ptr= my_ptr-1;
    return *this;
}

/**
 * Equality operator returns true if both iterators show the same element in the RAM
 * @tparam T
 * @param rhs
 * @return
 */
template<typename T>
bool GTUIteratorConst<T>::operator==(GTUIteratorConst<T> rhs) {
    return my_ptr==rhs.my_ptr;
}

/**
 * Inequality operator returns true if iterators show different elements in the RAM
 * @tparam T
 * @param rhs
 * @return
 */
template<typename T>
bool GTUIteratorConst<T>::operator!=(GTUIteratorConst<T> rhs) {
    return my_ptr!=rhs.my_ptr;
}

/**
 * Constructor that takes a raw pointer of T value
 * @tparam T
 * @param myPtr
 */
template<typename T>
GTUIteratorConst<T>::GTUIteratorConst(const T* myPtr) {
    this->my_ptr=myPtr;
}

/**
 * Copy assignment operator that copies the pointer of given GTUIteratorConst class
 * @tparam T
 * @param rhs
 * @return
 */
template<typename T>
GTUIteratorConst<T> &GTUIteratorConst<T>::operator=(const GTUIteratorConst<T> &rhs) {
    this->my_ptr=rhs.my_ptr;
    return *this;
}




#endif //CSE241_HW6_GTUITERATORCONST_H
