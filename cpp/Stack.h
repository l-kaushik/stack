#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <typename T>
class Stack
{
private:
    Node<T> *top{nullptr};

public:
    //constructor and destructor
    Stack();
    Stack(T value);
    Stack(std::initializer_list<T> list);

    //Functions
    void push(T value);
    void pop();
    void peek();

    //Operator overloading
    Stack& operator=(Stack& other);

};

//< -------------------- METHOD DEFINITION -------------------->

#endif