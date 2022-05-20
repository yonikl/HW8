//
// Created by yehud on 20/05/2022.
//

#ifndef HW8_STACKVECTOR_H
#define HW8_STACKVECTOR_H



#include "Vector.h"
//-------------------------------------------------------
//  class StackVector
//  Stack implemented using Vector
//  Vector will grow as necessary to avoid overflow
//-------------------------------------------------------

template <class T>
class StackVector
{
public:
    // constructor requires a starting size
    StackVector(unsigned int capacity);
    StackVector(const StackVector& s);


    // Stack operations
    void clear() ;
    bool isEmpty() const ;
    T pop() ;
    void push(int value) ;
    T top() /*cont*/ ;

protected:
    // data fields
    Vector<T> data;
};


//-------------------------------------------------------
//  class StackVector implementation
//-------------------------------------------------------
template <class T>
StackVector<T>::StackVector(unsigned int capacity) : data(capacity)
{
    // create and initialize a Stack based on Vectors
}

template <class T>
StackVector<T>::StackVector(const StackVector& s) : data(s.data)
{ /* copy constructor*/}

template <class T>
void StackVector<T>::clear()
{
    // clear all elements from Stack, by setting
    // index to bottom of Stack
    data.clear();
}

template <class T>
bool StackVector<T>::isEmpty() const
{
    return data.getSize() == 0;
}

template <class T>
T StackVector<T>::pop()
{
    // return and remove the topmost element in the Stack
    if(isEmpty()) throw "Stack is empty";
    return data.delLast();
}

template <class T>
void StackVector<T>::push(int val)
{
    // push new value onto Stack
    data.insert(val);
}

template <class T>
T StackVector<T>::top() //const
{
    // return the intopmost element in the Stack
    if(isEmpty()) throw "Stack is empty";
    return data[data.getSize() - 1];
}


#endif //HW8_STACKVECTOR_H
