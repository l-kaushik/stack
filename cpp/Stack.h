#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <typename T>
class Stack
{
private:
    Node<T> *m_top{nullptr};

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
    Stack<T>& operator=(const Stack<T> &other);
};

//< -------------------- METHOD DEFINITION -------------------->

// constructor and destructor
template <typename T>
Stack<T>::Stack() : m_top(nullptr) {}

template <typename T>
Stack<T>::Stack(T value) : m_top(new Node<T>(value)) {}

template <typename T>
Stack<T>::Stack(Stack<T> &other)
{
    *this = other;
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
        temp->setNextNode(m_top);
        m_top = temp;
    }
    else
        m_top = new Node<T>(value);
}

template <typename T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        std::cout<<"Stack is already empty\n";
    }
    else{
        Node<T> *temp = m_top;
        m_top = m_top->getNextNode();
        temp->setNextNode(nullptr);
        delete temp;
    }
}

template <typename T>
void Stack<T>::peek() { std::cout << m_top->getValue(); }

template <typename T>
bool Stack<T>::isEmpty() { return m_top == nullptr; }

//operator overloading
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T> &other)
{
    if(this == &other)
        return *this;

    delete m_top;
    m_top = nullptr;

    Node<T> *temp {other.m_top};
    Node<T> *setNewNode {nullptr};

    while(temp)
    {
        if(m_top == nullptr)
        {
            m_top = new Node(temp->getValue());
            setNewNode = m_top;
        }
        else
        {
            Node<T> *newNode {new Node(temp->getValue())};
            setNewNode->setNextNode(newNode);
            setNewNode = newNode;
        }

        temp = temp->getNextNode();   
    }

    return *this;
}

#endif