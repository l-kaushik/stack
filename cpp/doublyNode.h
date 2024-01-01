#ifndef NODE_H
#define NODE_H

/*
Implementaion of doubly node, having Previous and Next pointer
*/

#include <iostream>

template <typename T>
class Node
{
private:
    T m_value{};
    Node<T> *m_prev{nullptr};
    Node<T> *m_next{nullptr};

public:
    // constructors and destructors
    Node();
    Node(T value);
    Node(Node<T> *prev, T value);   //point to the same object
    Node(Node<T> &prev, T value);   //Point to new object
    Node(T value, Node<T> *next);   //point to the same object
    Node(T value, Node<T> &next);   //Point to new object
    Node(Node<T> *prev, T value, Node<T> *next);

    // copy contructor, copy assignment operator and destructor
    Node(const Node<T> &other);
    Node<T> &operator=(const Node<T> &other);
    ~Node();

    // Getters
    T getValue() const;
    Node<T> *getNextNode() const;
    Node<T> *getPrevNode() const;

    // Setters
    void setValue(T value);
    void setNextNode(Node<T> *next);
    void setPrevNode(Node<T> *prev);

    // Functions
    void display() const;
};

//<--------- METHOD DEFINITIONS --------->

// constructors and destructors
template <typename T>
Node<T>::Node() : m_value(), m_prev(nullptr), m_next(nullptr) {}

template <typename T>
Node<T>::Node(T value) : m_value(value) {}

template <typename T>
Node<T>::Node(T value, Node<T> *next)
    : m_value(value), m_next(next) {}

template <typename T>
Node<T>::Node(T value, Node<T> &next)
    : m_value(value), m_next(new Node(next)) {}

template <typename T>
Node<T>::Node(Node<T> *prev, T value)
    : m_value(value), m_prev(prev) {}

template <typename T>
Node<T>::Node(Node<T> &prev, T value)
    : m_value(value), m_prev(new Node(prev)) {}

template <typename T>
Node<T>::Node(Node<T> *prev, T value, Node<T> *next)
    : m_prev(prev), m_value(value), m_next(next) {}

// copy contructor, copy assignment operator and destructor
template <typename T>
Node<T>::Node(const Node<T> &other)
    : m_value(other.m_value), m_prev(other.m_prev), m_next(other.m_next)
{
}

template <typename T>
Node<T> &Node<T>::operator=(const Node<T> &other)
{
    this->m_value = other.m_value;

    delete m_prev;
    m_prev = nullptr;
    if (other.m_prev)
        this->m_prev = new Node<T>(*other.m_prev);
    delete m_next;

    m_next = nullptr;
    if (other.m_next)
        this->m_next = new Node<T>(*other.m_next);

    return *this;
}

template <typename T>
Node<T>::~Node()
{
}

// Getters
template <typename T>
T Node<T>::getValue() const
{
    return m_value;
}
template <typename T>
Node<T> *Node<T>::getNextNode() const
{
    return m_next;
}

template <typename T>
Node<T> *Node<T>::getPrevNode() const
{
    return m_prev;
}

// Setters
template <typename T>
void Node<T>::setValue(T value)
{
    m_value = value;
}

template <typename T>
void Node<T>::setNextNode(Node<T> *next)
{
    m_next = next;
    next->m_prev = this;
}

template <typename T>
void Node<T>::setPrevNode(Node<T> *prev)
{
    m_prev = prev;
    prev->m_next = this;
}

// Functions
template <typename T>
void Node<T>::display() const
{
    std::cout << "Value: " << m_value << '\n';
}

#endif