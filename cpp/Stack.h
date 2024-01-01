#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <typename T>
class Stack
{
private:
    Node<T> *top{nullptr};

public:
    // constructor and destructor
    Stack();
    Stack(T value);
    Stack(std::initializer_list<T> list);

    // Functions
    void push(T value);
    void pop();
    void peek();
    bool isEmpty();

    // Operator overloading
    Stack &operator=(Stack &other);
};

//< -------------------- METHOD DEFINITION -------------------->

// constructor and destructor
template <typename T>
Stack<T>::Stack() : top(nullptr) {}

template <typename T>
Stack<T>::Stack(T value) : top(new Node<T>(value)) {}

// Functions
template <typename T>
void Stack<T>::push(T value)
{
    if (!isEmpty())
    {
        Node<T> *temp = new Node<T>(value);
        temp->setNextNode(top);
        top = temp;
    }
    else
        top = new Node<T>(value);
}

template <typename T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        std::cout<<"Stack is already empty\n";
    }
    else{
        Node<T> *temp = top;
        top = top->getNextNode();
        delete temp;
    }
}

template <typename T>
void Stack<T>::peek() { std::cout << top->getValue(); }

template <typename T>
bool Stack<T>::isEmpty() { return top == nullptr; }
#endif