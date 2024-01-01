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
    Stack(Stack &other);
    Stack(std::initializer_list<T> list);
    ~Stack();

    // Functions
    void push(T value);
    void pop();
    void peek();
    bool isEmpty();

    // Operator overloading
    Stack<T>& operator=(Stack<T> &other);
};

//< -------------------- METHOD DEFINITION -------------------->

// constructor and destructor
template <typename T>
Stack<T>::Stack() : top(nullptr) {}

template <typename T>
Stack<T>::Stack(T value) : top(new Node<T>(value)) {}

template <typename T>
Stack<T>::Stack(Stack &other)
{
    top = other;
}

template <typename T>
Stack<T>::Stack(std::initializer_list<T> list)
{
    for(auto &value: list)
    {
        push(value);
    }
}

template <typename T>
Stack<T>::~Stack()
{
    while(!isEmpty())
        pop();
}

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

//operator overloading
template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T> &other)
{
    delete top;
    top = nullptr;

    while(!other.isEmpty())
    {
        push(other.top->getValue());
        other = other.top->getNextNode();       
    }

    return *this;
}

#endif