//
// Created by darkb on 25.12.2021.
//

#ifndef CSE241_HW6_ITERABLE_H
#define CSE241_HW6_ITERABLE_H

#include <iostream>

#include "GTUIterator.h"

#include "GTUIteratorConst.h"

using namespace  std;

/**
 * Base iterable class
 * @tparam T is typename
 */
template <typename T>
class Iterable {
protected:
    virtual bool empty() const =0; //return true if the container is empty

    virtual int size() const =0; //Returns lastIndex of container

    virtual void erase(GTUIterator<T> iter)=0; //Erase element pointed by the given iterator

    virtual void erase(GTUIteratorConst<T> constIter)=0; //Erase element pointed by the given constant iterator

    virtual void clear()=0; //Clears all content

    virtual GTUIterator<T> begin()=0; //Returns a iterator to beginning

    virtual GTUIterator<T> end()=0; //Returns iterator to end

    virtual const GTUIteratorConst<T> cbegin() const=0; //Returns a constant iterator to beginning

    virtual const GTUIteratorConst<T> cend() const=0; //Returns a constant iterator to end


};


#endif //CSE241_HW6_ITERABLE_H
